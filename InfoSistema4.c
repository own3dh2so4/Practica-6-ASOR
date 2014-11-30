#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Como usar: ./compilado <directorio>\n");
		return -1;
	}

	printf("Max number of links: %li\n", pathconf(argv[1], _PC_LINK_MAX));
	printf("Max length of paths: %li\n", pathconf(argv[1], _PC_PATH_MAX));
	printf("Max length of file names: %li\n", pathconf(argv[1], _PC_NAME_MAX));

	return 0;
}
