#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	deque<pair<int,int>> deq;
	int N, M;
	for (int i = 0;i < n;i++) {
		int dat[10] = {0};
		int a;
		int cnt = 1;
		cin >> N>> M;
		for (int j = 0;j < N;j++) {
			cin >> a;
			dat[a]++;
			deq.push_back(pair<int, int>(a, j));
		}

		for (int k = 9;k >= 1;k--) {
			if (dat[k] != 0) {
				while (dat[k]!=0)
				{
					if (deq.front().first == k) {
						if (deq.front().second == M) {
							cout << cnt << '\n';
							break;
						}
						else {
							deq.pop_front();
							dat[k]--;
							cnt++;
						}
					}
					else {
						int temp = deq.front().first;
						int temp2 = deq.front().second;
						deq.pop_front();
						deq.push_back(pair<int,int>(temp,temp2));
					}
				}
			}
		}
		deq.clear();
		
	}
	
}
