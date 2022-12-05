#include <stdio.h>
#include <math.h>
void main() {
	float a, b, c, d = 0, x1, x2, x;
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);
	if (a == 0) {
		printf("x= %f", -c / b);
	}
	else {
		d = b * b - 4 * a * c;
		if (d > 0) {
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			printf("x1=%f\nx2=%f", x1, x2);
		}
		else {
			printf("x1=%.2f+i*%.3f\n", -b, +sqrt(-d) / (2 * a));
			printf("x2=%.2f-i*%.3f", -b, sqrt(-d) / (2 * a));
		}
	}
}