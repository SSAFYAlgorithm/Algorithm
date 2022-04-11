#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;

struct MinMax {
	int min;
	int max;
};

MinMax dp[100001][3];

vector <int> answer;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 3; i++) {
		dp[0][i] = { 0,0 };
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = ({ min(dp[i - 1][0].min, dp[i - 1][1].min),max(dp[i - 1][0].max, dp[i - 1][1].max) });
		dp[i][1] = ({ min(dp[i - 1][0].min, dp[i - 1][1].min, dp[i - 1][2].min),max(dp[i - 1][0].max, dp[i - 1][1].max), dp[i - 1][2].max) });
		dp[i][2] = ({ min(dp[i - 1][1].min, dp[i - 1][2].min),max(dp[i - 1][1].max, dp[i - 1][2].max) });
	}

	return 0;
}