#include <cstdio>
#include <climits>
#define MAX_N 1000000

int min_counts[MAX_N + 1];
int cache = 0;
int call = 0;

int make_one(int n) {
	call++;
	int cd[3] = {INT_MAX, INT_MAX, INT_MAX}, min = INT_MAX, tmp;

	if (n == 1)
		return 0;

	if (min_counts[n] != 0) {
		cache++;
		return min_counts[n];
	}

	if (n % 3 == 0)
		cd[0] = 1 + make_one(n / 3);
	if (n % 2 == 0)
		cd[1] = 1 + make_one(n / 2);
	cd[2] = 1 + make_one(n - 1);

	for (int i = 0; i < 3 ; i++)
		if (cd[i] < min)
			min = cd[i];

	min_counts[n] = min;

	return min;
}	

int main() {
	int n;

	scanf("%d", &n);
	printf("%d\n", make_one(n));
	printf("function call : %d\n", call);
	printf("cache call : %d\n", cache);

	return 0;
}
