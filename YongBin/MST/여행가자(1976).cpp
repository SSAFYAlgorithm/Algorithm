#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> arr;
vector<int> ans;
int parent[201];

int getParent(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = getParent(parent[a]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[a] = b;
		getParent(a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, temp;
	vector<int> result;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp != 0) {
				Union(i + 1, j + 1);
			}
		}
	}
	int first, next;
	bool flag = true;
	cin >> first;
	for (int i = 1; i < m; i++) {
		cin >> next;
		if (flag == false)
			break;
		if (getParent(first) != getParent(next))
			flag = false;
		first = next;
	}
	if (flag == false)
		cout << "NO";
	else
		cout << "YES";


	

	return 0;
}