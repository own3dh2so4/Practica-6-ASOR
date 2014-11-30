#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	struct utsname info;
	//uname pide un putero a una estructura de la forma que pone en el manual.
	//declaramos la estructura arriba y le pasamos el puntero con la memoria ya reservada.
	int respuesta = uname(&info);
	
	if (respuesta == -1) {
		char error_mensaje[200];
		sprintf(error_mensaje, "Ocurrio un error y devolvio %i", errno);
		perror(error_mensaje);
		return -1;
	}

	printf("System Name: %s\n", info.sysname);
	printf("Node Name: %s\n", info.nodename);
	printf("Release: %s\n", info.release);	
	printf("Version: %s\n", info.version);	
	printf("Machine: %s\n", info.machine);
	// #ifdef _GNU_SOURCE
	//	printf("Domain: %s\n", info.domainname);
	// #endif
	
	return 0;
}
