#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, temp;
	int ans = 0;
	vector<int> arr;
	vector<int> dist;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	if (k >= n) {
		cout << 0;
		return 0;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 1; i++) {
		dist.push_back(arr[i + 1] - arr[i]);
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < n - k; i++) {
		ans += dist[i];
	}

	cout << ans;

	return 0;
}