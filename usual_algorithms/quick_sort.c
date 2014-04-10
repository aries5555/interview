/*
 *©ЛкыеепР
 */
#include <stdio.h>
#include <stdlib.h>

void mqsort(int*a, int b, int e) {
	int i = b - 1, j = e + 1, v, t;
	if (!a || b >= e) return;
	v = a[b + ((e-b)>>1)];
	while (i < j) {
		while (a[++i] < v); while (a[--j] > v);
		if (i < j) { t = a[j]; a[j] = a[i]; a[i] = t;}
	}
	i += i == j; j -= i == j;
	if (i < e) mqsort(a, i, e);
	if (b < j) mqsort(a, b, j);
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
		mqsort(a, 0, n - 1);
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
