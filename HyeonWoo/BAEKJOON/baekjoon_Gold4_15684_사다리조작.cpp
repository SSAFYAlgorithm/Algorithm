#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, H;
int line[300][15];
int flag; // 플레이결과 성공했는지 확인
//int Debug[300][15]; // 디버깅떄문에 만들어줌
struct Node {
	int y;
	int x;
};

int play() {
	for (int x = 1; x <= N; x++) {
		//memset(Debug, 0, sizeof(Debug));
		int nowy = 1;
		int nowx = x;
		while (nowy <= H+1) {
			//Debug[nowy][nowx] = 9;
			if (line[nowy][nowx] == 1) { // 오른쪽으로 갈수있다.
				nowx++;
				//Debug[nowy][nowx] = 9;
			}
			else if (line[nowy][nowx] == 2) { //왼쪽으로갈수있다.
				nowx--;
				//Debug[nowy][nowx] = 9;
			}
			nowy++;
		}
		if (nowx != x) {
			return 0;
		}
	}
	return 1;
}

// dfs로 어디에 사다리를 놓을지 결정 1부터 시작해서 N-1까지 무조건 오른쪽을 놓을것이다.
void dfs(int level, int MAXcnt, int lasty, int lastx) { // cnt는 최대 몇개까지 추가할지
	if (level == MAXcnt) {
		if (play()) {// play결과 성공했다면?
			flag = 1;
		}
		return;
	}
	if (flag) return; // 이미 성공했으면 게임할 필요가없다.

	for(int y=lasty; y<=H; y++){// 이전 아래 있던거는 할 필요가 없다.
		int start = 1;
		if (y == lasty) start = lastx;
		for (int x = start; x <= N-1; x++) {
			if (line[y][x] != 0) continue;
			if (line[y][x + 1] != 0) continue; // 연속해서 사다리가 만들어져도 안된다.
			line[y][x] = 1;
			line[y][x + 1] = 2;
			dfs(level + 1, MAXcnt, y, x);
			line[y][x] = 0;
			line[y][x + 1] = 0;
		}
	}
}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		line[a][b] = 1; // 1이면 오른쪽으로갈수있다.
		line[a][b+1] = 2; // 2이면 왼쪽으로 갈수있다.
	}

	int MAXLEDDER = 3; // 최대로 놓을 수 있는 사다리 개수
	int NowLedder = 0;
	while (NowLedder <= MAXLEDDER) {
		dfs(0, NowLedder, 1, 1);
		if (flag) break;
		NowLedder++;
	}

	if (!flag) {
		cout << -1;
	}
	else {
		cout << NowLedder;
	}
	
	return 0;
}