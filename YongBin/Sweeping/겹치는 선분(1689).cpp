#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	int ans = 0;
	int temp = 0;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,1 });
		v.push_back({ b,0 });
	}

	sort(v.begin(), v.end());

	for (auto li : v) {
		if (li.second)
			temp++;
		else
			temp--;
		ans = max(ans, temp);
	}
	cout << ans <<"\n";
	return 0;
}