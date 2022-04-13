#include<iostream>
#include<string>
using namespace std;


// 121074110
// ans :2


int main()
{
	string str;
	cin >> str;
	int len = str.length();
	if (str[0] == '0') {
		cout << 0;
		return 0;
	}
	int dp[5001] = { 0 };
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2;i <= len;i++) {
		if (str[i - 1] > '0')dp[i] = dp[i - 1] % 1000000;
		int n = (str[i - 2] - '0') * 10 + str[i - 1] - '0';
		if (10 <= n && 26 >= n) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}
	cout << dp[len];
}