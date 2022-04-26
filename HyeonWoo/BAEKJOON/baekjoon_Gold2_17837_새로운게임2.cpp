#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int arr[13][13]; // 색의 칸을 나타내는 배열
int dy[] = { -9,0,0,-1,1 }; // 1~4 우,좌,상,하
int dx[] = { -9,1,-1,0,0 };
int resflag; //게임이 끝나는지 판단하는 변수
struct INFO {
	int No,dir;
};

vector<vector<vector<INFO>>> map(13, vector<vector<INFO>>(13, vector<INFO>()));

struct Node {
	int y, x;
};

vector <Node> Search;
vector <Node> nextSearch;
vector <INFO> temp;
void White(int ny, int nx) {
	for (int i = 0; i < temp.size(); i++) {
		map[ny][nx].push_back(temp[i]);
	}
	if (map[ny][nx].size() >= 4) {
		resflag = 1;
	}
}

void Red(int ny, int nx) {
	for (int i = temp.size() - 1; i >= 0; i--) {
		map[ny][nx].push_back(temp[i]);
	}
	if (map[ny][nx].size() >= 4) {
		resflag = 1;
	}
}

//존재하면 1 아니면 0
int isExist(int ny, int nx) {
	for (int i = 0; i < nextSearch.size(); i++) {
		if (nextSearch[i].y == ny && nextSearch[i].x == nx) {
			return 1;
		}
	}
	return 0;
}

void Play() {
	for (int i = 1; i <=K; i++) {
		int y;
		int x;
		int num = i;
		int tempFlag = 0;
		for (int j = 1; j <= N; j++) {
			if (tempFlag) break;
			for (int k = 1; k <= N; k++) {
				if (tempFlag) break;
				if (map[j][k].size() == 0) continue;
				for (int q = 0; q < map[j][k].size(); q++) {
					if (map[j][k][q].No == num) {
						y = j;
						x = k;
						tempFlag = 1;
						break;
					}
				}
			}
		}
		
		// 움직이는거는 타겟 넘버이후로 쌓여있는것
		temp = vector<INFO>();
		// 먼저 움직일 수 있는말을 temp에 담아둔다.
		for (int j = 0; j < map[y][x].size(); j++) {
			if (map[y][x][j].No == num) {
				int SIZE = map[y][x].size();
				for (int k = j; k < SIZE; k++) {
					temp.push_back(map[y][x][k]);
				}
				for (int k = j; k <SIZE; k++) {
					map[y][x].pop_back();
				}
			}
		}

		int dir = temp[0].dir;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		// 움직이려는칸이 판을 벗어나거나 파란색이면 이동방향을 반대로하고 이동
		if (ny <= 0 || nx <= 0 || ny > N || nx > N || arr[ny][nx] == 2) {
			if (dir == 1 || dir == 3) {
				dir++;
			}
			else {
				dir--;
			}
			// 만약 반대방향도 파란색이거나 벗어나면 제자리에있고 dir 원래대로 움직이지 않음
			// else면 움직이는데 해당 지역이 white(0)면 그대로 pushback, Red(1)면  순서전환(temp를거꾸로담음)
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny <= 0 || nx <= 0 || ny > N || nx > N || arr[ny][nx] == 2) {
				temp[0].dir = dir;
				// 같은게 없다면 PUSH
				if (!isExist(y, x)) { // 제자리 검색
					nextSearch.push_back({ y, x });
				}
				//제자리에 다시 담아준다.
				for (int k = 0; k < temp.size(); k++) {
					map[y][x].push_back(temp[k]);
				}
			}
			else {
				temp[0].dir = dir;
				if (arr[ny][nx] == 0) {
					White(ny, nx);
				}
				else if (arr[ny][nx] == 1) {
					Red(ny, nx);
				}

				// 만약 움직이는데 한번에 움직여서 현재 자리가 비어있게되면 nextSearch에서도 지워야한다.
				if (map[y][x].size() == 0) {
					if (isExist(y, x)) {// 존재하면
						vector <Node> TempnextSearch;
						for (int i = 0; i < nextSearch.size(); i++) {
							if (nextSearch[i].y == y && nextSearch[i].x == x) continue;
							TempnextSearch.push_back(nextSearch[i]);
						}
						nextSearch = vector <Node>();
						nextSearch = TempnextSearch;
					}
				}

				// 같은게 없다면 PUSH
				if (!isExist(ny, nx)) {
					nextSearch.push_back({ ny, nx });
				}
			}
		}
		else {
			if (arr[ny][nx] == 0) {
				White(ny, nx);
			}
			else if (arr[ny][nx] == 1) {
				Red(ny, nx);
			}

			// 만약 움직이는데 한번에 움직여서 현재 자리가 비어있게되면 nextSearch에서도 지워야한다.
			if (map[y][x].size() == 0) {
				if (isExist(y, x)) {// 존재하면
					vector <Node> TempnextSearch;
					for (int i = 0; i < nextSearch.size(); i++) {
						if (nextSearch[i].y == y && nextSearch[i].x == x) continue;
						TempnextSearch.push_back(nextSearch[i]);
					}
					nextSearch = vector <Node>();
					nextSearch = TempnextSearch;
				}
			}
			// 같은게 없다면 PUSH
			if (!isExist(ny, nx)) {
				nextSearch.push_back({ ny, nx });
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}
	for (int i = 1; i <= K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		map[y][x].push_back({ i,dir });
		Search.push_back({ y,x }); // 해당 부분만 확인할예정
	}

	int res = 0;
	while (1) {
		if (res > 1000) {
			res = -1;
			break;
		}
		Play();
		res++;

		if (resflag) {
			break;
		}

		Search = vector <Node>();
		Search = nextSearch;

		

	}
	cout << res;
	
	

	return 0;
}