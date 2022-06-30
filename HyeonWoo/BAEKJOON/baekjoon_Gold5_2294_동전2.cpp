#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector <int> Coin;
int dp[200][10010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		Coin.push_back(temp);
	}

	sort(Coin.begin(), Coin.end());
	
	for (int i = 1; i <= n; i++) {
		int nowCoin = Coin[i-1];
		for (int j = 1; j <= k; j++) {
			if (i == 2 && j == 9) {
				int de = -1;
			}
			if (j < nowCoin) {
				if (dp[i - 1][j] > 0) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = -1;
				}
			}
			else {
				if (dp[i - 1][j] != 0 && dp[i - 1][j] != -1) {
					if (dp[i][j - nowCoin] != -1) {
						if (dp[i - 1][j] != -1) {
							dp[i][j] = min(dp[i - 1][j], dp[i][j - nowCoin] + 1);
						}
						else {
							dp[i][j] = dp[i - 1][j];
						}
					}
					else { // dp[i][j - nowCoin] == -1
						if (dp[i - 1][j] > 0) {
							dp[i][j] = dp[i - 1][j];
						}
						else {
							dp[i][j] = -1;
						}
					}
				}
				else {
					if (dp[i][j - nowCoin] == -1) {
						dp[i][j] = -1;
					}
					else {
						dp[i][j] = dp[i][j - nowCoin] + 1;
					}
				}
			}
		}
	}
	
	cout << dp[n][k];


	return 0;
}