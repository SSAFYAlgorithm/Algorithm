#include <iostream>
#include <vector>
using namespace std;

int N, K;

int MaxSize;
int arr[15][15];
vector <int> info[15][15];
int res;
struct Node {
	int y;
	int x;
	int dir;
};
Node NumPlace[12]; // 각 인덱스별 노드 위치

int dy[] = { 0, 0,0,-1,1 };
int dx[] = { 0,1,-1,0,0 };


void White(int y,int x,int ny, int nx, int i) {
	// 해당 vector위치에서 i ~ .size() 까지 담겨진 값들을 순차적으로 옮김
	int flag = 0;
	int PopCnt = 0;
	for (int j = 0; j < info[y][x].size(); j++) {
		if (info[y][x][j] == i) {
			flag = 1;
		}
		if (flag) {
			PopCnt++;
			info[ny][nx].push_back(info[y][x][j]);
			NumPlace[info[y][x][j]] = { ny,nx,NumPlace[info[y][x][j]].dir };
		}
	}
	for (int j = 0; j < PopCnt; j++) {
		info[y][x].pop_back();
	}
}

void Red(int y, int x, int ny, int nx, int i) {
	vector <int> RevInfo;
	for (int j = info[y][x].size() - 1; j >= 0; j--) {
		RevInfo.push_back(info[y][x][j]);
		NumPlace[info[y][x][j]] = { ny,nx,NumPlace[info[y][x][j]].dir };
		if (info[y][x][j] == i) {
			break;
		}
	}
	for (int j = 0; j < RevInfo.size(); j++) {
		info[y][x].pop_back();
	}
	for (int j = 0; j < RevInfo.size(); j++) {
		info[ny][nx].push_back(RevInfo[j]);

	}
}

// 가장 아래에 있는 말만 움직일 수 있다.
void Move() {
	while (1) {
		MaxSize = 0;
		for (int i = 1; i <= K; i++) {
			int y = NumPlace[i].y;
			int x = NumPlace[i].x;
			int dir = NumPlace[i].dir;

			if (info[y][x][0] != i) continue;

			int ny = y + dy[dir];
			int nx = x + dx[dir];
			// 파란색
			if (ny <= 0 || nx <= 0 || ny > N || nx > N || arr[ny][nx] == 2) {
				if (dir == 1 || dir == 3) {
					dir++;
				}
				else {
					dir--;
				}
				ny = y + dy[dir];
				nx = x + dx[dir];
				if (ny <- 0 || nx <= 0 || ny > N || nx > N || arr[ny][nx] == 2) {
					ny = y;
					nx = x;
				}
				else if (arr[ny][nx] == 0) {
					NumPlace[i].dir = dir;
					White(y, x, ny, nx, i);
				}
				else if (arr[ny][nx] == 1) {
					NumPlace[i].dir = dir;
					Red(y, x, ny, nx, i);
				}

			}

			// 흰색
			else if (arr[ny][nx] == 0) {
				White(y, x, ny, nx, i);
			}
			// 빨간색
			else if (arr[ny][nx] == 1) {
				Red(y, x, ny, nx, i);
			}
			MaxSize = max(MaxSize, (int)info[ny][nx].size());
			NumPlace[i] = { ny,nx,dir };
			int de = -1;
		}
		res++;
		if (MaxSize >= 4) break;
		if (res > 1000) {
			res = -1;
			break;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	int startflag = 0;

	for (int i = 1; i <= K; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		info[r][c].push_back(i);
		NumPlace[i] = { r,c, dir };
		if (info[r][c].size() >= 4) startflag = 1;
	}
	if (startflag) {
		cout << 0 << endl;
		return 0;
	}
	Move();
	cout << res;
	return 0;
}