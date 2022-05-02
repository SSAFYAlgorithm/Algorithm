#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//  N×N인 격자에 파이어볼 M개 K번 명령
int N, M, K;
int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };

//  i번 파이어볼의 위치는 (r, c), 질량은 m이고, 방향은 d, 속력은 s
struct INFO {
	int r, c, m, s, d;
};

struct Node {
	int r, c;
};
vector <INFO> Fireball[52][52]; // 같은 위치에 합쳐지면 해당 위치에 info 추가

vector <INFO> info;



void Move() {
	vector <INFO> tempinfo;
	vector <INFO> tempFireball[52][52];
	vector <Node> Check; // Fireball이 2개이상으로 겹치는곳이면 push;
	for (int i = 0; i < info.size(); i++) {
		int r = info[i].r;
		int c = info[i].c;
		int m = info[i].m;
		int s = info[i].s;
		int d = info[i].d;
		int nr = r + dr[d]*s;
		int nc = c + dc[d]*s;
		if (nr > N) {
			nr = nr % N;
			if (nr == 0) {
				nr = N;
			}
		}
		else if (nr <= 0) {
			nr = N - (abs(nr) % N);
		}
		if (nc > N) {
			nc = nc % N;
			if (nc == 0) {
				nc = N;
			}
		}
		else if (nc <= 0) {
			nc = N - (abs(nc) % N);
		}
		tempFireball[nr][nc].push_back({ nr,nc,m,s,d });
		if (tempFireball[nr][nc].size() == 2) {
			Check.push_back({ nr,nc }); // 3부터는 2일때 이미 넣어줬으므로 무시 가능
		}
	}
	// 1개짜리는 일단 tempinfo에 넣어줌
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (tempFireball[y][x].size() == 1) {
				tempinfo.push_back(tempFireball[y][x][0]);
			}
		}
	}


	// Bomb
	
	for (int i = 0; i < Check.size(); i++) {
		int TargetR = Check[i].r;
		int TargetC = Check[i].c;
		// 나눠져야함
		int SZ = tempFireball[TargetR][TargetC].size();
		int standardD = 0; // 기준 홀수인지 짝수인지 파악 1 -> 홀수 2-> 짝수
		int flag = 0; // 방향이 모두 홀수 / 짝수인지 파악
		int totalm = 0;
		int totals = 0;
		for (int j = 0; j < SZ; j++) {
			int r = tempFireball[TargetR][TargetC][j].r;
			int c = tempFireball[TargetR][TargetC][j].c;
			int m = tempFireball[TargetR][TargetC][j].m;
			int s = tempFireball[TargetR][TargetC][j].s;
			int d = tempFireball[TargetR][TargetC][j].d;
			// 방향파악부터
			if (j == 0) {
				if (d % 2 == 0) {
					standardD = 2;
				}
				else {
					standardD = 1;
				}
			}
			else {
				if (!flag) {
					if (standardD == 2 && d % 2 == 1) {
						flag = 1;
					}
					else if (standardD == 1 && d % 2 == 0) {
						flag = 1;
					}
				}
			}
			totalm += m;
			totals += s;
		}
		int nm = totalm / 5;
		int ns = totals / SZ;
		if (nm == 0) continue;
		// 나뉜것들을 맵과 tempinfo에 저장
		// r, c, m, s, d;
		if (!flag) { // 새로운 방향은 0 2 4 6
			for (int d = 0; d <= 6; d += 2) {
				tempinfo.push_back({ TargetR,TargetC,nm,ns,d });
				tempFireball[TargetR][TargetC].push_back({ TargetR,TargetC,nm,ns,d });
			}
		}
		else {
			for (int d = 1; d <= 7; d += 2) {
				tempinfo.push_back({ TargetR,TargetC,nm,ns,d });
				tempFireball[TargetR][TargetC].push_back({ TargetR,TargetC,nm,ns,d });
			}
		}
	}
	
	// Fireball 갱신, info 갱신
	info = vector <INFO>();
	info = tempinfo;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			Fireball[y][x] = vector <INFO>();
		}
	}

	for (int i = 0; i < tempinfo.size(); i++) {
		int r = info[i].r;
		int c = info[i].c;
		Fireball[r][c].push_back(info[i]);
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		info.push_back({ r,c,m,s,d });
		Fireball[r][c].push_back(info[i]);
	}

	for (int i = 0; i < K; i++) {
		Move();
	}

	int res = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			for (int i = 0; i < Fireball[r][c].size(); i++) {
				res += Fireball[r][c][i].m;
			}
		}
	}
	cout << res;
	
	return 0;
}