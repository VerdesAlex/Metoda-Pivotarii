#include <iostream>
struct mat { float m[12][13]; };
void matr() {
	mat a;
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			std::cin>>a.m[i][j];
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++)
			std::cout<<a.m[i][j]<<' ';
		printf("\n");
	}
}