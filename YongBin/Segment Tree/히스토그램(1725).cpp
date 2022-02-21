#include <iostream>
#include <vector>
#include <algorithm>


#define INF 2000000001

using namespace std;

long long ans;
int n, temp;
vector<long long> h;

int init(vector<long long>& tree, int start, int end, int node) {
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int temp1 = init(tree, start, mid, node * 2);
	int temp2 = init(tree, mid + 1, end, node * 2 + 1);
	if (h[temp1] < h[temp2])
		return tree[node] = temp1;
	return tree[node] = temp2;
}

int query(vector<long long> &tree, int left, int right, int start, int end, int node) {
	if (left > end || start > right)
		return INF;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	int temp1 = query(tree, left, right, start, mid, node * 2);
	int temp2 = query(tree, left, right, mid + 1, end, node * 2 + 1);

	if (temp1 == INF)
		return temp2;
	if (temp2 == INF)
		return temp1;
	if (h[temp1] < h[temp2])
		return temp1;
	return temp2;
}

void solve(vector<long long>& tree, int left, int right) {
	if (left > right)
		return;
	int index = query(tree, left, right, 0, n - 1, 1);
	ans = max(ans, h[index] * (right - left + 1));
	solve(tree, left, index - 1);
	solve(tree, index + 1, right);
}

int main() {
	cin >> n;
	vector<long long> tree(n * 4);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		h.push_back(temp);
	}
	init(tree, 0, n - 1, 1);
	solve(tree, 0, n - 1);

	cout << ans;

	return 0;
}