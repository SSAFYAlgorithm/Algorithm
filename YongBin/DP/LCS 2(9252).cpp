#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1001][1001];
string dp2[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int size1 = s1.length();
	int size2 = s2.length();

	for (int i = 1; i <= size1; i++){
		for (int j = 1; j <= size2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				dp2[i][j] = dp2[i - 1][j - 1] + s1[i - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (dp2[i - 1][j].length() > dp2[i][j - 1].length())
					dp2[i][j] = dp2[i - 1][j];
				else
					dp2[i][j] = dp2[i][j - 1];
			}
		}
	}
	if (dp[size1][size2] == 0) {
		cout << dp[size1][size2] << "\n";
		return 0;
	}
	cout << dp[size1][size2] << "\n";
	cout << dp2[size1][size2] << "\n";

	return 0;
}