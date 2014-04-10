/*
 * 合并排序的非递归实现。
 */

#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *b, int l, int m, int e)
{
	int p1 = l, mid = m, p2 = mid + 1, i = l;
	while (p1 <= m || p2 <= e)
	{
		if (p2 > e || (p1 <= mid && a[p1] <= a[p2])) b[i++] = a[p1++];
		else b[i++] = a[p2++];
	}
	//no copy here.
}

void mpass(int *a, int *b, int n, int l)
{
	int i = 0, j = 0;
	const int f = l - 1; const int m = (l<<1) - 1;
	while ((i + (l<<1)) < n)
	{
		merge(a, b, i, i + f, i + m);
		i += (l<<1);
	}
	if ((i + l) < n) merge(a, b, i, i + f, n -1);
	else for (j = i; j < n; ++j) b[j] = a[j];
}

void msort(int *a, int *t, int n)
{
	int l = 1;
	while (l < n)
	{
		mpass(a, t, n, l); l <<= 1;
		mpass(t, a, n, l); l <<= 1;
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
		msort(a, t, n);
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
