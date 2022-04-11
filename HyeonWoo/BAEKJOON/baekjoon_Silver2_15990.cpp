#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

int T;
ull dp[100001][4];


int main() {
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int target;
		cin >> target;
		memset(dp, 0, sizeof(dp));
		dp[1][1] = 1;
		dp[2][2] = 1;
		dp[3][1] = 1;
		dp[3][2] = 1;
		dp[3][3] = 1;
		for (int i = 4; i <= target; i++) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
		}

		cout << (dp[target][1] + dp[target][2] + dp[target][3]) % 1000000009 << endl;

	}
	

	return 0;
}