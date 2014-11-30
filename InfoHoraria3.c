#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//Esta fecha esta en formato UNIX
	time_t unixTime = time(NULL);
	
	if (unixTime == -1) {
		char error_mensaje[200];
		sprintf(error_mensaje, "Ocurrio un error y devolvio %i", errno);
		perror(error_mensaje);
		return -1;
	}

	//La funcion ctime recibe un puntero a la estructura de memoria que guarda el tiempo
	printf("Fecha: %s", ctime(&unixTime));

	return 0;
}
