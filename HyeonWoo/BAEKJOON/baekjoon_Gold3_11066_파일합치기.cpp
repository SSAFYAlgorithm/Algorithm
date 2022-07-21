#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 이건 다시 풀어야될듯 코드 이해가 어렵네;;

int T;
int C_arr[501];
int SUM[501];
int dp[501][501];
int K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> C_arr[i];
			SUM[i] = SUM[i - 1] + C_arr[i];
		}

		for (int i = 1; i <= K; i++)
		{
			for (int j = 1; j <= K - i; j++)
			{
				dp[j][i + j] = 21e8;
				for (int k = j; k < i + j; k++)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + SUM[i + j] - SUM[j - 1]);
				}
			}
		}

		cout << dp[1][K] << endl;

	}
	return 0;
}