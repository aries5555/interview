#include <stdio.h>
#include <stdlib.h>

void msort(int*a, int *t, int b, int e) {
	int mid  = (b&e) + ((b^e)>>1);
	int p1 = b, p2 = mid + 1, i = b;
	if (!a || !t || b >= e) return;

	msort(a, t, b, mid); msort(a, t, mid + 1, e);
	while (p1 <= mid || p2 <= e) {
		if (p2 > e || (p1 <= mid && a[p1] <= a[p2]))
			t[i++] = a[p1++];
		else t[i++] = a[p2++];
	}
	for (i = b; i <= e; ++i) a[i] = t[i];
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
		msort(a, t, 0, n - 1);
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
