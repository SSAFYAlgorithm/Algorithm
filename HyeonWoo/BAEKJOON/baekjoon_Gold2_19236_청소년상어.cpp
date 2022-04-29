#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[] = {9,-1,-1,0,1,1,1,0,-1}; // 반시계순 //  ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dx[] = {9,0,-1,-1,-1,0,1,1,1};

int MAP[5][5];
int InitMAP[5][5];
int res = 0;
int ans = 0;
struct Node {
	int y, x, dir;
};

Node direction[17]; // 현재 물고기가 무슨방향인지 shark = 0번

// 작은 물고기부터 순서대로 이동
// 물고기는 한 칸을 이동할 수 있고, 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸, 
// 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.
// 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전
// 이동할 수 있는 칸이 없으면 이동을 하지 않는다.
// 물고기가 다른 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꾸는 방식
void dfs(int sy, int sx, int sdir);

void MoveFish() {
	for (int n = 1; n <= 16; n++) {
		if (direction[n].dir == -1) continue;
		int dir = direction[n].dir;
		int y = direction[n].y;
		int x = direction[n].x;
		for (int i = 0; i < 8; i++) {
			int Newdir = dir + i;
			if (Newdir > 8) {
				Newdir -= 8;
			}
			int ny = y + dy[Newdir];
			int nx = x + dx[Newdir];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (MAP[ny][nx] == -1) continue;
			// 물고기이건 빈칸이건 어차피 스왑
			int TargetFish = MAP[ny][nx];
			swap(MAP[y][x] , MAP[ny][nx]);
			direction[n] = { ny,nx,Newdir };
			if (direction[0].y == 0) {
				int de = -1;
			}
			if (TargetFish != 0) {
				int TargetFishDir = direction[TargetFish].dir;
				direction[TargetFish] = { y,x,TargetFishDir };
			}
			break;
		}
	}
	// 움직임 끝났으면 샤크로 돌아가기
	dfs(direction[0].y, direction[0].x, direction[0].dir);
}

vector <Node> path;// 상어가 이동가능한 경로를 기록할 예정

void dfs(int sy, int sx, int sdir) {
	int TempMAP[5][5] = { 0 };
	Node Tempdirection[17];
	int tempres = res;
	memcpy(TempMAP, MAP, sizeof(MAP));
	memcpy(Tempdirection, direction, sizeof(direction));
	int y = sy;
	int x = sx;
	while (1) {
		y = y + dy[sdir];
		x = x + dx[sdir];
		// 상어가 맵밖으로 나갔을때
		if (y < 0 || x < 0 || y >= 4 || x >= 4) {
			// 결과값 비교
			if (res > ans) {
				ans = res;
			}
			break;
		}
		res += MAP[y][x];
		direction[0] = direction[MAP[y][x]];
		direction[MAP[y][x]] = { -1,-1,-1 };
		MAP[y][x] = -1; // Shark는 -1로 표현
		MAP[sy][sx] = 0;
		// 움직이면 물고기이동재개
		MoveFish();

		// 돌아오면 원상태
		memcpy(MAP, TempMAP, sizeof(MAP));
		memcpy(direction, Tempdirection, sizeof(direction));
		res = tempres;
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int a, b;
			cin >> a >> b;
			MAP[y][x] = a;
			direction[a] = { y,x,b };
		}
	}
	memcpy(InitMAP, MAP, sizeof(MAP));
	//  ↑, ↖, ←, ↙, ↓, ↘, →, ↗
	// 청소년 상어는 (0, 0)에 있는 물고기를 먹고, (0, 0)에 들어가게 된다.
	// 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다. 이후 물고기가 이동한다.
	res += MAP[0][0];
	direction[0] = direction[MAP[0][0]];
	direction[MAP[0][0]] = {-1,-1,-1};
	MAP[0][0] = -1; // Shark는 -1로 표현

	MoveFish();
	cout << ans;
	return 0;
}