#include "functions.h"
#include "random.h"

void Move(int* x, int xv, int* y, int yv) {
	*x += xv;
	*y += yv;
}

void Update(int x, int* xv, int y, int* yv, int* coll) {
	if (x <= 0 || x >= 800 - 100) {
		*xv = -*xv;
		*coll = 1;
	}
	if (y <= 0 || y >= 600 - 100) {
		*yv = -*yv;
		*coll = 1;
	}
}

void Collusion(int* coll, int* r, int* g, int* b) {
	if (*coll == 1) {
		*r = Random();
		*g = Random();
		*b = Random();
	}
	
	*coll = 0;
}

int Summ(int* num1, int* num2) {
	int sum;

	num1 = 10
	sum = num1 + num2;

	return sum;
}
