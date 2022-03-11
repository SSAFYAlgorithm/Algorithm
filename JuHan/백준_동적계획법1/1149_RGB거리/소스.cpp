#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> house(1001);

int main() {
	int n;
	cin >> n;
	int red, green, blue;
	for (int i = 0; i < n; i++) {
		cin >> red >> green >> blue;
		house[i].push_back(red);
		house[i].push_back(green);
		house[i].push_back(blue);
	}

	for (int y = 1; y < n; y++) {
		house[y][0] += min(house[y - 1][1], house[y - 1][2]);
		house[y][1] += min(house[y - 1][0], house[y - 1][2]);
		house[y][2] += min(house[y - 1][0], house[y - 1][1]);
	}

	cout << min(min(house[n-1][0], house[n-1][1]), house[n-1][2]);

	return 0;
}