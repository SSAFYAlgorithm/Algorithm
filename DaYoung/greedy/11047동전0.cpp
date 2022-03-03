#include<iostream>
#include<queue>
using namespace std;

int n, k;
priority_queue<int> pq;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int won;
		cin >> won;
		pq.push(won);
	}
	int cnt = 0;
	while (1) {
		if (k == 0) break;
		int now = pq.top();
		cnt += (k / now);
		k %= now;
		pq.pop();
	}

	cout << cnt;

	return 0;
}