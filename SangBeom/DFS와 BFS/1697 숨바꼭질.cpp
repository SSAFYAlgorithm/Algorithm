#include<iostream>
#include<queue>

using namespace std;
int arr[200001] = { 0 };
int cnt[200001] = { 0 };
int main()
{
	int N, K;
	cin >> N >> K;
	arr[N] = 1;
	queue<int> que;
	que.push(N);
	while (1)
	{
		if (que.empty()) break;
		int position = que.front();
		arr[position] = 1;
		que.pop();
		if (position - 1 >= 0) {
			if (arr[position - 1] == 0 && cnt[position - 1] == 0) {
				cnt[position - 1] = cnt[position] + 1;
				if (position - 1 == K) break;
				que.push(position - 1);
			}
		}
		if (position + 1 <= 100000) {
			if (arr[position + 1] == 0 && cnt[position + 1] == 0) {
				cnt[position + 1] = cnt[position] + 1;
				if (position + 1 == K) break;
				que.push(position + 1);
			}
		}
		if (position * 2 <= 100000) {
			if (arr[position * 2] == 0 && cnt[position * 2] == 0) {
				cnt[position * 2] = cnt[position] + 1;
				if (position * 2 == K) break;
				que.push(position * 2);
			}
		}
	}
	cout << cnt[K];


}