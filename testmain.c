#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = "Hello";  // Pointer to a string literal
    str = (char *)malloc(15);
	free(str);free(str);
    printf("%s\n", str);  // Prints "World"
    return 0;
}
