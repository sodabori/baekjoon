#include <cstdio>
#define MAX_N 1000

int a[MAX_N];
int count[MAX_N];

int bitonic_sequence(int n) {
	int max = 1;

	for (int i = 0; i < n; i++) {
		if (count[i] == 0)
			count[i] = 1;

		for (int j = i + 1; j < n; j++)
			if (a[j] > a[i] && count[i] + 1 > count[j])
				count[j] = count[i] + 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i] && count[i] + 1 > count[j])
				count[j] = count[i] + 1;

	for (int i = 0; i < n; i++)
		if (count[i] > max)
			max = count[i];

	return max;
}

int main() {
	int n, len = 1, max = 1, inc_max = 1, dec_max = 1;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("%d\n", bitonic_sequence(n));

	return 0;
}
