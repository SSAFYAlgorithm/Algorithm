#include<iostream>
#include<queue>
using namespace std;

int n, k;
int t = 0;
int map[200000];
queue<int> q;

int walk_b(int x) {
	return x - 1;
}
int walk_f(int x) {
	return x + 1;
}
int teleport(int x) {
	return 2 * x;
}

void bfs(int time) {
	while (1) {
		int now = q.front();
		int tt = map[now];
		if (now == k) {
			cout << map[k]-1;
			return;
		}
		int next = walk_b(now);
		if (next>=0 && next<200000 && !map[next]) {
			q.push(next);
			map[next] = tt + 1;
		}
		next = walk_f(now);
		if (next >= 0 && next<200000 && !map[next]) {
			q.push(next);
			map[next] = tt + 1;
		}
		next = teleport(now);
		if (next >= 0 && next<200000 && !map[next]) {
			q.push(next);
			map[next] = tt + 1;
		}
		q.pop();
	}
	return;
}

int main() {
	cin >> n >> k;
	q.push(n);
	map[n] = 1;
	bfs(t);

	return 0;
}