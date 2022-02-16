#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
vector<int> tree[400004];

#define MIN -1000000000
#define MAX 1000000000

int n, m, a, b, c;

void init(int start, int end, int node) {
	for (int i = start; i <= end; i++) {
		tree[node].push_back(arr[i]);
	}
	sort(tree[node].begin(), tree[node].end());

	if (start != end) {
		int mid = (start + end) / 2;
		init(start, mid, node * 2);
		init(mid + 1, end, node * 2 + 1);
	}
}

int query(int start, int end, int left, int right, int node, int k) {
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right) {
		return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	}

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2, k) + query(mid + 1, end, left, right, node * 2 + 1, k);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		int low = MIN;
		int high = MAX;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (query(0, n - 1, a - 1, b - 1, 1, mid) < c)
				low = mid + 1;
			else
				high = mid - 1;
		}
		cout << low << "\n";
	}
	
	return 0;
}