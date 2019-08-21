#include <cstdio>
#include <climits>
#define MAX_N 10000

int wine[MAX_N];
int max_wines[2][MAX_N];

int max_wine(int n, bool use_one) {
	int cd1 = 0, cd2 = 0;

	if (n < 0)
		return 0;

	if (n == 0)
		return wine[0];

	if (max_wines[use_one][n] != 0)
		return max_wines[use_one][n];

	if (!use_one)
		cd1 = wine[n] + max_wine(n - 1, true);
	
	cd2 = wine[n] + max_wine(n - 2, false);

	max_wines[use_one][n] = (cd1 > cd2) ? cd1 : cd2;

	return max_wines[use_one][n];
}


int main() {
	int n, cd1, cd2;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &wine[i]);

	cd1 = max_wine(n - 1, false);
	cd2 = max_wine(n - 2, false);

	printf("%d\n", (cd1 > cd2) ? cd1 : cd2);

	return 0;
}
