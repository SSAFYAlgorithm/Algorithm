#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[110][110];
int N;
// 우 상 좌 하
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
struct Info {
	int x, y, d, g;
};


vector <Info> info;
vector <int> direction;

void draw(int sy, int sx) {
	int y = sy;
	int x = sx;
	arr[y][x] = 1;
	for (int i = 0; i < direction.size(); i++) {
		int ny = y + dy[direction[i]];
		int nx = x + dx[direction[i]];
		arr[ny][nx] = 1;
		y = ny;
		x = nx;
	}
}

void Type(int sy, int sx, int dir, int gen) {
	direction = vector <int>();

	int nowgen = 0;
	while (nowgen <= gen) {
		if (nowgen == 0) {
			direction.push_back(dir);
		}
		else if (nowgen == 1) {
			direction.push_back((dir + 1) % 4);
		}
		else { // 2세대 이후부터는 앞에 절반은 방향반전, 뒤의 절반은 그대로
			int Len = direction.size();
			// 앞의 절반
			for (int i = 0; i < Len; i++) {
				if (i < Len / 2) {
					direction.push_back((direction[i] + 2) % 4);
				}
				else {
					direction.push_back(direction[i]);
				}
			}

		}
		nowgen++;
	}

	// 그림그리자
	draw(sy, sx);
}

int Count() {
	int res = 0;
	for (int y = 0; y <= 99; y++) {
		for (int x = 0; x <= 99; x++) {
			if (arr[y][x] == 1 && arr[y + 1][x] == 1 && arr[y][x + 1] == 1 && arr[y + 1][x + 1] == 1)
				res++;
		}
	}
	return res;
}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		info.push_back({ x,y,d,g });
	}

	// 그림을 그려봅시당
	for (int i = 0; i < N; i++) {
		int x = info[i].x;
		int y = info[i].y;
		int dir = info[i].d;
		int gen = info[i].g;
		Type(y, x, dir, gen);
	}

	// 정사각형 개수세기
	cout << Count();
	
	


	return 0;
}