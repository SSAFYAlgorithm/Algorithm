#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int arr[10][10];
int tempArr[10][10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int res = 0;
struct Node {
	int y;
	int x;
};

vector <Node> VirusPlace;
queue < Node > q;
void Virus() {
	q = queue <Node>();
	memcpy(tempArr, arr, sizeof(tempArr));
	for (int i = 0; i < VirusPlace.size(); i++) {
		q.push(VirusPlace[i]);
	}

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (tempArr[ny][nx] != 0) continue;
			tempArr[ny][nx] = 2;
			q.push({ ny,nx });
		}
	}

}

void CountSafePlace() {
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (tempArr[y][x] == 0) {
				cnt++;
			}
		}
	}

	if (cnt > res) {
		res = cnt;
	}
}

void DFS(int cnt) {
	if (cnt == 3) {// 3개 모두 세웠다면 바이러스 퍼뜨려봄
		Virus();
		CountSafePlace();
		return;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] != 0) continue;
			arr[y][x] = 1;
			DFS(cnt + 1);
			arr[y][x] = 0;
		}
	}
	
}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				VirusPlace.push_back({ i,j });
			}
		}
	}
	// DFS로 벽 위치 3개씩 전부 만들어본다
	DFS(0);

	cout << res;

	return 0;
}