#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int store[2];
vector<vector<int>>vect;
int findStore(int now, int s1, int s2) {
	int visited[101] = { 0 };
	queue<int>que;
	que.push(now);
	visited[now] = 1;
	while (!que.empty())
	{
		int a = que.front();que.pop();
		for (int i = 0; i < vect[a].size();i++) {
			if (visited[vect[a][i]])continue;
			if (vect[a][i] == s1 || vect[a][i] == s2) {
				return visited[a];
			}
			visited[vect[a][i]] = visited[a] + 1;
			que.push(vect[a][i]);
		}
	}
}
int calc(int s1, int s2)
{
	int sum = 0;
	for (int i = 1;i <= N;i++) {
		if (i == s1 || i == s2)continue;
		sum += findStore(i, s1, s2);
	}
	return sum * 2;
}
int ans1, ans2, minValue = 21e4;
void dfs(int level, int next)
{
	if (level == 2) {
		int now = calc(store[0], store[1]);
		if (minValue > now) {
			ans1 = store[0];ans2 = store[1];
			minValue = now;
		}
		else if (minValue == now) {
			if (ans1 < store[0])return;
			else if (ans1 == store[0]) {
				if (ans2 < store[1])return;
				else {
					ans1 = store[0];ans2 = store[1];
				}
			}
			else {
				ans1 = store[0];ans2 = store[1];
			}
		}
		return;
	}
	for (int i = next; i <= N;i++) {
		store[level] = i;
		dfs(level + 1, i + 1);

	}
}
void solve()
{
	dfs(0, 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i <= N;i++) {
		vect.push_back(vector<int>());
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		vect[a].push_back(b);
		vect[b].push_back(a);
	}
	solve();
	cout << ans1 << " " << ans2 << " " << minValue;
}