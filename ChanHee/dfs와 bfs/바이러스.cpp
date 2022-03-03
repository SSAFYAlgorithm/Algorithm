#include<iostream>
#include <queue>
using namespace std;
int arr[101][101] = { 0 };
int used[101] = { 0 };
int cnt = 0;
void dfs(int now) {
	cnt++;
	for (int i = 0; i <= 101; i++) {
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

	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}
	used[1] = 1;
	dfs(1);

	cout << cnt-1;
}
