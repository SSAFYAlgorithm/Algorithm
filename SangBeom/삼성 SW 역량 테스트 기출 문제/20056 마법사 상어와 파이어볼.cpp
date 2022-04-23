#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
struct Fireball {
	int r, c, m, s, d;
};
struct Firediv {
	int m, s, flag, cnt, dir;
};
int N, M, K;
vector<Fireball>fire;
Firediv MAP[51][51];
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
void moveFireball() {
	memset(MAP, 0, sizeof(MAP));
	for (int i = 0;i < fire.size();i++) {
		int tr = fire[i].r + dr[fire[i].d] * fire[i].s;
		int tc = fire[i].c + dc[fire[i].d] * fire[i].s;
		if (tr < 0)tr = tr % N + N;
		if (tr >= N)tr %= N;
		if (tc < 0)tc = tc % N + N;
		if (tc >= N)tc %= N;

		MAP[tr][tc].m += fire[i].m;
		MAP[tr][tc].s += fire[i].s;
		if (!MAP[tr][tc].flag) {
			if (fire[i].d % 2 == 0)//¦
				MAP[tr][tc].flag = 1;
			else  //Ȧ
				MAP[tr][tc].flag = 2;
		}
		else if (MAP[tr][tc].flag == 1) {
			if (fire[i].d % 2) MAP[tr][tc].flag = 3;
		}
		else if (MAP[tr][tc].flag == 2) {
			if (!(fire[i].d % 2)) MAP[tr][tc].flag = 3;
		}
		MAP[tr][tc].cnt++;
		MAP[tr][tc].dir = fire[i].d;
	}
}
void divFireball()
{
	fire.clear();
	int fx[4] = { -1,0,1,0 };
	int fy[4] = { 0,1,0,-1 };
	int ex[4] = { -1,-1,1,1 };
	int ey[4] = { 1,1,-1,-1 };
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j].cnt >= 2) {
				if (!(MAP[i][j].m / 5))continue;
				if (MAP[i][j].flag == 1 || MAP[i][j].flag == 2) {
					for (int k = 0;k < 4;k++) {
						fire.push_back({ i,j,(MAP[i][j].m / 5),(MAP[i][j].s / MAP[i][j].cnt),2 * k });
					}
				}
				else if (MAP[i][j].flag == 3) {
					for (int k = 0;k < 4;k++) {
						fire.push_back({ i,j,(MAP[i][j].m / 5),(MAP[i][j].s / MAP[i][j].cnt),2 * k + 1 });
					}
				}
			}
			else if (MAP[i][j].cnt == 1) {
				fire.push_back({ i,j,MAP[i][j].m,MAP[i][j].s,MAP[i][j].dir });
			}
		}
	}
}
int solve() {
	for (int t = 0;t < K;t++) {
		moveFireball();
		divFireball();
	}
	int sum = 0;
	for (int i = 0;i < fire.size();i++) {
		sum += fire[i].m;
	}
	return sum;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0;i < M;i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fire.push_back({ r - 1,c - 1,m,s,d });
	}
	cout << solve();
}