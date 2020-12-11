#include "random.h"

void Seed() {
	srand(time(NULL));
}

int Random() {
	int num;

	num = rand() % 256;

	return num;
}