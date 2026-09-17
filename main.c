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
	
	printf("WARNING: This will overwrite any file name \"makefile\" or the file name you choose.");
	printf("Only GCC style compilers are supported, if your compiler doesnt support \"-o\" the same way GCC does, its not supported.\n\n\n");

	printf("Makefile name (default: makefile) : "); char *MAKEFILE = getl();

	printf("Compiler of choice : "); char *CC = getl();

	printf("Source file : "); char *SRC = getl();

	printf("Output filename : "); char *OUT = getl();

	printf("Extra flags : "); char *FLAGS = getl();

	printf("add a \"make clean\" function [y/N] : "); char CLEAN = getchar();

	FILE *makefile = fopen(MAKEFILE, "w");

	fprintf(makefile, "# MADE BY MakeMake\n");

	fprintf(makefile, "CC = %s\n", CC);
	fprintf(makefile, "SRC = %s\n", SRC);
	fprintf(makefile, "OUT = %s\n", OUT);
	fprintf(makefile, "FLAGS = %s\n\n", FLAGS);

	fprintf(makefile, "all: %s\n", OUT);
	fprintf(makefile, "%s:\n", OUT);
	fprintf(makefile, "\t$(CC) $(FLAGS) $(SRC) -o $(OUT)");

	if (MAKEFILE == '\n') MAKEFILE = "makefile";

	if (CLEAN == 'y' || CLEAN == 'Y') {
		fprintf(makefile, "\n\n.PHONY: clean\n");
		fprintf(makefile, "clean:\n");
		fprintf(makefile, "\trm $(OUT)");
	}

	printf("\"./makefile\" written. if you have any issues or can help with other compilers reach out to my discord: @kremadev");

	printf(SCR_EXT);

	free(MAKEFILE);
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
