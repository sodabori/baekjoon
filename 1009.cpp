#include <cstdio>

int computer(int a, int b) {
	int tmp = a;

	for (int i = 1; i < b; i++)
		tmp = (tmp * a) % 10;

	return tmp % 10;
}

int main() {
	int T, a, b;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", computer(a, b));
	}

	return 0;
}
