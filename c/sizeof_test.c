#include <stdio.h>

typedef union {
	long i;
	int k[5];
	char c;
}DATE;

typedef struct data {
	int cat;
	DATE cow;
	double dog;
}_DATA;

int main() {
	DATE uion_data;
	_DATA s_data;
	printf("sizeof(DATE): %lu\n", sizeof(uion_data));
	printf("sizeof(struct data): %lu\n", sizeof(struct data));

	printf("addr data.cat: %lu\n", &(s_data.cat));
	printf("addr data.cow: %lu\n", &(s_data.cow));
	printf("addr data.dog: %lu\n", &s_data.dog);

	return 0;
}
