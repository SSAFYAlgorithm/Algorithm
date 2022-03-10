#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, temp;
	int ans = 0;
	vector<int> arr1;
	vector<int> arr2;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > 0)
			arr1.push_back(temp);
		else
			arr2.push_back(temp);
	}

	sort(arr1.begin(), arr1.end(), greater<int>());
	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < arr1.size(); i += m) {
		ans += arr1[i] * 2;
	}

	for (int i = 0; i < arr2.size(); i += m) {
		ans += abs(arr2[i] * 2);
	}
	if (!arr1.empty() && !arr2.empty())
		ans -= max(arr1[0], -arr2[0]);
	else if (arr1.empty())
		ans -= -arr2[0];
	else if (arr2.empty())
		ans -= arr1[0];

	cout << ans;
	return 0;
}