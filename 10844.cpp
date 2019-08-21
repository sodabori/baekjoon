#include <cstdio>
#define MAX_N 100
#define DIVIDER 1000000000

long counts[10][MAX_N + 1];

long number_count(int cur, int n) {
	long cd1, cd2;
	if (cur < 0 || cur > 9)
		return 0;

	if (n == 0)
		return 1;

	if (counts[cur][n] != 0)
		return counts[cur][n];

	if (cur == 9)
		cd1 = 0;
	else {
		cd1 = number_count(cur + 1, n - 1) % DIVIDER;
		counts[cur + 1][n - 1] = cd1;
	}

	if (cur == 0)
		cd2 = 0;
	else {
		cd2 = number_count(cur - 1, n - 1) % DIVIDER;
		counts[cur - 1][n - 1] = cd2;
	}

	return (cd1 + cd2) % DIVIDER;
}

int main() {
	int n;
	long sum = 0;

	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		sum += number_count(i, n - 1);
		sum = sum % DIVIDER;
	}
	printf("%ld\n", sum);

	return 0;
}
