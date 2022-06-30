#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
struct Shark {
	int r, c, dir, life;
};
int N, M, K;
pair<int, int> MAP[21][21];  //num,smell
pair<int, int>temp[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<Shark>shark;
int sharkdir[401][4][4];

void priority2(Shark now, int num)
{
	for (int i = 0;i < 4;i++) {
		int tx = dx[sharkdir[num][now.dir][i]] + now.r;
		int ty = dy[sharkdir[num][now.dir][i]] + now.c;
		if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
		if (MAP[tx][ty].second)continue;
		if (temp[tx][ty].second == K && temp[tx][ty].first < num) {
			shark[num].life = -1;
			return;
		}
		shark[num].r = tx; shark[num].c = ty; shark[num].dir = sharkdir[num][now.dir][i];
		temp[tx][ty].first = num; temp[tx][ty].second = K;
		return;

	}
}
void priority3(Shark now, int num)
{
	for (int i = 0;i < 4;i++) {
		int tx = dx[sharkdir[num][now.dir][i]] + now.r;
		int ty = dy[sharkdir[num][now.dir][i]] + now.c;
		if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
		if (MAP[tx][ty].first != num)continue;
		if (temp[tx][ty].second == K && temp[tx][ty].first < num) {
			shark[num].life = -1;
			return;
		}
		shark[num].r = tx; shark[num].c = ty; shark[num].dir = sharkdir[num][now.dir][i];
		temp[tx][ty].first = num; temp[tx][ty].second = K;
		return;
	}
}
void findway()
{
	for (int i = 1;i <= M;i++) {
		if (shark[i].life == -1)continue;
		Shark now = shark[i];
		int cnt = 0;
		for (int j = 0;j < 4;j++) {
			int tx = now.r + dx[j];
			int ty = now.c + dy[j];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			if (!MAP[tx][ty].second)cnt++;
		}

		if (cnt) {
			priority2(now, i);
		}
		else if (cnt == 0) {
			priority3(now, i);
		}
	}
}
void eraseSmell()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j].second)MAP[i][j].second--;
			if (!MAP[i][j].second)MAP[i][j].first = 0;
		}
	}
}
void sync()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (temp[i][j].second == K) {
				MAP[i][j].first = temp[i][j].first;
				MAP[i][j].second = temp[i][j].second;
			}
		}
	}
	memset(temp, 0, sizeof(temp));
}
void solve()
{
	int ans;
	for (int t = 0;t < 1000;t++) {
		eraseSmell();
		findway();
		sync();
		int flag = 0;
		for (int i = 2;i <= M;i++) {
			if (shark[i].life == 0) {
				flag = 1;break;
			}
		}
		if (!flag) {
			cout << t + 1;
			return;
		}
	}
	cout << -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	K += 1;
	for (int i = 0;i <= M;i++) {
		shark.push_back({});
	}
	shark[0].life = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j].first;
			if (MAP[i][j].first) {
				shark[MAP[i][j].first] = { i,j,0,0 };
				MAP[i][j].second = K;
			}
		}
	}
	for (int i = 1;i <= M;i++) {
		int d;cin >> d;
		shark[i].dir = d - 1;
	}
	for (int i = 1;i <= M;i++) {
		for (int j = 0;j < 4;j++) {
			for (int k = 0;k < 4;k++) {
				cin >> sharkdir[i][j][k];
				sharkdir[i][j][k]--;
			}
		}
	}
	solve();
}