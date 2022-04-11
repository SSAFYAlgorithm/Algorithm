#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 다익스트라 알고리즘
int V, E,S;
struct Edge {
	int to, cost;
};

struct comp {
	bool operator()(Edge right, Edge left) {
		if (left.cost == right.cost) {
			return left.to < right.to;
		}
		return left.cost < right.cost;
	}
};

vector <Edge> vect[21000];
priority_queue <Edge, vector<Edge>, comp> pq;
int COST[21000];

int isFinish() {
	for (int i = 1; i <= V; i++) {
		if (COST[i] == -1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> V >> E >> S;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vect[from].push_back({ to,cost });
	}
	
	memset(COST, -1, sizeof(COST));

	pq.push({ S,0 });
	while (!pq.empty()) {
		int now_node = pq.top().to;
		int now_cost = pq.top().cost;
		pq.pop();
		// 이미 노드가 결정되었다면 continue;
		if (COST[now_node] != -1) {
			continue;
		}

		// 이미 모든 노드가 결정되었나 확인
		if (isFinish()) {
			break;
		}

		COST[now_node] = now_cost;

		for (int i = 0; i < vect[now_node].size(); i++) {
			int next_node = vect[now_node][i].to;
			int next_cost = vect[now_node][i].cost + now_cost;

			pq.push({ next_node,next_cost });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (COST[i] == -1) {
			cout << "INF\n";
		}
		else {
			cout << COST[i] << endl;
		}
	}

	return 0;
}