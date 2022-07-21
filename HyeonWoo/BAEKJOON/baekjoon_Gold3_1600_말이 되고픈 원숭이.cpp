#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, W, H;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int Horse_dy[] = { -1,-2,-2,-1,1,2,2,1 };
int Horse_dx[] = { -2,-1,1,2,2,1,-1,-2 };

struct Node {
	int y, x,used_k;
};

int Map[201][201];
int Res[201][201][31];
bool visited[201][201][31]; // y x k

void BFS() {
	
	queue <Node> q;

	q.push({ 0,0,0 });
	Res[0][0][0] = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int used_k = q.front().used_k;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			if (next_x < 0 || next_y < 0 || next_y >= H || next_x >= W) continue;
			if (Map[next_y][next_x]) continue;
			if (visited[next_y][next_x][used_k])continue;
			visited[next_y][next_x][used_k] = true;
			Res[next_y][next_x][used_k] = Res[y][x][used_k] + 1;
			q.push({ next_y,next_x,used_k });
		}
		for (int i = 0; i < 8; i++) {
			int next_y = y + Horse_dy[i];
			int next_x = x + Horse_dx[i];
			int next_k = used_k + 1;
			if (next_x < 0 || next_y < 0 || next_y >= H || next_x >= W) continue;
			if (Map[next_y][next_x]) continue;
			if (next_k > K) continue;
			if (visited[next_y][next_x][next_k])continue;
			visited[next_y][next_x][next_k] = true;
			Res[next_y][next_x][next_k] = Res[y][x][used_k] + 1;
			q.push({ next_y,next_x,next_k });
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> K >> W >> H;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> Map[y][x];
			for (int i = 0; i < 31; i++) {
				Res[y][x][i] = 21e8;
			}
		}
	}

	BFS();

	int res = 21e8+1;
	for (int i = 0; i <= K; i++) {
		if (Res[H - 1][W - 1][i] < res) {
			res = Res[H - 1][W - 1][i];
		}
	}

	if (res == 21e8) cout << -1;
	else cout << res;
	return 0;
}