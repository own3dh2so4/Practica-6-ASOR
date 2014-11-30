#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	uid_t uid = getuid();
	uid_t euid = geteuid();
	
	//Cogemos la info de /etc/passwd
	struct passwd *pw = getpwuid(uid);
	struct passwd *epw = getpwuid(uid);

	//Posible errores usuarios no encontrados u otro error
	if (pw == NULL || epw == NULL) {
		perror("Error al obtener la informacion del usuario\n");
		return -1;
	}

	char *name = pw->pw_name;
	char *ename = epw->pw_name;

	if (uid == euid)
		printf("UID y EUID son el mismo: %s(%i)\n", pw->pw_name, uid);
	else
		//Si el propietario no es el que ejecuta el archivo es por que el bit setuid esta activado.
		printf("UID es %s(%i) y EUID is %s(%i), el bit setuid esta activado\n", name, uid, ename, euid);

	return 0;
}
