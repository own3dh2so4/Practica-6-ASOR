#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	int respuesta = setuid(0);
	char error_mensaje[150];
	if (respuesta == -1) {
		sprintf(error_mensaje, "Ocurrio un error y devolvio %i", errno);
		perror(error_mensaje);
	}
	//Si nuestra llamada termino en error nuestro programa terminara con el mismo error.
	return respuesta;
}
