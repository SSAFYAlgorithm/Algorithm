#include <iostream>
using namespace std;

int dp[31];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[0] = 1;
	dp[2] = 3;
	int n;
	cin >> n;
	if (n == 2 || n==0) {
		cout << dp[n];
		return 0;
	}
	for (int i = 4; i <= n; i+=2) {
		int Sum = 0;
		for (int j = i - 4; j >= 0; j -= 2) {
			Sum += dp[j];
		}
		dp[i] = dp[i - 2] * dp[2] + Sum * 2;
	}
	cout << dp[n];
	

	return 0;
}