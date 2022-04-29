#include<iostream>
#include<queue>
using namespace std;

int N, M, T;
struct Node {
	int num;
	int flag;
};
vector<deque<Node>>deq;
int x, d, k;
void rotate()
{
	for (int i = x - 1; i < N;i += x) {
		for (int j = 0;j < k;j++) {
			if (d == 0) {//½Ã°è
				Node temp = deq[i].back();
				deq[i].pop_back();
				deq[i].push_front(temp);
			}
			else {
				Node temp = deq[i].front();
				deq[i].pop_front();
				deq[i].push_back(temp);
			}

		}
	}
}
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
void eraseFlag() {


	int indexflag = 1;
	for (int i = 0;i < N;i++) {
		if (deq[i][0].flag != -1 && deq[i][M - 1].flag != -1) {
			if (deq[i][0].num == deq[i][M - 1].num) {
				deq[i][0].flag = 0;
				deq[i][M - 1].flag = 0;
				indexflag = 0;
			}

		}
		for (int j = 0;j < M;j++) {
			if (deq[i][j].flag == -1)continue;
			for (int k = 0;k < 4;k++) {
				int tx = dx[k] + i;
				int ty = dy[k] + j;
				if (tx < 0 || tx >= N || ty < 0 || ty >= M)continue;
				if (deq[tx][ty].flag == -1)continue;
				if (deq[tx][ty].num == deq[i][j].num) {
					deq[i][j].flag = 0;
					indexflag = 0;
				}
			}
		}

	}
	if (indexflag) {
		double sum = 0;
		double cnt = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (deq[i][j].flag == 1) {
					sum += deq[i][j].num;
					cnt += 1;
				}
			}
		}
		double avg = sum / cnt;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (deq[i][j].flag == 1) {
					if (deq[i][j].num > avg) {
						deq[i][j].num--;
					}
					else if (deq[i][j].num < avg) {
						deq[i][j].num++;
					}

				}
			}
		}
	}

}
void eraseNum()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (deq[i][j].flag == 0) {
				deq[i][j].flag = -1;
			}
		}
	}
}
void solve()
{
	for (int t = 0;t < T;t++) {
		cin >> x >> d >> k;
		k = k % M;
		rotate();
		eraseFlag();
		eraseNum();
	}
	int res = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (deq[i][j].flag == 1) {
				res += deq[i][j].num;
			}
		}
	}
	cout << res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> T;
	for (int i = 0;i < N;i++) {
		deq.push_back(deque<Node>());
		for (int j = 0;j < M;j++) {
			int a;
			cin >> a;
			deq[i].push_back({ a,1 });
		}
	}
	solve();

}