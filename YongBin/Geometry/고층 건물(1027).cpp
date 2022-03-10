#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, temp;
	vector<int> building;
	int arr[51] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		building.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		double maxAng = -1000000001;
		for (int j = i + 1; j < n; j++) {
			int h = building[j] - building[i];
			int w = j - i;
			double ang = (double)h /w;
			if (ang > maxAng) {
				arr[i]++;
				arr[j]++;
				maxAng = ang;
			}
		}
	}
	sort(arr, arr + n);
	cout << arr[n - 1];
	return 0;
}