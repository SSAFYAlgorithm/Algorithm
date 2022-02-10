#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, b, d;
	int ans = 0;
	int pqSize = 0;
	vector<pair<int, int>> v;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a < b)
			v.push_back({ a,b });
		else
			v.push_back({ b,a });
	}
	cin >> d;

	sort(v.begin(), v.end(), cmp);

	int left = v[0].second - d;
	int right = v[0].second;

	for (int i = 0; i < n; i++) {
		if (v[i].first >= left && v[i].second <= right) {
			pqSize++;
			pq.push({ v[i].first, v[i].second });
		}
		else {
			pq.push({ v[i].first, v[i].second });
			pqSize++;
			left = v[i].second - d;
			right = v[i].second;
			while (true) {
				if (pq.empty())
					break;
				if (pq.top().first >= left && pq.top().second <= right)
					break;
				pq.pop();
				pqSize--;
			}
			
		}
		ans = max(ans, pqSize);
	}

	cout << ans;

	return 0;
}