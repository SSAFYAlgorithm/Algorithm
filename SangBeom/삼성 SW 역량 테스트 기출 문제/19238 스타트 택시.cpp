#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int sx, sy;
struct Person {
	int sr, sc, er, ec;
	int flag;
};
struct Taxi {
	int r, c, cnt;
};
int N, M, K;
int MAP[21][21];
vector<Person>vect;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool cmp(pair<int, int>left, pair<int, int>right) {
	if (left.first < right.first)return 1;
	if (left.first > right.first)return 0;
	return left.second < right.second;
}
int findPerson() {
	int visited[21][21] = { 0 };
	visited[sx][sy] = 1;
	if (MAP[sx][sy] == 2) {
		for (int i = 0;i < vect.size();i++) {
			if (vect[i].sr == sx && vect[i].sc == sy) {
				if (vect[i].flag == 1)continue;
				MAP[sx][sy] = 0;
				return i;
			}
		}
	}
	queue<Taxi>que;
	que.push({ sx,sy,0 });

	int minValue = 500;
	vector<pair<int, int>>f;
	while (!que.empty()) {
		Taxi now = que.front();que.pop();
		if (MAP[now.r][now.c] == 2) {
			int de = -1;
			if (now.cnt < minValue) {
				f.clear();
				minValue = now.cnt;
				f.push_back(make_pair(now.r, now.c));
			}
			else if (now.cnt == minValue) {
				f.push_back(make_pair(now.r, now.c));
			}
		}
		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.r;
			int ty = dy[i] + now.c;
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			if (visited[tx][ty])continue;
			if (MAP[tx][ty] == 1)continue;
			visited[tx][ty] = 1;
			que.push({ tx,ty,now.cnt + 1 });
		}
	}
	if (!f.size())return -1;
	K -= minValue;
	if (K < 0)return -1;
	sort(f.begin(), f.end(), cmp);
	sx = f[0].first;
	sy = f[0].second;
	MAP[sx][sy] = 0;
	for (int i = 0;i < vect.size();i++) {
		if (vect[i].sr == sx && vect[i].sc == sy) {
			if (vect[i].flag == 1)continue;
			return i;
		}
	}
}
int movePerson(int x)
{
	int visited[21][21] = { 0 };
	visited[vect[x].sr][vect[x].sc] = 1;
	queue<Taxi>que;
	que.push({ vect[x].sr,vect[x].sc,0 });
	while (!que.empty())
	{
		Taxi now = que.front();que.pop();
		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.r;
			int ty = dy[i] + now.c;
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			if (visited[tx][ty])continue;
			if (MAP[tx][ty] == 1)continue;
			visited[tx][ty] = 1;
			if (tx == vect[x].er && ty == vect[x].ec) {
				vect[x].flag = 1;
				sx = tx;sy = ty;
				return now.cnt + 1;
			}
			que.push({ tx,ty,now.cnt + 1 });
		}
	}
	return -1;
}
void solve()
{
	while (1) {
		int stop = 0;
		int now = findPerson();
		if (now == -1) {
			cout << -1;
			return;
		}
		else {
			int sec = movePerson(now);
			if (sec == -1) {
				cout << -1;
				return;
			}
			else {
				K -= sec;
				if (K < 0) {
					cout << -1;
					return;
				}
				else {
					K += (sec * 2);
				}
			}
		}
		for (int i = 0;i < vect.size();i++) {
			if (!vect[i].flag) {
				stop = 1;
				break;
			}
		}
		if (!stop)break;

	}
	cout << K;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> sx >> sy;
	sx -= 1;
	sy -= 1;
	for (int i = 0;i < M;i++) {
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;
		vect.push_back({ sr - 1,sc - 1,er - 1,ec - 1,0 });
		if (MAP[sr - 1][sc - 1] == 0) {
			MAP[sr - 1][sc - 1] = 2;
		}

	}
	solve();
}