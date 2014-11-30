#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	time_t t;
	time(&t);
	
	if (t == -1) {
		char error_msg[200];
		sprintf(error_msg, "Ocurrio un error y devolvio %i", errno);
		perror(error_msg);
		return -1;
	}

	struct tm *timedata = localtime(&t);

	if (timedata == NULL) {
		char error_msg[200];
		sprintf(error_msg, "Ocurrio un error y devolvio %i", errno);
		perror(error_msg);
		return -1;
	}

	//Como los años transcurridos son desde 1900 (man 3 ctime)
	printf("Estamos en el año %i\n", 1900 + timedata->tm_year);

	return 0;
}
