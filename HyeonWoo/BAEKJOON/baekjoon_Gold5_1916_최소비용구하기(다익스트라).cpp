#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M,S,E;

struct node {
	int to, cost;
};

struct comp {
	bool operator()(node right, node left) {
		return left.cost < right.cost;
	}
};

int Cost[1100];
int used[1100];
vector <vector <node>> vect(1100);
priority_queue <node, vector<node>, comp> pq;

int main() {
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vect[from].push_back({ to,cost });
	}

	cin >> S >> E;

	// 다익스트타 실행
	pq.push({ S,0 });
	while (!pq.empty()) {
		int nowNode = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();
		if (used[nowNode] != 0) continue;
		used[nowNode] = 1;
		Cost[nowNode] = nowCost;		
		for (int i = 0; i < vect[nowNode].size(); i++) {
			int nextNode = vect[nowNode][i].to;
			int nextCost = vect[nowNode][i].cost + nowCost;
			if (Cost[nextNode] != 0) continue;
			pq.push({ nextNode,nextCost });
		}
	}

	cout << Cost[E];
}