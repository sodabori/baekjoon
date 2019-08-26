#include <cstdio>
#define MAX_N 1000

int a[MAX_N];
int count[MAX_N];

int long_sequence(int start, int end) {
	int len = 1, max = 1;
	if (start == end)
		return 1;

	for (int i = start + 1; i <= end; i++) {
		if (a[start] < a[i]) {
			len = 1 + long_sequence(i, end);

			if (len > max)
				max = len;
		}
	}

	count[start] = max;
	return max;
}


int main() {
	int n, len = 1, max = 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
			count[i] = 1;

	for (int i = 0; i < n; i++) {
		len = long_sequence(i, n - 1);
		if (len > max)
			max = len;
	}

	printf("%d\n", max);

	return 0;
}
