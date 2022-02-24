#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][3] = { 0 };
int cost[1002][3] = { 0 };
int ans = 1000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				dp[1][j] = cost[1][j];
			else
				dp[1][j] = 1000000;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + cost[j][2];
		}

		for (int j = 0; j < 3; j++) {
			if (j == i)
				continue;
			else
				ans = min(ans, dp[n][j]);
		}
	}
	cout << ans;
	return 0;
}