#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
string MAP[53];
int Distance[53][53];
int res = 0;
struct Node {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	//보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}

	//for문으로 탐색하다가 만약 MAP[y][x] = 'L' 이면 BFS탐색 -> 최대 거리 구한다
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (MAP[y][x] == 'L') {
				//BFS시작
				memset(Distance, 0, sizeof(Distance));
				int MAX = 0;
				queue <Node> q;
				q.push({ y,x });
				Distance[y][x] = 0;
				int initY = y;
				int initX = x;
				while (!q.empty()) {
					int nowY = q.front().y;
					int nowX = q.front().x;
					if (Distance[nowY][nowX] > MAX && (nowY != initY || nowX != initX)) MAX = Distance[nowY][nowX];
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nextY = nowY + dy[i];
						int nextX = nowX + dx[i];
						if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)continue;
						if (MAP[nextY][nextX] != 'L') continue;
						if (Distance[nextY][nextX] != 0) continue;
						q.push({ nextY,nextX });
						Distance[nextY][nextX] = Distance[nowY][nowX] + 1;
					}
				}
				if (MAX > res) {
					res = MAX;
				}

			}
		}
	}

	cout << res;

	return 0;
}