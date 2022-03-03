#include<iostream>
#include <queue>
using namespace std;
int arr[1001][1001] = { 0 };
int used[1001] = { 0 };
void dfs(int now) {
	cout << now << ' ';

	for (int i = 0; i <= 1001; i++) {
		if (arr[now][i] == 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodeCnt, edgeCnt, start;
	cin >> nodeCnt >> edgeCnt >> start;
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}
	used[start] = 1;
	dfs(start);
	cout << '\n';

	queue<int> q;

	int qused[1001] = { 0 };
	qused[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';

		for (int to = 1; to <= 1001; to++) {
			if (arr[now][to] == 0) continue;
			if (qused[to] != 0) continue;
			qused[to] = qused[now] + 1;
			q.push(to);
		}
	}

}
