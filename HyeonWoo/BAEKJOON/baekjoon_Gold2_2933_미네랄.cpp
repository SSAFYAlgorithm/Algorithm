#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, N;


struct NODE {
	int y, x;
};

NODE parents[101][101];
int arr[101][101];
int arrNum[101][101];
int Break[101];
int Number;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };



void BFS(int r, int c) {
	queue <NODE> q;
	arrNum[r][c] = Number;
	q.push({r,c});
	while (!q.empty()) {
		int now_r = q.front().y;
		int now_c = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_r = now_r + dr[i];
			int next_c = now_c + dc[i];
			if (arr[next_r][next_c] == 0) continue;
			if (arrNum[next_r][next_c] != 0) continue;
			arrNum[next_r][next_c] = Number;
			q.push({ next_r, next_c });
		}
 	}
}

void MakeGroup() {
	memset(arrNum, 0, sizeof(arrNum));
	Number = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (arrNum[r][c] == 0 && arr[r][c] == 1) {
				Number++;
				BFS(r,c);
				
			}
		}
	}

}

void Gravity() {
	// 먼저 각 숫자 그룹의 각 열마다 가장 밑에있는 미네랄이 바닥 or 다른 미네랄까지의 최소거리를 찾아야 함
	int Bottom_to_Top[1000] = { 0 };
	for (int i = 1; i <= Number; i++) {
		Bottom_to_Top[i] = 21e8;
	}

	for (int r = R - 1; r >= 0; r--) {
		for (int c = 0; c < C; c++) {
			if (arrNum[r][c] == 0) continue;
			if (Bottom_to_Top[arrNum[r][c]] == 0) continue;
			for (int j = r+1; j <= R; j++) {
				if (j - r - 1 > Bottom_to_Top[arrNum[r][c]]) break;
				// 바닥까지 도달한경우
				if (j == R) {
					Bottom_to_Top[arrNum[r][c]] = min(Bottom_to_Top[arrNum[r][c]], R - r - 1);
					continue;
				}
				if (arrNum[j][c] == 0 || arrNum[j][c] == arrNum[r][c]) continue;
				// 다른 미네랄이 발견된 경우
				Bottom_to_Top[arrNum[r][c]] = min(Bottom_to_Top[arrNum[r][c]], j - r - 1);
			}
		}
	}

	// 떨어지는 배열 만큼 떨어뜨려야 한다.
	int NewArr[101][101] = { 0 };
	for (int c = 0; c < C; c++) {
		for (int r = R - 1; r >= 0; r--) {
			int TempNumber = arrNum[r][c];
			if (TempNumber > 0) {
				NewArr[r + Bottom_to_Top[TempNumber]][c] = 1;
			}
		}
	}
	memcpy(arr, NewArr, sizeof(arr));
}

void solution() {
	
	for (int i = 0; i < N; i++) {
		// 1. 미네랄 제거
		// 왼쪽
		int Target_r = R - Break[i];
		if (i % 2 == 0) {
			for (int c = 0; c < C; c++) {
				if (arr[Target_r][c] == 1) {
					arr[Target_r][c] = 0; // 부숨
					break;
				}
			}
		}
		// 오른쪽
		else {
			for (int c = C - 1; c >=0; c--) {
				if (arr[Target_r][c] == 1) {
					arr[Target_r][c] = 0; // 부숨
					break;
				}
			}
		}

		// 2. 미네랄 그룹화
		MakeGroup();

		// 3. 중력
		Gravity();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			char temp;
			cin >> temp;
			if (temp == 'x') {
				arr[r][c] = 1;
			}
		}
	}
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Break[i];
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			parents[r][c] = { r,c };
		}
	}

	solution();

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (arr[r][c] == 0) {
				cout << ".";
			}
			else {
				cout << "x";
			}
		}
		cout << "\n";
	}


	return 0;
}