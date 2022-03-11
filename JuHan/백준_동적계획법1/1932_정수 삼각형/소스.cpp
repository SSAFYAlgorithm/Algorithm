#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			cin >> tree[y][x];
		}
	}

	for (int y = 1; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (y >= 0 && y < n && x >= 0 && x < n) {
				if (x == 0) {
					tree[y][x] = tree[y - 1][x] + tree[y][x];
				}
				else {
					tree[y][x] = max(tree[y - 1][x], tree[y - 1][x - 1]) + tree[y][x];
				}
			}
		}
	}
	

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (tree[n-1][i] > max) {
			max = tree[n-1][i];
		}
	}

	cout << max;

	return 0;
}