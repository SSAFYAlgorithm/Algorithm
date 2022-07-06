#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int R, C;
char Map[101][101];

int used[101][101]; // 사용했는지를 구별하는 배열

struct Info {
	int cnt;
	int dir;
};

int Mirror[101][101]; // 해당 노드까지 몇개의 거울을 썼는지 구별하는 배열

int sr, sc, er, ec;

struct Node {
	int r, c, cnt, dir;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct compare {
	bool operator()(Node right, Node left) {
		return left.cnt < right.cnt;
	}
};

void BFS() {

	priority_queue <Node, vector<Node>, compare> q;
	q.push({ sr,sc, 0 });
	Mirror[sr][sc] = 0;
	while(!q.empty()){
		int now_r = q.top().r;
		int now_c = q.top().c;
		int now_cnt = q.top().cnt;
		int now_dir = q.top().dir;
		if (used[now_r][now_c]) {
			Mirror[now_r][now_c] = min(Mirror[now_r][now_c], now_cnt);
		}
		else {
			Mirror[now_r][now_c] = now_cnt;
		}
		used[now_r][now_c] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_r = now_r + dr[i];
			int next_c = now_c + dc[i];
			if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C) continue;
			if (Map[next_r][next_c] == '*') continue;
			if (used[next_r][next_c]) continue;
			int next_cnt = 0;
			if (now_dir != i) {
				next_cnt = now_cnt + 1;
			}
			else {
				next_cnt = now_cnt;
			}
			if (now_r == sr && now_c == sc) next_cnt = 0;
			q.push({ next_r,next_c,next_cnt,i });	
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> C >> R;
	int C_Flag = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			Mirror[r][c] = 21e8;
			cin >> Map[r][c];
			if (Map[r][c] == 'C') {
				if (!C_Flag) {
					C_Flag = 1;
					sr = r;
					sc = c;
				}
				else {
					er = r;
					ec = c;
				}
			}
		}
	}

	BFS();

	cout << Mirror[er][ec];
	return 0;
}