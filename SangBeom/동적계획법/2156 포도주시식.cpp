#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[10001];
int main(void) {
	int n;
	cin >> n;
	vector<int>vect;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		vect.push_back(a);
	}
	dp[0] = vect[0];
	dp[1] = vect[0] + vect[1];
	int t = max(vect[0] + vect[1], vect[0] + vect[2]);
	dp[2] = max(vect[1] + vect[2], t);
	for (int i = 3;i < n;i++) {
		int tmp = max(dp[i - 3] + vect[i] + vect[i - 1], dp[i - 2] + vect[i]);
		dp[i] = max(tmp, dp[i - 1]);

	}
	cout << dp[n - 1];
}