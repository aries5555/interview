/*
 *ц╟ещеепР
 */
#include <stdio.h>
#include <stdlib.h>

void bsort(int *a, int n) {
	int i, j, t; 
	--n;
	while (n > 0) {
		j = 0;
		for (i = 0; i < n; ++i) {
			if (a[i+1] < a[i]) {
				t = a[i+1]; a[i+1] = a[i]; a[i] = t;
				j = i;
			}
		}
		n = j;
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
		bsort(a, n);
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
