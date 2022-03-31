#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, k, ans = 0;
	string s;
	vector<int> p;
	queue<int> q;
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'P')
			p.push_back(i);
		else
			q.push(i);
	}
	for (int i = 0; i < p.size(); i++) {
		while (!q.empty()) {
			int a = q.front();
			if (abs(p[i] - a) <= k) {
				ans++;
				q.pop();
				break;
			}
			else if (p[i] > a)
				q.pop();
			else
				break;
		}
	}
	cout << ans;
	return 0;
}