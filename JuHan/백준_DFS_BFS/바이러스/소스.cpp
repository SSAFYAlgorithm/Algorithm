#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node, line;
int s, e;

bool visited[8] = { 0 };
vector<int> graph[100];
//vector<int> graph[8] = {
//	{},
//	{2,5},
//	{1,3,5},
//	{2},
//	{7},
//	{1,2,6},
//	{5},
//	{4}
//};

void dfs(int x) {
	// x에 방문한 상태
	visited[x] = true;
	//cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y])dfs(y);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> line;
	for (int i = 0; i < line; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	dfs(1);

	int cnt = 0;

	for (int i = 1; i < 8; i++) {
		if (visited[i]) {
			cnt++;
		}
	}

	//방문한 노드중 자기자신 빼기
	cout << cnt -1;

	return 0;
}