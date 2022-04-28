#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N;
int people[21][21];
int section[21][21];
int dy[] = { -1,1,1, -1 };
int dx[] = { 1,1,-1, -1 };
int mainy,  mainx, maind1, maind2;
int SectionPeople[6];
int res = 21e8;
void SetSection() {
	int TempSP[21][21] = {0};
	int tempCnt[6] = { 0 };
	memcpy(TempSP, section, sizeof(section));
	tempCnt[5] = SectionPeople[5];
	//1구역
	for (int y = 1; y < mainy; y++) {
		for (int x = 1; x <= mainx + maind1; x ++) {
			if (section[y][x] != 0) break;
			else {
				TempSP[y][x] = 1;
				tempCnt[1] += people[y][x];
			}
		}
	}

	//2구역
	for (int y = 1; y <= mainy + maind2 - maind1; y++) {
		for (int x = N; x > mainx+maind1; x--) {
			if (section[y][x] != 0) break;
			else {
				TempSP[y][x] = 2;
				tempCnt[2] += people[y][x];
			}
		}
	}

	//3구역
	for (int y = mainy; y <= N; y++) {
		for (int x = 1; x < mainx + maind2; x++) {
			if (section[y][x] != 0) break;
			else {
				TempSP[y][x] = 3;
				tempCnt[3] += people[y][x];
			}
		}
	}

	//4구역
	for (int y = mainy+maind2-maind1+1; y <= N; y++) {
		for (int x = N; x >= mainx + maind2; x--) {
			if (section[y][x] != 0) break;
			else {
				TempSP[y][x] = 4;
				tempCnt[4] += people[y][x];
			}
		}
	}

	//5구역
	for (int y = mainy-maind1; y <= mainy+maind2; y++) {
		for (int x = mainx; x <= mainx + maind2+maind1; x++) {
			if (TempSP[y][x] == 0) {
				TempSP[y][x] = 5;
				tempCnt[5] += people[y][x];
			}
		}
	}

	int MAX = 0;
	int MIN = 21e8;
	for (int i = 1; i <= 5; i++) {
		if (MAX < tempCnt[i]) {
			MAX = tempCnt[i];
		}
		if (MIN > tempCnt[i]) {
			MIN = tempCnt[i];
		}
	}

	int temp = MAX - MIN;
	if (temp < res) {
		res = temp;
	}
}

void dfs(int y, int x, int dir) {
	if (y == mainy+1 && x == mainx+1 && (dir==3||dir==2)) {
		// 규칙대로 섹션채우기
		SetSection();
		
		return;
	}

	for (int i = dir; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
		if (section[ny][nx] != 0)continue;
		section[ny][nx] = 5;
		if (dir == 0 && i == 1) {
			maind1 = x - mainx;
		}
		if (dir == 1 && i == 2) {
			maind2 = x - mainx - maind1;
		}
		SectionPeople[5] += people[ny][nx];
		dfs(ny, nx, i);
		SectionPeople[5] -= people[ny][nx];
		section[ny][nx] = 0;
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
			cin >> people[i][j];
		}
	}

	for (int y = 2; y <= N-1; y++) {
		for (int x = 1; x <= N; x++) {
			mainy = y;
			mainx = x;
			memset(section, 0, sizeof(section));
			memset(SectionPeople, 0, sizeof(SectionPeople));
			section[y][x] = 5;
			SectionPeople[5] += people[y][x];
			dfs(y, x, 0);
			
		}
	}

	cout << res;

	return 0;
}