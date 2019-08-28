#include <cstdio>
#define MAX_N 500

int a[MAX_N];
int count[MAX_N];

int lis(void) {
	int max = 1;

	for (int i = 0; i < MAX_N; i++) {
		if (a[i] != 0 && count[i] == 0)
			count[i] = 1;

		for (int j = i; j < MAX_N; j++) {
			if (a[j] > a[i] && count[i] + 1 > count[j])
				count[j] = count[i] + 1;
		}
	}

	for (int i = 0; i < MAX_N; i++)
		if (count[i] > max)
			max = count[i];

	return max;
}

int main() {
	int n, index, value;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &index, &value);
		a[index - 1] = value;
	}

	printf("%d\n", n - lis());

	return 0;
}
