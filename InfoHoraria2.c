#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	//En el manual pone que si pasas un puntero nulo el valor devuelto se guarda en la zona de memoria a la que apunte t.
	//Esta fecha esta en formato UNIX
	time_t unixTime = time(NULL);
	
	//Si sucede un error
	if (unixTime == -1) {
		char error_mensaje[200];
		sprintf(error_mensaje, "Ocurrio un error y devolvio %i", errno);
		perror(error_mensaje);
		return -1;
	}

	printf("Segundos transcurridos desde  1/1/1970 00:00:00 UTC: %i\n", unixTime);

	return 0;
}
