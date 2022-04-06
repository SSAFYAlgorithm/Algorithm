#include <iostream>
#include <vector>

using namespace std;
int N;
vector<pair<int, int>>vect;
int dp[20] = { 0 };
void solve()
{
	for (int i = N - 1;i >= 0;i--) {
		if (vect[i].first + i > N) {
			dp[i] = dp[i + 1];
		}
		else {
			if (vect[i].first >= 2) {
				if (dp[vect[i].first + i] + vect[i].second > dp[i + 1]) {
					dp[i] = dp[vect[i].first + i] + vect[i].second;
				}
				else {
					dp[i] = dp[i + 1];
				}
			}
			else if (vect[i].first == 1) {
				dp[i] = dp[i + 1] + vect[i].second;
			}
		}

	}
}

int main()
{
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		vect.push_back(pair<int, int>(a, b));
	}
	solve();

	cout << dp[0];

}