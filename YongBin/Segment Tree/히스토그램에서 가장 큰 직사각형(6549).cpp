#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> h;
long long ans;
int n, temp;

#define INF 2000000000

int init(vector<int>& tree, int start, int end, int node) { 
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int temp1 = init(tree, start, mid, node * 2);
	int temp2 = init(tree, mid + 1, end, node * 2 + 1);
	if (h[temp1] < h[temp2])
		return tree[node] = temp1;
	return tree[node] = temp2;

}

int query(vector<int> &tree, int start, int end, int left, int right, int node) {
	if (left > end || start > right)
		return INF;
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	int temp1 = query(tree, start, mid, left, right, node * 2);
	int temp2 = query(tree, mid + 1, end, left, right, node * 2 + 1);
	
	if (temp1 == INF)
		return temp2;
	if (temp2 == INF)
		return temp1;
	if (h[temp1] < h[temp2])
		return temp1;
	return temp2;
}

void solve(vector<int> &tree, int left, int right) {
	if (left > right)
		return;
	long long index = query(tree, 0, n - 1, left, right, 1);
	ans = max(ans, h[index] * (right - left + 1));
	solve(tree, left, index - 1);
	solve(tree, index + 1, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> n;
		ans = 0;
		h.clear();

		vector<int> tree(n * 4);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			h.push_back(temp);
		}
		
		init(tree, 0, n - 1, 1);
		solve(tree, 0, n-1);
		cout << ans << "\n";
	}
	return 0;
}