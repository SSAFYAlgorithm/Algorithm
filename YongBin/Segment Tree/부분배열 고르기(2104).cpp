#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000

using namespace std;

long long ans;
int n, temp;
vector<int> arr;

pair<long long, int> init(vector<pair<long long, int>>& tree, int start, int end, int node) {
	if (start == end)
		return tree[node] = { arr[start], start };
	int mid = (start + end) / 2;
	pair<long long, int> temp1 = init(tree, start, mid, node * 2);
	pair<long long, int> temp2 = init(tree, mid + 1, end, node * 2 + 1);
	if (arr[temp1.second] < arr[temp2.second])
		return tree[node] = { temp1.first + temp2.first, temp1.second };
	return tree[node] = { temp1.first + temp2.first, temp2.second };
}

pair<long long, int> query(vector<pair<long long, int>>& tree, int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return { 0, INF };
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	pair<long long, int> temp1 = query(tree, start, mid, left, right, node * 2);
	pair<long long, int> temp2 = query(tree, mid + 1, end, left, right, node * 2 + 1);

	if (temp1.second == INF)
		return temp2;
	if (temp2.second == INF)
		return temp1;
	if (arr[temp1.second] < arr[temp2.second])
		return { temp1.first + temp2.first, temp1.second };
	return { temp1.first + temp2.first, temp2.second };

}

void solve(vector<pair<long long, int>>& tree, int left, int right) {
	if (left > right)
		return;
	pair < long long, int> temp1 = query(tree, 0, n - 1, left, right, 1);
	ans = max(ans, arr[temp1.second] * temp1.first);
	solve(tree, left, temp1.second - 1);
	solve(tree, temp1.second + 1, right);
}

int main() {
	cin >> n;
	vector<pair<long long, int>> tree(n * 4);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	init(tree, 0, n - 1, 1);
	solve(tree, 0, n - 1);
	cout << ans;
	return 0;
}