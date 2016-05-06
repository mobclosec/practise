#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <sys/sendfile.h>
#include <stdint.h>
#include <errno.h>

#include "config.h"
#include "types.h"
#include "debug.h"
#include "alloc-inl.h"

#ifndef SIMPLE_FILES
#  define CASE_PREFIX "id:"
#else
#  define CASE_PREFIX "id_"
#endif

static u8 *in_dir, *out_dir;


static u32 get_min_accept(u8* dir_name) {

    u32 min_accept = 0;
    struct dirent* sd_ent;
    DIR* sd = opendir(out_dir);
    if (!sd) PFATAL("Unable to open '%s'", out_dir);

    while ((sd_ent = readdir(sd))) {
        u32 new_fuzzer = 1;
        u8 *qd_synced_path = alloc_printf("%s/%s/.synced/%s", out_dir, sd_ent->d_name, dir_name);
        s32 id_fd = open(qd_synced_path, O_RDWR, 0600);

        if (id_fd < 0) {
            ck_free(qd_synced_path);
            continue;
        }

        if (read(id_fd, &min_accept, sizeof(u32)) > 0) {
            new_fuzzer = 0;
        }

        close(id_fd);
        ck_free(qd_synced_path);

        if (new_fuzzer == 0) break;
    }

    return min_accept;
}

static void create_sync_dir(u8* dir_name) {

    struct stat st;
    u8* path = alloc_printf("%s/%s", out_dir, dir_name);

    if (stat(path, &st) != 0) {
        if (mkdir(path, 0700) && errno != EEXIST)
            PFATAL("Unable to create '%s'", path);
    }
    ck_free(path);

    path = alloc_printf("%s/%s/queue", out_dir, dir_name);

    if (stat(path, &st) != 0) {
        if (mkdir(path, 0700) && errno != EEXIST)
            PFATAL("Unable to create '%s'", path);
    }
    ck_free(path);
}

static void write_to_testcase(void* mem, u32 len, u8* dir_name, u8* file_name) {

    u8* file_path = alloc_printf("%s/%s/queue/%s", out_dir, dir_name, file_name);
    s32 fd = open(file_path, O_WRONLY | O_CREAT | O_EXCL | S_IRUSR | S_IWUSR, 0600);

    if (fd < 0) {
        if (errno != EEXIST) PFATAL("Unable to create '%s'", file_name);
    } else {
        ck_write(fd, mem, len, file_path);
    }

    ck_free(file_path);
    close(fd);
}

static void sync_asan_fuzzers() {

    struct dirent* sd_ent;
    DIR* sd = opendir(in_dir);
    if (!sd) PFATAL("Unable to open '%s'", in_dir);

    while ((sd_ent = readdir(sd))) {

        DIR* qd;
        u8 *qd_path;
        u32 min_accept = 0;

        if (sd_ent->d_name[0] == '.') continue;

        qd_path = alloc_printf("%s/%s/queue", in_dir, sd_ent->d_name);

        if (!(qd = opendir(qd_path))) {
            ck_free(qd_path);
            continue;
        }

        min_accept = get_min_accept(sd_ent->d_name);
        OKF("min_accept %d", min_accept);
        create_sync_dir(sd_ent->d_name);

        struct dirent* qd_ent;
        while ((qd_ent = readdir(qd))) {

            u8* path;
            s32 fd;
            struct stat st;
            u32 syncing_case;

            if (qd_ent->d_name[0] == '.' ||
                sscanf(qd_ent->d_name, CASE_PREFIX "%06u", &syncing_case) != 1 ||
                syncing_case < min_accept) continue;

            path = alloc_printf("%s/%s", qd_path, qd_ent->d_name);
            fd = open(path, O_RDONLY);

            if (fd < 0) PFATAL("Unable to open '%s'", path);
            if (fstat(fd, &st)) PFATAL("fstat() failed");

            if (st.st_size && st.st_size <= MAX_FILE) {

                u8* mem = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
                if (mem == MAP_FAILED) PFATAL("Unable to mmap '%s'", path);
                write_to_testcase(mem, st.st_size, sd_ent->d_name, qd_ent->d_name);
                munmap(mem, st.st_size);
            }

            ck_free(path);
            close(fd);
        }

        closedir(qd);
        ck_free(qd_path);
    }

    closedir(sd);
}

static void usage(u8* argv0) {
    SAYF("\n%s [ options ] \n\n"
       "Required parameters:\n\n"
       "  -i dir        - output directory of non-ASAN\n"
       "  -o dir        - output directory of ASAN\n"
       "  -t time       - synchronization cycle\n\n",
       argv0);

    exit(1);
}

int main(int argc, char** argv) {
    s32 opt;
    u32 timeout = 300;

    while ((opt = getopt(argc, argv, "+i:o:t:")) > 0) {

        switch (opt) {
            case 'i': in_dir = optarg; break;
            case 'o': out_dir = optarg; break;
            case 't': timeout = atoi(optarg); break;
            default: usage(argv[0]);
        }
    }

    if (!in_dir || !out_dir) usage(argv[0]);

    while (1) {
   //     OKF("Starting sync_asan_fuzzers!\n");
        sync_asan_fuzzers();
        sleep(timeout);
    }

    exit(0);
}
