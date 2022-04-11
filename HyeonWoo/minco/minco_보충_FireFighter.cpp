#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };



struct Node {
	int y;
	int x;
};
//소화기 위치
vector <Node> A;

string arr[20];

int main() {
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		cin >> arr[y];
	}

	// 소화기위치 탐색, 불위치 탐색
	int Fy, Fx;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (arr[y][x] == 'A') {
				A.push_back({ y,x });
			}
			if (arr[y][x] == '$') {
				Fy = y;
				Fx = x;
			}
		}
	}

	// 시작 위치 입력
	int start_y, start_x;
	cin >> start_y >> start_x;


	// 각각 소화기 위치까지의 최단거리 + 불까지의 거리 두번 BFS

	int min = 2134567890;
	for (int i = 0; i < A.size(); i++) {
		queue <Node> q;
		int cnt = 0;
		int Ay = A[i].y;
		int Ax = A[i].x;
		// 소화기 위치까지
		int Cnt1[20][20] = { 0 };
		q.push({ start_y,start_x });
		Cnt1[start_y][start_x] = -1;
		while (!q.empty()) {
			// 무의미한 반복 줄이기 위해 해당 소화기가 Cnt값이 0이 아니면 break;
			if (Cnt1[Ay][Ax] != 0) {
				cnt += Cnt1[Ay][Ax];
				break;
			}

			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_y = now_y + dy[i];
				int next_x = now_x + dx[i];
				if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;
				if (arr[next_y][next_x] == '#' || arr[next_y][next_x] == '$') continue;
				if (Cnt1[next_y][next_x] != 0) continue;
				if (Cnt1[now_y][now_x] == -1) {
					Cnt1[next_y][next_x] = 1;
				}
				else {
					Cnt1[next_y][next_x] = Cnt1[now_y][now_x] + 1;
				}
				q.push({ next_y,next_x });
			}
		}

		// q를 초기화시키고, 소화기부터 불까지 다시 BFS
		int Cnt2[20][20] = { 0 };
		q = queue <Node>();
		q.push({ Ay,Ax });
		Cnt2[Ay][Ax] = -1;
		while (!q.empty()) {
			// 무의미한 반복 줄이기 위해 해당 소화기가 Cnt값이 0이 아니면 break;
			if (Cnt2[Fy][Fx] != 0) {
				cnt += Cnt2[Fy][Fx];
				break;
			}

			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_y = now_y + dy[i];
				int next_x = now_x + dx[i];
				if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;
				if (arr[next_y][next_x] == '#') continue;
				if (Cnt2[next_y][next_x] != 0) continue;
				if (Cnt2[now_y][now_x] == -1) {
					Cnt2[next_y][next_x] = 1;
				}
				else {
					Cnt2[next_y][next_x] = Cnt2[now_y][now_x] + 1;
				}
				q.push({ next_y,next_x });
			}
		}
		if (min > cnt) {
			min = cnt;
		}
	}

	cout << min;



	return 0;
}