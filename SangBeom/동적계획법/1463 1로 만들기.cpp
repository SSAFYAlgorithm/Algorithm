#include <iostream>

using namespace std;
int dp[1000001];
int main(void) {
	int num;
	cin >> num;
	dp[1] = 0;
	for (int i = 2; i <= num; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
		}
	}
	cout << dp[num] << endl;
	return 0;

}