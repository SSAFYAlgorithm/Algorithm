#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m, k, temp;
		int ans = 1;
		vector<int> person;
		cin >> n >> m >> k;

		for (int j = 0; j < n; j++) {
			cin >> temp;
			person.push_back(temp);
		}

		sort(person.begin(), person.end());

		for (int j = 0; j < n; j++) {
			if ((person[j] / m) * k < j + 1) {
				ans = 0;
				break;
			}
		}

		if (ans == 1)
			cout << "#" << i + 1 << " Possible" << "\n";
		else
			cout << "#" << i + 1 << " Impossible" << "\n";

	}
	return 0;
}