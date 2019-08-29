#include <cstdio>

int combination(int m, int n) {
	int tmp = 1;

	n = (n < m - n) ? n : m - n;

	for (int i = 1; i <= n; i++)
		tmp = tmp * (m - i + 1) / i;

	return tmp;
}

int main() {
	int T, n, m;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", combination(m, n));
	}

	return 0;
}
