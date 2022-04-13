#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

int N, K, L;
int map[110][110];
char dir[4] = { 'R','D','L','U' };

int flag = 0;
int Turn[10010];
struct Node{
	int y;
	int x;
};
queue <Node> snake;


void Move(int HeadY,int HeadX, int* TailY, int* TailX) {
	if (map[HeadY][HeadX] == 1) {
		map[HeadY][HeadX] = 9;
	}
	// 사과가 없다면 꼬리도 움직여야함
	else {
		if (map[HeadY][HeadX] != 0) {
			flag = 1;
			return;
		}
		map[HeadY][HeadX] = 9;
		*TailY = snake.front().y;
		*TailX = snake.front().x;
		snake.pop();
		map[*TailY][*TailX] = 0;

	}
	snake.push({ HeadY,HeadX });
}

int main() {
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time; char dir;
		cin >> time >> dir;
		if (dir == 'D') {
			// 1이면 오른쪽으로 회전
			Turn[time] = 1;
		}
		else if (dir == 'L') {
			// -1이면 왼쪽으로 회전
			Turn[time] = -1;
		}
			
	}
	
	
	// 지렁이 움직이자 지렁이는 9로 표시
	int res = 0;
	int diridx = 0;
	int HeadY = 1; int HeadX = 1;
	int TailY = 1; int TailX = 1;
	map[HeadY][HeadX] = 9;
	snake.push({ 1,1 });
	while (1) {
		res++;
		if (dir[diridx] == 'R') {
			// 사과가 있다면 길이변화 x
			HeadX++;
			if (HeadX == N+1 || HeadY == N + 1 || HeadX == 0 || HeadY == 0) {
				break;
			}
			Move(HeadY, HeadX, &TailY, &TailX);
		}
		else if (dir[diridx] == 'D') {
			HeadY++;
			if (HeadX == N + 1 || HeadY == N + 1 || HeadX == 0 || HeadY == 0) {
				break;
			}
			Move(HeadY, HeadX, &TailY, &TailX);
		}
		else if (dir[diridx] == 'L') {
			HeadX--;
			if (HeadX == N + 1 || HeadY == N + 1 || HeadX == 0 || HeadY == 0) {
				break;
			}
			Move(HeadY, HeadX, &TailY, &TailX);
		}
		else {
			HeadY--;
			if (HeadX == N + 1 || HeadY == N + 1 || HeadX == 0 || HeadY == 0) {
				break;
			}
			Move(HeadY, HeadX, &TailY, &TailX);
		}
		if (flag) {
			break;
		}
		if (Turn[res] == 1) {
			diridx++;
			if (diridx == 4) {
				diridx = 0;
			}
		}
		else if (Turn[res] == -1) {
			diridx--;
			if (diridx == -1) {
				diridx = 3;
			}
		}
	}

	cout << res;
}