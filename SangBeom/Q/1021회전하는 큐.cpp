#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
		
	deque<int> deqLeft;
	deque<int> deqRight;
	vector<int>positionNum;
	int n,m;
	cin >> n>> m;
	int a;
	for (int i = 1;i <= n;i++) {
		deqLeft.push_back(i);
		deqRight.push_back(i);
	}

	for (int i = 0;i < m;i++) {
		cin >> a;
		positionNum.push_back(a);
	}
	int cnt = 0;
	int cntLeft = 0;
	int cntRight = 0;
	for (int i = 0;i < m;i++) {
		while (1)
		{
			int left = deqLeft.front();
			int right = deqRight.back();
			if (left == positionNum[i]) {
				deqLeft.pop_front();
				break;
			}
			else {
				deqLeft.push_back(left);
				deqLeft.pop_front();
				cntLeft++;
			}
			if (right == positionNum[i]) {
				deqRight.pop_back();
				break;
			}
			else {
				deqRight.push_front(right);
				deqRight.pop_back();
				cntRight++;
			}
		}
		if (cntRight+1 > cntLeft) {
			cnt += cntLeft;
			deqRight = deqLeft;
		}
		else {
			cnt = cnt + cntRight + 1;
			deqLeft = deqRight;
		}
		cntLeft = 0;
		cntRight = 0;
	}
	cout << cnt;
}
