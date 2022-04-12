#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
string map[103];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int used[103][103];
int Cost[103][103];
struct Node {
	int y;
	int x;
	int cost;
};

struct comp {
	bool operator()(Node right, Node left) {
		return left.cost < right.cost;
	}
};

priority_queue<Node, vector<Node>, comp> pq;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> M>> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	pq.push({ 0,0,0 });
	used[0][0] = 1;
	while (!pq.empty()) {
		int nowY = pq.top().y;
		int nowX = pq.top().x;
		int nowCost = pq.top().cost;
		pq.pop();
		Cost[nowY][nowX] = nowCost;
		if (Cost[N - 1][M - 1] != 0) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];
			if (nextX < 0 || nextY < 0 || nextY >= N || nextX >= M)continue;
			if (used[nextY][nextX] != 0)continue;
			if (map[nextY][nextX] == '1') {
				pq.push({ nextY,nextX,nowCost + 1 });
			}
			else if (map[nextY][nextX] == '0') {
				pq.push({ nextY,nextX,nowCost });
			}
			used[nextY][nextX] = 1;
			
		}
	}
	
	cout << Cost[N - 1][M - 1];

	return 0;
}