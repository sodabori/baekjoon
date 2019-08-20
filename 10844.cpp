#include <cstdio>
#define MAX_N 100
#define DIVIDER 1000000000

long counts[10][MAX_N];

long number_count(int cur, int n) {
	long cd1, cd2;
	if (cur < 0 || cur > 9)
		return 0;

	if (n == 0)
		return 1;

	if (counts[cur][n] != 0)
		return counts[cur][n];

	cd1 = number_count(cur + 1, n - 1) % DIVIDER;
	cd2 = number_count(cur - 1, n - 1) % DIVIDER;

	if (cur < 9)
		counts[cur + 1][n - 1] = cd1;
	if (cur > 0)
		counts[cur - 1][n - 1] = cd2;

	return (cd1 + cd2) % DIVIDER;
}

int main() {
	int n;
	long sum = 0;

	scanf("%d", &n);
	for (int i = 1; i < 10; i++)
		sum += number_count(i, n - 1);
	printf("%ld\n", sum);

	return 0;
}
