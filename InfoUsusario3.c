#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	uid_t uid = getuid();
	uid_t euid = geteuid();
	struct passwd *pw = getpwuid(uid);
	struct passwd *epw = getpwuid(uid);

	if (pw == NULL || epw == NULL) {
		perror("Error al obtener la informacion del usuario\n");
		return -1;
	}
	
	//mirando man 3 getpwuid vemos que la estructura trae mas info.
	char *name = pw->pw_name;
	char *ename = epw->pw_name;
	char *home = pw->pw_dir;
	char *ehome = epw->pw_dir;
	char *gecos = pw->pw_gecos;
	char *egecos = epw->pw_gecos;

	if (uid == euid) {
		printf("UID y EUID son el mismo:\n");
		printf("ID: %s(%i)\n", name, uid);
		printf("Home dir: %s\n", home);
		printf("Real name: %s\n", gecos);
	}
	else {
		printf("UID datos:\n");
		printf("\tID: %s(%i)\n", name, uid);
		printf("\tHome dir: %s\n", home);
		printf("\tReal name: %s\n", gecos);
		printf("EUID datos:\n");
		printf("\tID: %s(%i)\n", ename, euid);
		printf("\tHome dir: %s\n", ehome);
		printf("\tReal name: %s\n", egecos);
	}

	return 0;
}
