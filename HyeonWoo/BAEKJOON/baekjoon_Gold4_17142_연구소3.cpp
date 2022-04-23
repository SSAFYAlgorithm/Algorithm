#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[51][51];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int totflag; // 모든 맵을 채웠는지
int res = 21e8;
struct Node {
	int y, x;
};

vector <Node> CanVirus;
vector <Node> path;

void bfs() {
	int tempMap[51][51];
	int Count[51][51]={0};
	int flag = 0;
	memcpy(tempMap, map, sizeof(map));
	for (int i = 0; i < CanVirus.size(); i++) {
		int y = CanVirus[i].y;
		int x = CanVirus[i].x;
	}

	queue <Node> q;
	for (int i = 0; i < path.size(); i++) {
		int y = path[i].y;
		int x = path[i].x;
		tempMap[y][x] = 2;
		Count[y][x] = -1;
		q.push({ y,x });
	}

	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (Count[ny][nx] != 0) continue;
			if (tempMap[ny][nx] == 1) continue;
			if (Count[y][x] == -1) {
				Count[ny][nx] = 1;
			}
			else {
				Count[ny][nx] = Count[y][x] + 1;
			}
			q.push({ ny,nx });
		}
	}

	 //다채웠나 확인
	int MAX = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (tempMap[y][x] == 1) continue;
			if (tempMap[y][x] == 2) continue;
			if (Count[y][x] == 0) {
				flag = 1;
				break;
			}
			if (Count[y][x] > MAX) {
				MAX = Count[y][x];
			}
		}
	}


	if (MAX < res && flag == 0) {
		res = MAX;
	}

	if (!flag) {
		totflag = 1; // 한개라도 되니까 tot갱신
	}
}

void dfs(int level, int lastI) {
	if (level == M) {
		// M개만큼 넣을곳을 정했다면 BFS로 파이러스 퍼뜨려봄
		bfs();
		
		return;
	}

	for (int i = lastI+1; i < CanVirus.size(); i++) {
		path.push_back(CanVirus[i]);
		dfs(level + 1, i);
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				CanVirus.push_back({ i,j });
			}
		}
	}

	dfs(0,-1);
	if (totflag == 0) {
		cout << -1;
	}
	else {
		if (res == 21e8) {
			cout << 0;
		}
		else {
			cout << res;
		}
	}

	return 0;
}