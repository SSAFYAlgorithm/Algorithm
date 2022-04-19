#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int R, C, T;
struct Node {
	int y, x;
};

struct DUST {
	int y, x, amount;
};
int map[55][55];
vector <Node> AC; // 위에서부터 입력하니까 0번인덱스는 top, 1번인덱스는 bottom
queue <DUST> dust;
vector <DUST> tempdust;
int dy[] = { -1,1,0,0 }; // top : 우 상 좌 하
int dx[] = { 0,0,-1,1 }; // bottom : 우 하 좌 상
int res;


void WhereDust() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] > 0) {
				dust.push({ y,x,map[y][x] });
			}
		}
	}
}

void diffusion() {
	int tempMap[55][55] = {0};
	tempMap[AC[0].y][AC[0].x] = -1;
	tempMap[AC[1].y][AC[1].x] = -1;
	while (!dust.empty()) {
		int nowy = dust.front().y;
		int nowx = dust.front().x;
		int nowAmount = dust.front().amount;
		dust.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int newy = nowy + dy[i];
			int newx = nowx + dx[i];
			if (newy < 0 || newx < 0 || newy >= R || newx >= C) continue;
			if (map[newy][newx] == -1) continue;
			int newAmount = nowAmount / 5;
			cnt++; // 몇군데나 확산했나.
			tempMap[newy][newx] += newAmount;
		}
		// nowAmount도 계산
		nowAmount = nowAmount - (nowAmount / 5) * cnt;
		tempMap[nowy][nowx] += nowAmount;
	}
	memcpy(map, tempMap, sizeof(map));
}

void TopClean(int yy, int xx) {
	int TempMap[55][55] = { 0 };
	memcpy(TempMap, map, sizeof(map));

	// 아래줄부터
	for (int x = C - 1; x >= xx+2; x--) {
		TempMap[yy][x] = map[yy][x - 1];
	}
	TempMap[yy][xx + 1] = 0;
	// 오른쪽
	for (int y = 0; y <= yy - 1; y++) {
		TempMap[y][C - 1] = map[y + 1][C - 1];
	}
	// 위쪽
	for (int x = 0; x < C - 1; x++) {
		TempMap[0][x] = map[0][x + 1];
	}
	// 왼쪽
	for (int y = yy-1; y >= 1; y--) {
		TempMap[y][0] = map[y-1][0];
	}
	memcpy(map, TempMap, sizeof(map));
}

void BotClean(int yy, int xx) {
	int TempMap[55][55] = { 0 };
	memcpy(TempMap, map, sizeof(map));

	// 위쪽
	for (int x = C - 1; x >= xx + 2; x--) {
		TempMap[yy][x] = map[yy][x - 1];
	}
	TempMap[yy][xx + 1] = 0;
	// 오른쪽
	for (int y = yy; y < R-1; y++) {
		TempMap[y+1][C - 1] = map[y][C - 1];
	}
	// 아래쪽
	for (int x = C-2; x >= xx; x--) {
		TempMap[R-1][x] = map[R-1][x+1];
	}
	// 왼쪽
	for (int y = R-2; y >= yy+1; y--) {
		TempMap[y][xx] = map[y+1][xx];
	}
	memcpy(map, TempMap, sizeof(map));
}

void Clean() {
	Node TopAC = AC[0];
	Node BotAC = AC[1];

	// 탑부분은 반시계방향 회전
	TopClean(AC[0].y, AC[0].x);
	BotClean(AC[1].y, AC[1].x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> R >> C >> T;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
			if (map[y][x] == -1) {
				AC.push_back({ y,x });
			}
		}
	}


	for (int t = 1; t <= T; t++) {
		WhereDust();
		diffusion();
		Clean();
	}

	
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == -1 || map[y][x] == 0) continue;
			res += map[y][x];
		}
	}
	cout << res;

	return 0;
}