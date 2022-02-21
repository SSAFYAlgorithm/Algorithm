#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, v, d1, d2;
stack<int> s;
vector<vector<int>> g(1001);
queue<int> q;

void dfs(int start) {
	int checked[1001] = { 0 };
	s.push(start);
	checked[start] = 1;
	cout << start << " ";
	while (1) {
		int flag = 0;
		if (s.empty()) break;

		for (int i = 0; i < g[s.top()].size(); i++) {
			if (!checked[g[s.top()][i]]) {
				checked[g[s.top()][i]] = 1;
				s.push(g[s.top()][i]);
				cout << s.top() << " ";
				flag = 1;
				break;
			}
		}
		if (!flag) {
			s.pop();
		}
	}
	return;
};

void bfs(int start) {
	int checked[1001] = { 0 };
	q.push(start);
	checked[start] = 1;
	cout << "\n" << start << " ";
	while (1) {
		if (q.empty()) break;
		for (int i = 0; i < g[q.front()].size(); i++) {
			if (!checked[g[q.front()][i]]) {
				checked[g[q.front()][i]] = 1;
				q.push(g[q.front()][i]);
				cout << q.back() << " ";
			}
		}
		q.pop();
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> d1 >> d2;

		g[d1].push_back(d2);
		g[d2].push_back(d1);
	}

	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	dfs(v);
	bfs(v);

	return 0;

}