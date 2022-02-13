#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,a,b;
	int sum = 0;
	int left = -1000000010;
	int right = -1000000010;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < n; i++) {
		if (right >= v[i].first)
			right = max(v[i].second, right);
		else {
			sum += right - left;
			left = v[i].first;
			right = v[i].second;
		}
	}
	sum += right - left;
	cout << sum;

	return 0;
}