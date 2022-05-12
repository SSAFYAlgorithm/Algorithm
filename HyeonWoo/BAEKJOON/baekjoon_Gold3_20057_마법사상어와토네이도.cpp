#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int map[550][550];

int res;

int dr[] = { 0,1,0,-1 };
int dc[] = { -1,0,1,0 };

int r, c;
int MaxCountArr[2000]; // 1,1,2,2,3,3,4,4,5,5,6,6 ... 
int MaxCountIdx = 0; // dir이 바뀔때마다 증가
int Count = 0;
int dir = 0;   // 0,1,2,3,0,1,2,3,0,1,2,3\

void Wind(int nr, int nc) {
	float nowSand = map[nr][nc];
	int PlusSand[5][5] = { 0 };
	if (dir == 0) {
		PlusSand[0][2] = (int)(nowSand * 0.02);
		PlusSand[1][1] = (int)(nowSand * 0.1);
		PlusSand[1][2] = (int)(nowSand * 0.07);
		PlusSand[1][3] = (int)(nowSand * 0.01);
		PlusSand[2][0] = (int)(nowSand * 0.05);
		PlusSand[3][1] = (int)(nowSand * 0.1);
		PlusSand[3][2] = (int)(nowSand * 0.07);
		PlusSand[3][3] = (int)(nowSand * 0.01);
		PlusSand[4][2] = (int)(nowSand * 0.02);
		PlusSand[2][1] = nowSand - PlusSand[0][2] - PlusSand[1][1] - PlusSand[1][2] - PlusSand[1][3] -
			PlusSand[2][0] - PlusSand[3][1] - PlusSand[3][2] - PlusSand[3][3] - PlusSand[4][2];
	}
	else if (dir == 1) {
		PlusSand[2][0] = (int)(nowSand * 0.02);
		PlusSand[3][1] = (int)(nowSand * 0.1);
		PlusSand[2][1] = (int)(nowSand * 0.07);
		PlusSand[1][1] = (int)(nowSand * 0.01);
		PlusSand[4][2] = (int)(nowSand * 0.05);
		PlusSand[3][3] = (int)(nowSand * 0.1);
		PlusSand[2][3] = (int)(nowSand * 0.07);
		PlusSand[1][3] = (int)(nowSand * 0.01);
		PlusSand[2][4] = (int)(nowSand * 0.02);
		PlusSand[3][2] = nowSand - PlusSand[2][0] - PlusSand[3][1] - PlusSand[2][1] - PlusSand[1][1] -
			PlusSand[3][3] - PlusSand[2][3] - PlusSand[1][3] - PlusSand[2][4] - PlusSand[4][2];
	}
	else if (dir == 2) {
		PlusSand[0][2] = (int)(nowSand * 0.02);
		PlusSand[1][3] = (int)(nowSand * 0.1);
		PlusSand[1][2] = (int)(nowSand * 0.07);
		PlusSand[1][1] = (int)(nowSand * 0.01);
		PlusSand[2][4] = (int)(nowSand * 0.05);
		PlusSand[3][3] = (int)(nowSand * 0.1);
		PlusSand[3][2] = (int)(nowSand * 0.07);
		PlusSand[3][1] = (int)(nowSand * 0.01);
		PlusSand[4][2] = (int)(nowSand * 0.02);
		PlusSand[2][3] = nowSand - PlusSand[0][2] - PlusSand[1][1] - PlusSand[1][2] - PlusSand[1][3] -
			PlusSand[2][4] - PlusSand[3][1] - PlusSand[3][2] - PlusSand[3][3] - PlusSand[4][2];
	}
	else if (dir == 3) {
		PlusSand[2][0] = (int)(nowSand * 0.02);
		PlusSand[1][1] = (int)(nowSand * 0.1);
		PlusSand[2][1] = (int)(nowSand * 0.07);
		PlusSand[3][1] = (int)(nowSand * 0.01);
		PlusSand[0][2] = (int)(nowSand * 0.05);
		PlusSand[1][3] = (int)(nowSand * 0.1);
		PlusSand[2][3] = (int)(nowSand * 0.07);
		PlusSand[3][3] = (int)(nowSand * 0.01);
		PlusSand[2][4] = (int)(nowSand * 0.02);
		PlusSand[1][2] = nowSand - PlusSand[2][0] - PlusSand[3][1] - PlusSand[2][1] - PlusSand[1][1] -
			PlusSand[3][3] - PlusSand[2][3] - PlusSand[1][3] - PlusSand[2][4] - PlusSand[0][2];
	}

	// map에 추가 y의 모든 모래가 비율과 α가 적혀있는 칸으로 이동한다. -> 해당칸 비어있게 된다.
	map[nr][nc] = 0;
	for (int y = -2; y <= 2; y++) {
		for (int x = -2; x <= 2; x++) {
			int ny = nr + y;
			int nx = nc + x;
			if (ny <= 0 || nx <= 0 || ny > N || nx > N) {
				res += PlusSand[y + 2][x + 2];
			}
			else {
				map[nr + y][nc + x] += PlusSand[y + 2][x + 2];
			}
		}
	}
}

void Move() {
	int MaxCount = MaxCountArr[MaxCountIdx];
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (nr < 0 || nc < 0) {
		int de = -1;
	}
	if (map[nr][nc] != 0) {
		Wind(nr, nc);
	}
	r = nr;
	c = nc;
	Count++;
	if (Count == MaxCount) {
		dir = (dir + 1) % 4;
		MaxCountIdx++;
		Count = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < 2000; i++) {
		MaxCountArr[i] = (i + 2) / 2;
	}

	r = (N+1) / 2;
	c = (N+1) / 2;

	

	while (1) {
		if (r == 1 && c == 1) break;
		Move();
	}

	cout << res;
	return 0;
}