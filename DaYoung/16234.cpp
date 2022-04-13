#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

struct xy {
	int y, x;
};

int N, L, R;
int MAP[51][51] = { 0 }; // 인구수 맵
int checked[51][51] = { 0 }; 
int ANS = 0;
int countryCount = 1; // 연합 가입국 수
int populationSum = 0; // 연합 인구 수
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int flag = 1; //같은 날인지
int uni = 1;
queue<xy> q;

void bfs(int starty, int startx) {
	if (checked[starty][startx]) return;
	q.push({ starty,startx });
	checked[starty][startx] = uni;
	countryCount = 1;
	populationSum = MAP[starty][startx];
	while (!q.empty()) {
		xy now = q.front();
		for (int i = 0; i < 4; i++) {
			int r = now.y + dr[i];
			int c = now.x + dc[i];
			if (checked[r][c]) continue;
			if (r < 0 || c < 0 || r >= N || c >= N) continue;
			int diff = abs(MAP[r][c] - MAP[now.y][now.x]);
			if (diff<L || diff>R) continue;
			checked[r][c] = uni;
			q.push({ r,c });
			countryCount++;
			populationSum += MAP[r][c];
		}
		q.pop();
	}

	if (countryCount > 1) {
		flag++;
		int po = populationSum / countryCount;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (checked[i][j] != uni) continue;
				MAP[i][j] = po;
			}
		}
		uni++;
	}
	else checked[starty][startx] = 0;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	while (flag) {
		flag = 0;
		uni = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bfs(i, j);
			}
		}
		if (flag) ANS++;
		memset(checked, 0, sizeof(checked));
	}

	cout << ANS;

	return 0;
}