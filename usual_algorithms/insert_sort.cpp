/*
 ≤Â»Î≈≈–Ú
 */
#include <stdio.h>
#include <stdlib.h>

void isort(int *a, int n) {
	for (int j = 1; j < n; ++j) {
		int k = a[j]; int i = j - 1;
		while (i >= 0 && a[i] > k) {
			a[i+1] = a[i];
			--i;
		}
		a[i+1] = k;
	}
}

int cmp(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

void test(void) {
	int *a = NULL, *t = NULL, *b;
	int n = 0, i = 0, j = 0;
	for (i = 0; i < 1000; ++i) {
		n = rand() % 100;
		a = (int *)malloc(sizeof(int) * n);
		t = (int *)malloc(sizeof(int) * n);
		b = (int *)malloc(sizeof(int) * n);
		for (j = 0; j < n; ++j) {
			a[j] = rand() % 20;
			b[j] = a[j];
		}
		isort(a, n);
		qsort(b, n, sizeof(int), cmp);
		for (j = 0; j < n; ++j) {
			if (a[j] != b[j]) printf("Error\n");
		}
		free(a); free(b); free(t);
	}
}

int main(void) {
	test();
	return 0;
}
