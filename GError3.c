#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	//Hay que cambiar sys_nerr por que esta deprecated
	for (i = 0; i < sys_nerr; i++)
		printf("Error numero  %i: \n  %s\n", i, strerror(i));
	return 0;
}
