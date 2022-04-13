#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, X;

struct Node {
	int to, cost;
};

struct comp {
	bool operator()(Node right, Node left) {
		return left.cost < right.cost;
	}
};

vector <vector <Node>> vect(1010);
priority_queue<Node, vector<Node>, comp> pq;

int GoCost[1010];
int BackCost[1010];

int main() {
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vect[from].push_back({to,cost});
	}

	// 다익스트라
	// 먼저 현재집에서 X까지 가는것부터
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		pq = priority_queue<Node, vector<Node>, comp>();
		int Cost[1010] = { 0 };
		int used[1010] = { 0 };
		pq.push({ i,0 });
		while (!pq.empty()) {
			int nowNode = pq.top().to;
			int nowCost = pq.top().cost;
			pq.pop();
			if (used[X] != 0) break;
			if (used[nowNode] != 0) continue;
			used[nowNode] = 1;
			Cost[nowNode] = nowCost;
			for (int j = 0; j < vect[nowNode].size(); j++) {
				int nextNode = vect[nowNode][j].to;
				int nextCost = vect[nowNode][j].cost+nowCost;
				if (used[nextNode] != 0) continue;
				pq.push({ nextNode,nextCost });
			}
		}
		GoCost[i] = Cost[X];
	}
	
	// 본인 집으로 돌아오기
	pq = priority_queue<Node, vector<Node>, comp>();
	int used[1010] = { 0 };
	pq.push({ X,0 });
	while (!pq.empty()) {
		int nowNode = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();
		if (used[nowNode] != 0) continue;
		used[nowNode] = 1;
		BackCost[nowNode] = nowCost;
		for (int j = 0; j < vect[nowNode].size(); j++) {
			int nextNode = vect[nowNode][j].to;
			int nextCost = vect[nowNode][j].cost + nowCost;
			if (used[nextNode] != 0) continue;
			pq.push({ nextNode,nextCost });
		}
	}
	
	// 최대로 걸린 시간 찾기
	int res = -21e8;
	for (int i = 1; i <= N; i++) {
		int temp = GoCost[i] + BackCost[i];
		if (temp > res) {
			res = temp;
		}
	}

	cout << res;
}