#include <cstdio>
#define MAX_N 1000

int a[MAX_N];
int inc_count[MAX_N];
int dec_count[MAX_N];

int lds(int start, int end) {
	int len = 1, max = 1;

	if (start == end)
		return 1;

	if (dec_count[start] != 1)
		return dec_count[start];

	for (int i = start + 1; i <= end; i++) {
		if (a[start] > a[i]) {
			len = 1 + lds(i, end);

			if (len > max)
				max = len;
		}
	}

	dec_count[start] = max;
	return dec_count[start];
}
 
int lis(int start, int end) {
	int len = 1, max = 1;

	if (start == end)
		return 1;

	if (inc_count[start] != 1)
		return inc_count[start];

	for (int i = start + 1; i <= end; i++) {
		if (a[start] < a[i]) {
			len = 1 + lis(i, end);

			if (len > max)
				max = len;
		}
	}

	inc_count[start] = max;
	return inc_count[start];
}

int main() {
	int n, len = 1, max = 1, inc_max = 1, dec_max = 1;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			inc_count[i] = 1;
			dec_count[i] = 1;
		}

		inc_max = 1;
		dec_max = 1;

		for (int i = 0; i <= k; i++) {
			len = lis(i, k);
			if (len > inc_max)
				inc_max = len;
		}

		for (int i = k; i < n; i++) {
			len = lds(i, n - 1);
			if (len > dec_max)
				dec_max = len;
		}

		len = inc_max + dec_max;
		if (len > max)
			max = len;
	}

	printf("%d\n", max - 1);

	return 0;
}
