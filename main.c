#include <stdio.h>
#include <stdlib.h>

char *getl();

int main(void) {
	printf("-- MAKEMAKE: Makefile maker --\n");
	printf("COMPILER : ");
	char *compiler = getl();
	printf("%s", compiler);
}

char *getl() {
	char *s = malloc(1);
	int len;
	char c;
	while ((c = getchar()) != EOF && c != '\n') {
		s = realloc(s, len + 2);
		s[len] = c;
		len++;
	}
	return s;
}
