#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int map[16][16]; // 1은 덮을곳 덮으면 2로 바꿀꺼임
int res = 2134567890;
int OneCount;
struct PaperInfo {
	int r;
	int c;
};

int isOK(int ColorPaperSize, int sy, int sx) {
	int tempmap[16][16];
	memcpy(tempmap, map, sizeof(map));
	for (int y = sy; y < sy + ColorPaperSize; y++) {
		for (int x = sx; x < sx + ColorPaperSize; x++) {
			if (map[y][x] != 1) {
				memcpy(map, tempmap, sizeof(map));
				return 0;
			}
			else {
				map[y][x] = 2;
			}
		}
	}
	return 1;
}

// dfs는 각 색종이 사이즈별로 어디 배치할지
int Size[6] = { 0,5,5,5,5,5 };
int flag = 0;
void dfs(int y, int x, int Cnt) {

	// 먼저 1인 지점을 찾자
	while(1){
		if (y == 10 || x == 10) {
			// 끝까지 탐색했다면 res 갱신
			res = min(res, Cnt);
			return;
		}
		if (map[y][x] == 1) break;
		x++;
		if (x >= 10) {
			x = 0; y++;
		}
	}

	// 가지치기 (만약 res보다 현재 Cnt가 더 크거나 같으면 볼필요도 없다.)
	if (Cnt >= res) {
		return;
	}

	// 모든 크기 색종이를 덮어본다
	for (int i = 5; i >= 1; i--) {
		// 맵밖으로 넘어가거나 이미 색종이를 다썼으면 continue
		if (y + i > 10 || x + i > 10 || Size[i] == 0) continue;

		int tempmap[16][16];
		memcpy(tempmap, map, sizeof(map)); // 후에 초기화를 위해 담아줬음

		// 색종이 부착 겸 판별
		if (isOK(i, y, x)) {
			// 부착했으니까 Size[i] 감소
			Size[i]--;
			dfs(y, x, Cnt + 1);
			Size[i]++;
			memcpy(map, tempmap, sizeof(map));
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				OneCount++;
			}
		}
	}

	dfs(0, 0, 0);

	if (res == 2134567890) {
		res = -1;
	}
	cout << res;

	return 0;
}