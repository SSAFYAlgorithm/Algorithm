#include <iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int tri;
vector<deque<int>>deq;
int solve() {
	deq.clear();
	for (int i = 0;i < 4;i++) {
		deq.push_back(deque<int>());
		for (int j = 0;j < 8;j++) {
			int a;
			cin >> a;
			deq[i].push_back(a);
		}
	}

	for (int i = 0;i < tri;i++) {
		int n, direction;
		cin >> n >> direction;
		//n->오른쪽
		int right = n - 1;
		for (int j = 0;j < 4;j++) {
			if (n + j >= 4)break;
			if (deq[n - 1 + j][2] != deq[n + j][6]) {
				right = n + j;
			}
			else break;
		}
		//n<-왼쪽
		int left = n - 1;
		for (int j = 0;j < 4;j++) {
			if (n - j - 1 <= 0)break;
			if (deq[n - 1 - j][6] != deq[n - j - 2][2]) {
				left = n - 2 - j;
			}
			else break;
		}
		//현재 n-1
		//n-4 n-3 n-2 n-1 n n+1 n+2 
		//0   1   0   1   0  1  0
		//1   0   1   0   1  0  1
		int leftDirect;
		if ((n - 1 - left) % 2)leftDirect = -1 * direction;
		else leftDirect = direction;
		for (int j = left; j <= right;j++) {
			if (leftDirect == 1) {
				int now = deq[j].back();
				deq[j].pop_back();
				deq[j].push_front(now);
				leftDirect = -1;
			}
			else if (leftDirect == -1) {
				int now = deq[j].front();
				deq[j].pop_front();
				deq[j].push_back(now);
				leftDirect = 1;
			}

		}

	}
	int score = 0;
	for (int i = 0; i < 4;i++) {
		if (deq[i][0]) {
			score += pow(2, i);
		}
	}
	return score;
}


int main(void) {
	//freopen("input.txt", "r", stdin);
	int test;
	cin >> test;
	for (int t = 1;t <= test;t++) {
		cin >> tri;
		cout << "#" << t << " " << solve() << endl;
	}
}