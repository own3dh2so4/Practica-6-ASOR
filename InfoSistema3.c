#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Max argument length: %li\n", sysconf(_SC_ARG_MAX));
	printf("Max number of childs: %li\n", sysconf(_SC_CHILD_MAX));
	printf("Max number of files opened: %li\n", sysconf(_SC_OPEN_MAX));
	//Para mas valores man 3 sysconf
	return 0;
}
