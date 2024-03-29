#include <cstdio>
#include <climits>
#define STAIR_NUMBER 300
#define MAX_SCORE 10000

int stairs[STAIR_NUMBER];
int max_scores[2][STAIR_NUMBER];

int stair_score(int n, bool use_one) {
	int cd1 = 0, cd2 = 0, ss1 = 0, ss2 = 0;

	if (n < 0)
		return 0;

	if (n == 0) {
		max_scores[use_one][0] = stairs[0];
		return stairs[0];
	}

	if (max_scores[use_one][n] != 0)
		return max_scores[use_one][n];

	if (!use_one)
		cd1 = stairs[n] + stair_score(n - 1, true);
	
	cd2 = stairs[n] + stair_score(n - 2, false);

	max_scores[use_one][n] = (cd1 > cd2) ? cd1 : cd2;
	return max_scores[use_one][n];
}

int main() {
	int n, cd1, cd2;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &stairs[i]);

	printf("%d\n", stair_score(n - 1, false));

	return 0;
}
