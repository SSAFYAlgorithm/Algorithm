#include <iostream>
using namespace std;

int dp[10001];
int coins[101];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		cin >> coins[i];
	}
	for (int i = 0;i < n;i++)
	{
		if (coins[i] > 10000)
		{
			continue;
		}
		dp[coins[i]]++;
		for (int j = 1;j <= k;j++)
		{
			if (j - coins[i] >= 0)
			{
				dp[j] = dp[j - coins[i]] + dp[j];
			}
		}
	}
	cout << dp[k];


	return 0;
}