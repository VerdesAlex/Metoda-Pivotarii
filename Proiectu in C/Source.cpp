#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
struct mat { float z[12][13]; int m; int n; };
void citire_date(mat& a) {
	printf("Introdu dimensiunile matricii(n,m): \n");
	scanf("%d", &a.n);
	scanf("%d", &a.m);
	printf("Introdu matricea: \n");
	for (int i = 0; i <= a.n - 1; i++)
		for (int j = 0; j <= a.m - 1; j++)
			scanf("%f", &a.z[i][j]);
	printf("Introdu vectorul x:\n");
	for (int i = 0; i <= a.n - 1; i++) scanf("%f", &a.z[i][a.m]);
	printf("\n");
}
void copiere(mat& a, mat& b) {
	a.n = b.n;
	a.m = b.m;
	for (int i = 0; i <= a.n-1; i++) {
		for (int j = 0; j <= a.m; j++)
			a.z[i][j] = b.z[i][j];
	}
}
void afisare(mat& a) {
	for (int i = 0; i <= a.n-1; i++) {
		for (int j = 0; j <= a.m; j++) {
			if (j == a.m) a.z[i][j] >= 0 ? printf("  %.2f ", a.z[i][j]) : printf(" %.2f ", a.z[i][j]);
			else a.z[i][j] >= 0 ? printf("%.2f  ", a.z[i][j]) : printf("%.2f ", a.z[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void transformare(mat& a, mat& b) {
	for(int k = 0; k < a.n; k++) {
		for (int j = 0; j < a.m + 1; j++)
			for (int i = 0; i < a.n; i++) {
				b.z[i][j] = (a.z[i][j] * a.z[k][k] - a.z[i][k] * a.z[k][j]) / a.z[k][k];
				b.z[k][j] = a.z[k][j] / a.z[k][k];
				b.z[i][k] = 0;
				b.z[k][k] = 1;
			}
		/*for (int j = 0; j < a.m; j++)
			for (int i = 0; i < a.n; i++) {
				if (i != k && j != k) a.z[i][j] = (a.z[i][j] * a.z[k][k] - a.z[i][k] * a.z[k][j]) / a.z[k][k];
			}
		for (int i = 0; i < a.m; i++) {
			if (i != k) a.z[k][i] = a.z[k][i] / a.z[k][k];
		}
		for (int i = 0; i < a.n; i++) {
			if (i == k) a.z[i][k] = 1;
			else a.z[i][k] = 0;
		}*/
		copiere(a, b);
	}
}
void solutie(mat& a) {
	printf("Solutia este vectorul v=( ");
	for (int i = 0; i < a.n; i++) {
		if (i < a.n - 1) printf("x%d = %.2f, ", i + 1, a.z[i][a.m]);
		else printf("x%d = %.2f ).\n", i + 1, a.z[i][a.m]);
	}
}
void sist(mat& a, mat& b, mat& a1) {
	citire_date(a);
	copiere(a1, a);
	copiere(b, a);
	transformare(a, b);
	afisare(a);
	solutie(a);
}

void inversa(mat& a) {
	printf("Inversa functiei este: \n\n");
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.m; j++)
			printf("%.2f ", a.z[i][j]);
		printf("\n");
	}
	printf("\n");
}
void transformare2(mat& a1, mat& b1, mat& b) {
	for (int k = 0; k < a1.n; k++) {
		for (int i = 0; i < a1.n; i++)
			a1.z[i][a1.m] = b.z[i][k];
		mat aux1, aux2;
		copiere(aux1, a1);
		copiere(aux2, a1);
		transformare(a1, aux1);
		for (int i = 0; i < a1.n; i++)
			b1.z[i][k] = a1.z[i][a1.m];
		copiere(a1, aux2);
		copiere(aux1, a1);
	}
}
void inv(mat& a1, mat& b1, mat& b) {
	transformare2(a1, b1, b);
	printf("\n");
	inversa(b1);
}

int main() {
	mat a, b, a1, b1;
	sist(a,b,a1);
	copiere(b1, b);
	inv(a1, b1, b);
	system("pause");
}