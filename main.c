#include <stdio.h>
#include <string.h>

void print_stats(char *strABC, char *strDEF) {
    printf("%lu %lu\n", (long unsigned)sizeof(strABC), (long unsigned)strlen(strABC));
	printf("%lu %lu\n", (long unsigned)sizeof(strDEF), (long unsigned)strlen(strDEF));
}

int main() {
	char strABC[] = "abc";
	char strDEF[10] = "def";
	char test1[5];
	char test2[5];

	printf("%lu %lu\n", (long unsigned)sizeof(strABC), (long unsigned)strlen(strABC));
	printf("%lu %lu\n", (long unsigned)sizeof(strDEF), (long unsigned)strlen(strDEF));

	print_stats(strABC, strDEF);

	// max. Länge angeben, sonst ungültiger Speicherzugriff möglich
	scanf("%4s", test1);
	scanf("%4s", test2);

	printf("%s\n%s\n%s\n%s\n", strABC, strDEF, test1, test2);

	return 0;
}
