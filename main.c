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

	printf("Compiler of choice : "); char *compilerName = getl();

	printf("Source file : "); char *sourceFileName = getl();

	printf("Output filename : "); char *outputFileName = getl();

	printf("Extra flags : "); char *compileFlags = getl();

	printf("Add a \"make clean\" function [y/N] : "); char CLEAN = getchar();

	FILE *makefile = fopen("makefile", "w");

	fprintf(makefile, "# MADE BY MakeMake\n");

	fprintf(makefile, "CC = %s\n", compilerName);
	fprintf(makefile, "SRC = %s\n", sourceFileName);
	fprintf(makefile, "OUT = %s\n", outputFileName);
	fprintf(makefile, "FLAGS = %s\n\n", compileFlags);

	fprintf(makefile, "all: %s\n", outputFileName);
	fprintf(makefile, "%s:\n", outputFileName);
	fprintf(makefile, "\t$(CC) $(FLAGS) $(SRC) -o $(OUT)");

	if (CLEAN == 'y' || CLEAN == 'Y') {
		fprintf(makefile, "\n\n.PHONY: clean\n");
		fprintf(makefile, "clean:\n");
		fprintf(makefile, "\trm $(OUT)");
	}

	printf("\"./makefile\" written. if you have any issues or can help with other compilers reach out to my discord: @kremadev");

	getchar();

	printf(SCR_EXT);

	free(compilerName);
	free(sourceFileName);
	free(outputFileName);
	free(compileFlags);

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
