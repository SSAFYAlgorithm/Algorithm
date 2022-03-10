#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long> dp;
vector<int> input;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
    int maxnum = 0;
	cin >> n;
    
	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(1);
	dp.push_back(1);
	dp.push_back(2);
	dp.push_back(2);
	dp.push_back(3);
	dp.push_back(4);
	dp.push_back(5);
	dp.push_back(7);
	dp.push_back(9);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		input.push_back(a);
		if (a > maxnum) maxnum = a;
	}

	for (int i = 11; i <= maxnum; i++) {
		dp.push_back(dp[i-1] + dp[i-5]);
	}
	for (int i = 0; i < n; i++) {
		cout << dp[input[i]] << "\n";
	}

	return 0;
}