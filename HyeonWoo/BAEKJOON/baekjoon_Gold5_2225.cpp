#include <iostream>
#include <vector>
using namespace std;

int n,k;
int dp[205][205];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i <= k; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])% 1000000000;
		}
	}

	cout << dp[k][n];
	


	return 0;
}