#include <iostream>
float a[12][13], b[12][13], a1[12][13], b1[12][13];
int i, j, k = 1, n, m;
void citire_date() {
	std::cout << "Introdu dimensiunile matricii(n,m): " << '\n';
	std::cin >> n >> m;
	std::cout << "Introdu matricea: " << '\n';
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			std::cin >> a[i][j];
	printf("Introdu vectorul x:\n");
	for (i = 1; i <= n; i++) std::cin >> a[i][m + 1];
	printf("\n");

}
void copiere(float a[12][13], float b[12][13]) {
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m + 1; j++)
			a[i][j] = b[i][j];
	}
}
void afisare(float a[12][13]) {
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m + 1; j++) {
			if (j == m + 1) a[i][j] >= 0 ? printf("  %.2f ", a[i][j]) : printf(" %.2f ", a[i][j]);
			else a[i][j] >= 0 ? printf("%.2f  ", a[i][j]) : printf("%.2f ", a[i][j]);
		}
		printf("\n");
	}
}
void transformare(float a[12][13], float b[12][13]) {
	for (k = 1; k <= n; k++) {
		for (j = 1; j <= m + 1; j++)
			for (i = 1; i <= n; i++) {
				b[i][j] = (a[i][j] * a[k][k] - a[i][k] * a[k][j]) / a[k][k];
				b[k][j] = a[k][j] / a[k][k];
				b[i][k] = 0;
				b[k][k] = 1;
			}
		copiere(a, b);
		afisare(a);
		printf("\n");
	}
}
void solutie(float a[12][13]) {
	std::cout << "Solutia este vectorul v=(";
	for (i = 1; i <= n; i++) {
		if (i < n) printf("x%d = %.2f, ", i, a[i][m + 1]);
		else printf("x%d = %.2f).\n", i, a[i][m + 1]);
	}
}
void sist() {
	citire_date();
	copiere(a1, a);
	copiere(b, a);
	transformare(a, b);
	solutie(a);
}

void inversa() {
	printf("Inversa functiei este: \n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m + n; j++)
			printf("%.2f ", a1[i][j]);
		printf("\n");
	}
}
void transformare2(float a1[12][13], float b1[12][13]) {
	for (k = 1; k <= n; k++) {
		for (j = 1; j <= m + n; j++)
			for (i = 1; i <= n; i++) {
				b1[i][j] = (a1[i][j] * a1[k][k] - a1[i][k] * a1[k][j]) / a1[k][k];
				b1[k][j] = a1[k][j] / a1[k][k];
				b1[i][k] = 0;
				b1[k][k] = 1;
			}
		copiere(a1, b1);
		printf("\n");
	}
}
void creare_compl() {
	for (i = 1; i <= n; i++)
		for (j = m + 1; j <= m + n; j++)
		{
			if (i == j - m) a1[i][j] = 1;
			else a1[i][j] = 0;
		}
	copiere(b1, a1);
}
void inv() {
	creare_compl();
	copiere(b1, a1);
	transformare2(a1, b1);
	inversa();
}

int main() {
	sist();
	inv();
	system("pause");
}