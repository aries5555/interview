// 二分查找，C语言版本。
#include <stdio.h>
#include <stdlib.h>

int *binary_search(int *a, int n, int v) {
	int *b = a, *m, *e = a + n;
	if (!a || n <= 0) return NULL;
	while (b < e) {
		m = b + ((e-b)>>1);
		if (*m == v) return m;
		if (*m > v) e = m;
		else b = m + 1;
	}
	return NULL;
}

int cmp(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

void test(void) {
	int *a, n;
	for (int i = 0; i < 100; ++i) {
		n = rand() % 10000;
		a = (int *)malloc(sizeof(int)*n);
		for (int j = 0; j < n; ++j) a[j] = rand() % 1000;
		qsort(a, n, sizeof(int), cmp);
		for (int j = 0; j < n; ++j) {
			if (NULL == binary_search(a, n, a[j])) {
				printf("Error\n");
			}
		}
		for (int j = 0; j < n; ++j) {
			int v = rand() % 10000;
			int find = 0;
			for (int k = 0; k < n; ++k) {
				if (a[k] == v) {
					find = 1;
					break;
				}
			}
			if (find != (binary_search(a, n, v) != NULL)) {
				printf("Error\n");
			}
		}
		free(a);
	}
}

int main(void) {
	test();
	return 0;
}