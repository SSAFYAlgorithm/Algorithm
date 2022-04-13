#include <iostream>
#include <vector>
using namespace std;

int N;
int Coin[11];
int targetCost;
// dp 에 동전개수 입력
int dp[11][64001];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Coin[i];
	}
	cin >> targetCost;
	for (int cost = 1; cost <= targetCost; cost++) {
		// min쓰기위해 초기화
		dp[0][cost] = 21e8;
	}
	for (int i = 1; i <= N; i++) {
		for (int cost = 1; cost <= targetCost; cost++) {
			int a = dp[i - 1][cost];
			int b = 21e8;
			if (cost - Coin[i] >= 0) {
				b = dp[i][cost - Coin[i]] + 1;
			}
			dp[i][cost] = min(a, b);

		}
	}
	if (dp[N][targetCost] == 21e8) {
		cout << "impossible";
		return 0;
	}
	cout << dp[N][targetCost];
	return 0;
}
