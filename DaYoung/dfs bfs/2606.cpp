#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, p, p1, p2;
vector<vector<int>> g(101);
int cnt=0;
queue<int> q;
int checked[101];

int bfs() {
	q.push(1);
	checked[1] = 1;

	while (1) {
		if (q.empty()) break;

		for (int i = 0; i < g[q.front()].size(); i++) {
			if (!checked[g[q.front()][i]]) {
				checked[g[q.front()][i]] = 1;
				q.push(g[q.front()][i]);
				cnt++;
			}
		}
		q.pop();
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		cin >> p1 >> p2;
		g[p1].push_back(p2);
		g[p2].push_back(p1);
	}

	cout<<bfs();

	return 0;

}