#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <time.h>

using namespace std;


#define errExit(a) {perror(a); exit(-1);}
static char* get_cur_time()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime(timeinfo);
}

static void sigchldHandler(int sig)
{
    cout << "child handler called" << endl;
}

int main(int argc, char *argv[])
{
    int j, sigCnt;
    sigset_t blockMask, emptyMask;
    struct sigaction sa;

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "%s child-sleep-time...\n", argv[0]);
        exit(-1);
    }

    setbuf(stdout, NULL);       /* Disable buffering of stdout */

    sigCnt = 0;
    int numLiveChildren = argc - 1;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigchldHandler;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(-1);
    }

    /* Block SIGCHLD to prevent its delivery if a child terminates
       before the parent commences the sigsuspend() loop below */

    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_SETMASK, &blockMask, NULL) == -1) {
        perror("sigprocmask");
        exit(-1);
    }

    printf("argc is %d\n", argc);

    for (j = 1; j < argc; j++) {
        switch (fork()) {
        case -1:
            errExit("fork");

        case 0:         /* Child - sleeps and then exits */
            sleep(2);
            printf("%s Child %d (PID=%ld) exiting\n", get_cur_time(),
                    j, (long) getpid());
            _exit(EXIT_SUCCESS);

        default:        /* Parent - loops to create next child */
            break;
        }
    }

    /* Parent comes here: wait for SIGCHLD until all children are dead */

    sigemptyset(&emptyMask);
    while (numLiveChildren > 0) {
        if (sigsuspend(&emptyMask) == -1 && errno != EINTR)
            errExit("sigsuspend");

        printf("sigCnt is %d\n", sigCnt);
        sigCnt++;
        numLiveChildren--;
    }

    printf("%s All %d children have terminated; SIGCHLD was caught "
            "%d times\n", get_cur_time(), argc - 1, sigCnt);

    exit(EXIT_SUCCESS);
}
