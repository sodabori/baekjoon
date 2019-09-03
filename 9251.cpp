#include <cstdio>
#include <cstring>
#define MAX_LEN 1000

char str1[MAX_LEN + 1];
char str2[MAX_LEN + 1];
int count[MAX_LEN][MAX_LEN];

int lcs(int cur1, int cur2, int len1, int len2) {
	int cd1, cd2;

	if (cur1 == len1 || cur2 == len2)
		return 0;

	if (cur1 == len1 - 1 && cur2 == len2 - 1) {
		count[cur1][cur2] = (str1[cur1] == str2[cur2]);
		return count[cur1][cur2];
	}

	if (count[cur1][cur2] != 0)
		return count[cur1][cur2];

	if (str1[cur1] == str2[cur2]) {
		count[cur1][cur2] = 1 + lcs(cur1 + 1, cur2 + 1, len1, len2);
		return count[cur1][cur2];
	}
	else {
		cd1 = lcs(cur1 + 1, cur2, len1, len2);
		cd2 = lcs(cur1, cur2 + 1, len1, len2);
		if (cd1 > cd2) {
			count[cur1][cur2] = cd1;
			return cd1;
		}
		else {
			count[cur1][cur2] = cd2;
			return cd2;
		}
	}
}

int main() {
	scanf("%s", str1);
	scanf("%s", str2);

	printf("%d\n", lcs(0, 0, strlen(str1), strlen(str2)));

	return 0;
}
