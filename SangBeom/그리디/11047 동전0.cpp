#include<iostream>
#include<vector>
using namespace std;
/*
1 100000000
1
ans:100000
1 1000
1000
*/
vector<int>coin;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		coin.push_back(num);
	}

	int cnt = 0;
	if (coin[N - 1] <= K) {
		cnt = cnt + (K / coin[N - 1]);
		K = K % coin[N - 1];
	}
	while (K)
	{
		for (int i = 0;i < N;i++) {

			if (coin[i] > K) {
				cnt = cnt + (K / coin[i - 1]);
				K = K % coin[i - 1];
				break;
			}
		}
	}
	cout << cnt;

}