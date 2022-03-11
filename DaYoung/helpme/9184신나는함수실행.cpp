#include<iostream>
#include<vector>
using namespace std;

struct abc {
	int wa, wb, wc;
};
vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21,0)));
vector<abc> input;

int main()
{
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		input.push_back({ a, b, c });
	}
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 1;
				if (dp[i][j][k]) continue;
				dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
			}
		}
	}
	for(int i=0;i<input.size();i++) {
		abc now =input[i];
		cout << "w(" << now.wa << ", " << now.wb << ", " << now.wc << ") = ";
		int a = now.wa;
		int b = now.wb;
		int c = now.wc;
		if (a < 0) a = 0;
		else if (a > 20) a = 20;
		if (b < 0) b = 0;
		else if (b > 20) b = 20;
		if (c < 0) c = 0;
		else if (c > 20)c = 20;
		cout << dp[a][b][c] << "\n";
	}

	return 0;
}