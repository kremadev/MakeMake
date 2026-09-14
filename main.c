#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCR_ENT  "\x1b[?1049h"
#define SCR_EXT  "\x1b[?1049l"

char *getl();

int main(void) {
	printf(SCR_ENT);

    printf("\n\n--------------------------------\n");
	printf("--| MAKEMAKE: Makefile maker |--\n");
	printf("--------------------------------\n\n");
	
	printf("DOTNET (C#) and JAVAC (java) are not supported!\n\n\n");

	printf("COMPILER : "); char *CC = getl();

	printf("SOURCE : "); char *SRC = getl();

	printf("OUTPUT : "); char *OUT = getl();

	printf("FLAGS : "); char *FLAGS = getl();

	printf("CLEAN [y/N] : "); char CLEAN = getchar();

	FILE *makefile = fopen("makefile", "w");

	fprintf(makefile, "CC = %s\n", CC);
	fprintf(makefile, "SRC = %s\n", SRC);
	fprintf(makefile, "OUT = %s\n", OUT);
	fprintf(makefile, "FLAGS = %s\n\n", FLAGS);

	fprintf(makefile, "all: %s\n", OUT);
	fprintf(makefile, "%s:\n", OUT);
	fprintf(makefile, "    $(CC) $(FLAGS) $(SRC) -o $(OUT)");

	if (CLEAN == 'y' || CLEAN == 'Y') {
		fprintf(makefile, "\n\n.PHONY: clean\n");
		fprintf(makefile, "clean:\n");
		fprintf(makefile, "    rm $(OUT)");
	}

	printf("\"./makefile\" written. if you ");

	printf(SCR_EXT);

	free(CC);
	free(SRC);
	free(OUT);
	free(FLAGS);

	return 0;
}

char *getl() {
	char *s = malloc(1);
	int len = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n') {
		s = realloc(s, len + 2);
		s[len] = c;
		len++;
	}
	s[len] = '\0';
	return s;
}
