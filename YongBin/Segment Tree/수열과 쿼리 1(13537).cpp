#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, temp, m, tempi, tempj, tempk;
vector<int> arr;
vector<int> tree[400004];

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
		return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());
	}

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2, k) + query(mid + 1, end, left, right, node * 2 + 1, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	init(0, n - 1, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tempi >> tempj >> tempk;
		cout << query(0, n-1, tempi-1,tempj-1,1,tempk) << "\n";
	}
	
	return 0;
}