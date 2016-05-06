#include <iostream>
#include <string>

using namespace std;


void c_input()
{
	char str[1000];
	printf("Please input the DNA string: ");
	fgets(str, 1000, stdin);

	printf("\nyou enter: ");
	puts(str);
}

void cc_input()
{
	string in;

	cin >> in;
	cout << in << endl;
}

int main()
{
	c_input();
	return 0;
}