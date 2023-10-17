#include <stdio.h>

int main(int argc, char **argv) {
	// Print all arguments passed from CLI
	for(int i = 0; i < argc; i++) {
		printf("%i: %s\n", i, argv[i]);
	}
	return 0;
}
