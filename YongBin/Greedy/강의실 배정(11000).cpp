#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
	int n;
	int ans = 0;
	vector<pair<int, int>> vec;
	priority_queue<int,vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());

	pq.push(vec[0].second);

	for (int i = 1; i < n; i++) {
		pq.push(vec[i].second);
		if (pq.top() <= vec[i].first)
			pq.pop();
	}

	cout << pq.size();



	return 0;
}