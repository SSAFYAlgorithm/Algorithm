#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int N;
int people[11];
vector<vector<int>>vect;
int visited[11];
int bfs()
{
	int temp[11];
	memcpy(temp, visited, sizeof(temp));
	queue<int>que;
	int a;
	for (int i = 0;i < N;i++) {
		if (!temp[i]) {
			a = i;
			temp[i] = 2;
			break;
		}
	}
	que.push(a);
	while (!que.empty()) {
		int now = que.front();que.pop();
		for (int i = 0;i < vect[now].size();i++) {
			if (temp[vect[now][i]])continue;
			temp[vect[now][i]] = 2;
			que.push(vect[now][i]);
		}
	}
	int s = 0;
	int e = 0;
	for (int i = 0;i < N;i++) {
		if (!temp[i])return -1;
		if (temp[i] == 1) s += people[i];
		if (temp[i] == 2)  e += people[i];
	}
	return abs(s - e);
}
int maxValue = 10000;
int flag;
int tmp[11];
void check(int from) {

	tmp[from] = 0;
	for (int i = 0; i < vect[from].size();i++) {
		if (tmp[vect[from][i]]) {
			check(vect[from][i]);
		}

	}
}
void dfs(int level, int now, int depth)
{
	if (level == depth) {

		flag = 1;
		if (depth >= 2 && depth <= N - 1) {
			memcpy(tmp, visited, sizeof(tmp));
			for (int i = 0;i < N;i++) {
				if (visited[i]) {
					check(i);
					break;
				}
			}
			for (int i = 0;i < N;i++) {
				if (tmp[i]) {
					flag = 0;
					break;
				}
			}
		}
		if (!flag)return;
		int now = bfs();
		if (now != -1 && now < maxValue) {
			maxValue = now;
		}
		return;
	}
	for (int i = now;i < N;i++) {
		if (visited[i])continue;
		visited[i] = 1;
		dfs(level + 1, i + 1, depth);
		visited[i] = 0;
	}
}
void divSector(int from)
{
	visited[from] = 1;
	for (int i = 0; i < vect[from].size();i++) {
		if (visited[vect[from][i]])continue;
		divSector(vect[from][i]);
	}
}
int solve()
{
	int t = 0;
	for (int i = 0;i < N;i++) {
		if (!visited[i]) {
			divSector(i);
			t++;
			if (t >= 3)return -1;
		}
	}
	memset(visited, 0, sizeof(visited));
	if (t == 1) {
		for (int i = 1;i < N;i++) {
			dfs(0, 0, i);
		}
		return maxValue;
	}
	if (t == 2) {
		for (int i = 0;i < N;i++) {
			if (!visited[i]) {
				divSector(i);
				break;
			}
		}
		int sum = 0;
		for (int i = 0;i < N;i++) {
			if (visited[i] == 1)sum -= people[i];
			else if (visited[i] == 0)sum += people[i];
		}
		return abs(sum);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> people[i];
	}

	for (int i = 0;i < N;i++) {
		int c;
		cin >> c;
		vect.push_back(vector<int>());
		for (int j = 0;j < c;j++) {
			int node;
			cin >> node;
			vect[i].push_back(node - 1);
		}
	}
	int now = solve();
	if (now == 10000)cout << -1;
	else cout << now;
}