#include <iostream>

using namespace std;

#define MOD 1000000009

long long dp[1000001];

int main() {
	int n, temp;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 4; j <= temp; j++) {
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % MOD;
		}
		cout << dp[temp] % MOD << "\n";
	}
	return 0;
}