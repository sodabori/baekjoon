#include <cstdio>
#define MAX_N 1000

int count[MAX_N][MAX_N];
int a[MAX_N];

int long_sequence(int start, int end) {
	int len = 0, max = 0;

	if (start == end)
		return 1;

	if (count[start][end] != 0)
		return count[start][end];

	for (int i = end - 1; i >= start; i--) {
		if (a[i] < a[end]) {
			len = 1 + long_sequence(start, i);

			if (len > max)
				max = len;
		}
	}

	count[start][end] = max;
	return max;
}

int main() {
	int n, max = 0, tmp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		tmp = long_sequence(0, i);

		if (tmp > max)
			max = tmp;
	}

	printf("%d\n", max);

	return 0;
}
