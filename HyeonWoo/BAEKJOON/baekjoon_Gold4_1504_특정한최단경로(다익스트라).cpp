#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N, E, V1, V2;
int res;
int res1;
int res2;
int V1toV2 = 0;
struct Edge {
	int to;
	int cost;
};

struct comp {
	bool operator()(Edge Right, Edge Left) {
		return Left.cost < Right.cost;
	}
};

vector <vector <Edge>> vect(801);


int dijkstra(int s, int e) {
	if (s == e) {
		return 0;
	}
	priority_queue <Edge, vector <Edge>, comp> pq;
	vector <int> Cost(1001, 21e8);
	pq.push({ s,0 });
	Cost[s] = 0;
	while (!pq.empty()) {
		int now = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();
		if (now == e) {
			break;
		}
		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].to;
			int nextCost = nowCost + vect[now][i].cost;
			if (Cost[next] <= nextCost) continue;
			Cost[next] = nextCost;
			pq.push({ next,nextCost });
		}
	}
	if (Cost[e] == 21e8) {
		return -1;
	}
	return Cost[e];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vect[from].push_back({ to,cost });
		vect[to].push_back({ from ,cost });
	}

	cin >> V1 >> V2;

	// 1->V1->V2->N
	int case1_1 = dijkstra(1, V1);
	int case1_2 = dijkstra(V1, V2);
	int case1_3 = dijkstra(V2, N);
	if (case1_1 == -1 || case1_2 == -1 || case1_3 == -1) res1 = 21e8;
	else {
		res1 = case1_1 + case1_2 + case1_3;
	}

	// 1->V2->V1->N
	int case2_1 = dijkstra(1, V2);
	int case2_2 = case1_2;
	int case2_3 = dijkstra(V1, N);
	if (case2_1 == -1 || case2_2 == -1 || case2_3 == -1) res2 = 21e8;
	else {
		res2 = case2_1 + case2_2 + case2_3;
	}

	if (res1 == 21e8 && res2 == 21e8) {
		res = -1;
	}
	else {
		res = min(res1, res2);
	}

	cout << res;


	return 0;
}