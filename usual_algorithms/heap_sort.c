/*
 *∂—≈≈–Ú
 */
#include <stdio.h>
#include <stdlib.h>

void heap(int *a, int n, int i) {
	int j, t = a[i];
	while ((j = (i<<1) + 1) < n) {
		if ((j+1) < n && a[j+1] > a[j]) ++j;
		if (a[j] > t) { a[i] = a[j]; i = j;}
		else break;
	}
	a[i] = t;
}

void hsort(int *a, int n) {
	for (int i = ((n-2)>>1); i >= 0; --i)
		heap(a, n, i);
	for (int i = n - 1; i > 0; --i) {
		int t = a[0]; a[0] = a[i]; a[i] = t;
		heap(a, i, 0);
	}
}


int cmp(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

void test(void) {
	int *a = NULL, *t = NULL, *b;
	int n = 0, i = 0, j = 0;
	for (i = 0; i < 100; ++i) {
		n = rand() % 100;
		a = (int *)malloc(sizeof(int) * n);
		t = (int *)malloc(sizeof(int) * n);
		b = (int *)malloc(sizeof(int) * n);
		for (j = 0; j < n; ++j) {
			a[j] = rand() % 20;
			b[j] = a[j];
		}
		hsort(a, n);
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
