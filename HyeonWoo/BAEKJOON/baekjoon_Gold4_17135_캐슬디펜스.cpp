#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 궁수 3명, 성이 있는 칸
// 궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적
// 여럿일 경우에는 가장 왼쪽에 있는 적
// 공격받은 적은 게임에서 제외
// 궁수의 공격이 끝나면, 적이 이동
// 적은 아래로 한 칸 이동
// 성이 있는 칸으로 이동한 경우에는 게임에서 제외

// dfs -> 궁수 위치 배열,
// vector에 짧은 거리 순서로 담는다 (pq써도 될듯)
// 
// 격자판의 N번행의 바로 아래(N+1번 행)의 모든 칸에는 성
struct Node {
	int y, x;
};

int Map[20][20];
int InitMap[20][20];
vector <Node> Enemy;
vector <Node> InitEnemy;

int usedCastle[20];
int N, M, D;
int ans = 0;
int res = 0;
int resFlag = 0;
vector <Node> Archer;

void PrintEnemy() {
	int tempMap[20][20] = { 0 };
	for (int i = 0; i < Enemy.size(); i++) {
		int y = Enemy[i].y;
		int x = Enemy[i].x;
		tempMap[y][x] = 1;
	}
	memcpy(Map, tempMap, sizeof(Map));
}

void KillEnemy() {
	vector <Node> KillPlace;
	for (int arc = 0; arc < Archer.size(); arc++) {
		if (resFlag) break; // 이미 게임 끝
		int ay = Archer[arc].y;
		int ax = Archer[arc].x;
		int ty = -1, tx = -1, tlen = -1;; // 누구를 죽일지
		// 모든 적과의 거리 탐색
		for (int i = 0; i < Enemy.size(); i++) {
			int Ey = Enemy[i].y;
			int Ex = Enemy[i].x;
			int len = abs(ay - Ey) + abs(ax - Ex);
			if (len > D) continue;
			if (tlen == -1) {
				ty = Ey;
				tx = Ex;
				tlen = len;
			}
			else {
				if (len < tlen) {
					ty = Ey;
					tx = Ex;
					tlen = len;
				}
				else if (len == tlen) {
					// 만약에 거리는 같다면 여럿일 경우에는 가장 왼쪽에 있는 적
					if (Ex < tx) {
						ty = Ey;
						tx = Ex;
						tlen = len;
					}
				}
			}
		}
		int tempFlag = 0;
		for (int j = 0; j < KillPlace.size(); j++) {
			if (ty == KillPlace[j].y && tx == KillPlace[j].x) {
				tempFlag = 1;
				break;
			}
		}
		// 같은게 없어야지 push
		if (!tempFlag && tlen != -1) {
			KillPlace.push_back({ ty,tx });
		}
	}
	vector <Node> tempEnemy;
	tempEnemy = Enemy;
	Enemy = vector <Node>();
	for (int i = 0; i < tempEnemy.size(); i++) {
		int tempFlag = 0;
		for (int j = 0; j < KillPlace.size(); j++) {
			if (tempEnemy[i].y == KillPlace[j].y && tempEnemy[i].x == KillPlace[j].x) {
				res++; // 죽인적은 새로운 Enemy가 아님
				tempFlag = 1;
			}
		}
		// 죽인적이 아니라면 Enemy에 추가
		if (!tempFlag) {
			Enemy.push_back(tempEnemy[i]);
		}
	}
	if (Enemy.size() == 0) {
		resFlag = 1;
	}
	PrintEnemy();
}

void MoveEnemy() {
	vector <Node> tempEnemy;
	tempEnemy = Enemy;
	Enemy = vector<Node>();
	for (int i = 0; i < tempEnemy.size(); i++) {
		int Ey = tempEnemy[i].y;
		int Ex = tempEnemy[i].x;

		// 적은 아래로 한 칸 이동
		// 성이 있는 칸으로 이동한 경우에는 게임에서 제외
		Ey++;
		if (Ey == N) continue;
		Enemy.push_back({ Ey,Ex });
	}
	if (Enemy.size() == 0) {
		resFlag = 1;
	}
	PrintEnemy();
}


void dfs(int level) {
	if (level == 3) {
		// 아처 위치 정해졌으면 아처 별로 가장 가까운 적 위치 탐색
		res = 0;
		resFlag = 0;
		Enemy = vector <Node>();
		Enemy = InitEnemy;
		memcpy(Map, InitMap, sizeof(Map));
		while (!resFlag) {
			KillEnemy();
			MoveEnemy();
		}
		if (res > ans) {
			ans = res;
		}
		return;
	}

	for (int i = 0; i < M; i++) {
		if (usedCastle[i] != 0) continue;
		usedCastle[i] = 1;
		Archer.push_back({ N,i });
		dfs(level + 1);
		usedCastle[i] = 0;
		Archer.pop_back();
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> D;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> Map[y][x];
			if (Map[y][x] == 1) {
				Enemy.push_back({ y,x });
			}
		}
	}
	InitEnemy = Enemy;
	memcpy(InitMap, Map, sizeof(Map));
	dfs(0);

	cout << ans;

	return 0;
}