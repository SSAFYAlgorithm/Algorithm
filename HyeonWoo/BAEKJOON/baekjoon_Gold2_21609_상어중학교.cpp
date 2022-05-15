#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int Map[21][21];
int MAX; //  크기가 가장 큰 블록그룹의 개수
int MaxType; // 크기가 가장 큰 블록그룹
int TypeArr[21][21]; // bfs돌려서 어떻게 그룹이 형성되는지 보여줄 예정
int flag = 1; // 만약 bfs돌렸는데 블록개수가 2보다 큰게 없으면 0으로바꿔줄 예정
int Score = 0;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };


struct Node {
	int y;
	int x;
};

struct Info {
	int TotCnt;
	int RBCnt;
	int Sy;
	int Sx;
	int Type;
	vector <Node> DelPlace;
};

bool comp(Info left, Info right) {
	if (left.TotCnt == right.TotCnt) {
		if (left.RBCnt == right.RBCnt) {
			if (left.Sy == right.Sy) {
				return left.Sx > right.Sx;
			}
			return left.Sy > right.Sy;
		}
		return left.RBCnt > right.RBCnt;
	}
	return left.TotCnt > right.TotCnt;

}


vector <Node> ZeroPlace;
vector <Node> DelPlace;
vector <Info> Tempinfo;

void FindGroup() {
	memset(TypeArr, 0, sizeof(TypeArr));
	DelPlace = vector <Node>();
	MAX = 0;
	MaxType = 0;

	Tempinfo = vector <Info>();

	int RainbowBlockCnt = 0;
	int StandardBlocky = -1;
	int StandardBlockx = -1;

	int TypeNum = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (TypeArr[y][x] != 0) continue;
			if (Map[y][x] == -1 || Map[y][x] == -2) continue;
			if (Map[y][x] == 0) continue; // 일반 블록이 적어도 하나 있어야 하며,
			for (int i = 0; i < ZeroPlace.size(); i++) {
				TypeArr[ZeroPlace[i].y][ZeroPlace[i].x] = 0; // map이 0인지점은 누구나 갈 수 있기때문에 0인부분만 초기화
			}
			queue <Node> q;
			vector <Node> TempDelPlace;
			q.push({ y,x });
			TypeArr[y][x] = TypeNum;
			int Cnt = 0;
			int standard = Map[y][x]; // 일반 블록의 색은 모두 같아야 한다.
			StandardBlocky = y;
			StandardBlockx = x;
			RainbowBlockCnt = 0;
			while (!q.empty()) {
				int nowy = q.front().y;
				int nowx = q.front().x;
				TempDelPlace.push_back({ nowy,nowx });
				q.pop();
				Cnt++;
				if (Map[nowy][nowx] == 0) {
					RainbowBlockCnt++;
				}
				for (int i = 0; i < 4; i++) {
					int ny = nowy + dy[i];
					int nx = nowx + dx[i];
					if (nx < 0 || ny < 0 || ny >= N || nx >= N) continue;
					if (Map[ny][nx] != standard && Map[ny][nx] != 0) continue; // 무지개블록을 선택하거나, 기준 블록을 선택하기 위함
					if (TypeArr[ny][nx] != 0) continue;
					TypeArr[ny][nx] = TypeNum;
					q.push({ ny,nx });
				}
			}
			Tempinfo.push_back({ Cnt,RainbowBlockCnt,StandardBlocky,StandardBlockx,TypeNum,TempDelPlace });
			if (Cnt > MAX) {
				MAX = Cnt;
				MaxType = TypeNum;
			}
			TypeNum++;
		}
	}
	sort(Tempinfo.begin(), Tempinfo.end(), comp);

	if (MAX <= 1) {
		flag = 0; // 블록의 개수는 2보다 크거나 같아야 하며,
		return;
	}

	DelPlace = Tempinfo[0].DelPlace;
}

void DelBlock() {
	for (int i = 0; i < DelPlace.size(); i++) {
		int y = DelPlace[i].y;
		int x = DelPlace[i].x;
		Map[y][x] = -2; // 지워질 블록은 -2로 표현할 예정.
	}
	Score += MAX * MAX;
}

void gravity() {
	for (int x = 0; x < N; x++) {
		int BlackFlag = 0; // -1이 발견되면 1로바꿔줄것이다.
		int Blacky = N;
		for (int y = 0; y < N; y++) {
			if (Map[y][x] == -1) {
				BlackFlag = 1;
				break;
			}
		}
		if (BlackFlag) { // 가장 처음으로 발견되는 -1블록이 있다면?
			int TEMPFlag = 0;
			while (1) { // -1블록 아래에도 비어있을 수 있기 때문에 반복
				for (int y = Blacky - 1; y >= 0; y--) {
					// 모든 탐색이 끝났으면 TEMPFlag = 1;
					if (y == 0) {
						TEMPFlag = 1; 
						break;
					}
					if (Map[y][x] == -1) {
						Blacky = y;
						break;
					}
					if (Map[y][x] != -2) continue; // 빈칸인 경우에만 중력 작용
					for (int yy = y - 1; yy >= 0; yy--) { // 중력작용
						if (Map[yy][x] == -1) break;
						if (Map[yy][x] != -2) { 
							swap(Map[yy][x], Map[y][x]);
							break;
						}

					}
					
				}
				if (TEMPFlag) {
					break;
				}
			}
		}
		else {
			for (int y = N - 1; y >= 1; y--) {
				if (Map[y][x] != -2) continue; // 빈칸인 경우에만 중력 작용
				for (int yy = y - 1; yy >= 0; yy--) { // 중력작용
					if (Map[yy][x] != -2) { // 첫번째로 발견되는 -1이기때문에 -1은 없다.
						swap(Map[yy][x], Map[y][x]);
						break;
					}

				}
			}
		}
	}
}

void FindZero() {
	ZeroPlace = vector <Node>();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (Map[y][x] == 0) {
				ZeroPlace.push_back({ y,x });
			}
		}
	}

}

void Turn() {
	int TempMap[21][21]={0};
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			TempMap[y][x] = Map[x][N-1-y];
		}
	}
	memcpy(Map, TempMap, sizeof(Map));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 0) ZeroPlace.push_back({ i,j });
		}
	}

	while(flag) {
		FindGroup();
		if (flag == 0) break;
		DelBlock();
		gravity();
		Turn();
		gravity();
		FindZero();
	}

	cout << Score;


	return 0;
}