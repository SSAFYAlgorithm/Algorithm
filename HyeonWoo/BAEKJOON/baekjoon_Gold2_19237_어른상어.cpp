#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K;
int shark[25][25];

struct INFO {
	int shark, SmellCnt;
};
INFO map[25][25]; // 냄새카운트와 그 냄새카운트의 주인 보여줄 예정

struct Node {
	int y, x, dir;
};
Node NowShark[420]; //현재 상어 정보

int dy[] = { 0,-1,1,0,0 }; // 1, 2, 3, 4는 각각 위, 아래, 왼쪽, 오른쪽을 의미한다.
int dx[] = { 0,0,0,-1,1 };

int Priority[420][5][4]; // 상어별로 우선순위 보여줄 에정 [상어번호][방향별][우선순위]


void Input() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> shark[y][x];
			if (shark[y][x] > 0) {
				NowShark[shark[y][x]] = { y,x,0 };
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		int dir;
		cin >> dir;
		NowShark[i].dir = dir;
	}

	for (int num = 1; num <= M; num++) {
		for (int priorityDir = 1; priorityDir <= 4; priorityDir++) {
			for (int i = 0; i < 4; i++) {
				int dir;
				cin >> dir;
				Priority[num][priorityDir][i] = dir;
			}
		}
	}
}

// 상어가 그자리에서 방구낌
void BBoong() {
	for (int i = 1; i <= M; i++) {
		if (NowShark[i].y == -1) continue; // 상어가 쫓겨남
		map[NowShark[i].y][NowShark[i].x] = { i,K };
	}
}

// 상어 이동
// 각 상어가 이동 방향을 결정할 때는, 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.
// 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다.
// 이때 가능한 칸이 여러 개일 수 있는데, 그 경우에는 특정한 우선순위를 따른다. 
void Move() {
	vector <int> NextSharkMap[25][25];
	for (int SharkNum = 1; SharkNum <= M; SharkNum++) {
		if (NowShark[SharkNum].y == -1) continue;
		int NowDir = NowShark[SharkNum].dir;
		int nextDir[4] = {0};
		int y = NowShark[SharkNum].y;
		int x = NowShark[SharkNum].x;
		int flag = 0; // 비어있는 칸으로 이동하면 1 아니면 0
		vector <Node> MySmell;
		for(int i=0; i<4; i++){
			nextDir[i] = Priority[SharkNum][NowDir][i];
			int dir = nextDir[i];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			// 만약 해당칸이 비어있지 않으면 넘어감 -> 해당칸 샤크번호 0
			if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
			if (map[ny][nx].shark == SharkNum) {
				// 만약 비어있는칸을 못찾을때를 대비해서 자기냄새인곳 저장해둠
				MySmell.push_back({ ny,nx,dir }); 
				continue;
			}
			if (map[ny][nx].shark != 0) continue;
			flag = 1;			
			NextSharkMap[ny][nx].push_back(SharkNum);
			NowShark[SharkNum] = { ny,nx,dir };		
			break; // 이동했으니 뒤에껀 탐색 x
		}

		// 빈칸 못찾은 경우
		if (!flag) {
			int ny = MySmell[0].y;
			int nx = MySmell[0].x;
			int dir = MySmell[0].dir;
			NextSharkMap[ny][nx].push_back(SharkNum);
			NowShark[SharkNum] = { ny,nx,dir };
		}

	}
	// 같은곳으로 이동한 경우 있나 확인 + 냄새감소도 같이
	memset(shark, 0, sizeof(shark));
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (NextSharkMap[y][x].size() == 1) {
				shark[y][x] = NextSharkMap[y][x][0];
			}
			else if (NextSharkMap[y][x].size() >= 2) {
				sort(NextSharkMap[y][x].begin(), NextSharkMap[y][x].end());
				shark[y][x] = NextSharkMap[y][x][0];
				// 나머지는 -1처리
				for (int i = 1; i < NextSharkMap[y][x].size(); i++) {
					int DieSharkNum = NextSharkMap[y][x][i];
					NowShark[DieSharkNum] = { -1,-1,-1 };
				}
			}
			// 냄새감소처리
			if (map[y][x].shark > 0) {
				map[y][x].SmellCnt--;
				if (map[y][x].SmellCnt == 0) {
					map[y][x] = { 0,0 };
				}
			}
		}
	}
}

int IsEnd() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (shark[y][x] > 1) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();
	// 1 맨 처음에는 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
	int time = 1;
	int resFlag = 0; // 1000초 넘었나 안넘었나
	BBoong();
	while (1) {
		if (time > 1000) {
			resFlag = 1;
			break;
		}
		Move();
		BBoong();
		if (IsEnd()) {
			break;
		}
		time++;
	}
	if (resFlag) {
		cout << -1;
	}
	else {
		cout << time;
	}
	

	return 0;
}