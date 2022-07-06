#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int R, C;
int Cnt[51][51];
int arr[51][51];
struct Node {
	int r, c;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

Node START, END;
int EndFlag = 0;
int Time = 0;
queue <Node> Rain;
queue <Node> Person;
void Person_Move() {
	int Size = Person.size();
	for (int i = 0; i < Size; i++) {
		if (EndFlag) break;
		int now_r = Person.front().r;
		int now_c = Person.front().c;
		Person.pop();
		for (int j = 0; j < 4; j++) {
			int next_r = now_r + dr[j];
			int next_c = now_c + dc[j];
			if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C) continue;
			if (arr[next_r][next_c] == 1 || arr[next_r][next_c] == 2) continue;
			if (next_r == START.r && next_c == START.c) continue; // 시작점은 안가도록
			if (Cnt[next_r][next_c] != 0) continue;
			Cnt[next_r][next_c] = Cnt[now_r][now_c] + 1;
			Person.push({ next_r,next_c });
			if (next_r == END.r && next_c == END.c) {
				EndFlag = 1;
				break;
			}
		}
	}
	
}

void Rain_Move() {
	int Size = Rain.size();
	for (int i = 0; i < Size; i++) {
		int now_r = Rain.front().r;
		int now_c = Rain.front().c;
		Rain.pop();
		for (int j = 0; j < 4; j++) {
			int next_r = now_r + dr[j];
			int next_c = now_c + dc[j];
			if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C) continue;
			if (arr[next_r][next_c] == 1 || arr[next_r][next_c] == 2) continue;
			if (arr[next_r][next_c] == 9 || arr[next_r][next_c] == 8) continue;
			arr[next_r][next_c] = 1;
			Rain.push({ next_r,next_c });
		}
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
			if (temp == '.') {
				arr[r][c] = 0;
			}
			else if (temp == '*'){
				arr[r][c] = 1; // 소나기
				Rain.push({ r,c });
			}
			else if (temp == 'X') {
				arr[r][c] = 2; // 강
			}
			else if (temp == 'H') {
				arr[r][c] = 9; // 집 (도착지)
				END = { r,c };
			}
			else if (temp == 'W') {
				arr[r][c] = 8; // 세차장 (출발지)
				START = { r,c };
				Person.push({ r,c });
			}
		}
	}

	// BFS로 이동할 것입니당~
	while (1) {
		Time++;
		// 소나기 이동
		Rain_Move();
		int de = -1;

		// 태범이가 이동
		Person_Move();
		if (!EndFlag && Person.size() == 0) EndFlag = 2; // 아무곳도 못가는 경우
		if (EndFlag) break;

	}

	if (EndFlag == 2) {
		cout << "FAIL\n";
	}
	else if (EndFlag == 1) {
		cout << Time;
	}

	return 0;
}