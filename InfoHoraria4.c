#include <sys/time.h>
#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	struct timeval tv;
	int rc = gettimeofday(&tv, NULL);
	
	if (rc == -1) {
		char error_msg[200];
		sprintf(error_msg, "Ocurrio un error y devolvio %i", errno);
		perror(error_msg);
		return -1;
	}

	//Me guardo los microsegundos que estan en la estructura tv
	long start = tv.tv_usec;
	int i;
	for (i = 0; i < 10000; i++);	
	
	//Cojo de nuevo los microsegundos
	rc = gettimeofday(&tv, NULL);
	
	if (rc == -1) {
		char error_msg[200];
		sprintf(error_msg, "Ocurrio un error y devolvio %i", errno);
		perror(error_msg);
		return -1;
	}

	//Me guardo el final.
	long end = tv.tv_usec;

	//Los microsegundos que han pasado son los finales menos lo iniciales.
	printf("Microsegundos transcurridos: %i\n", end - start);

	return 0;
}
