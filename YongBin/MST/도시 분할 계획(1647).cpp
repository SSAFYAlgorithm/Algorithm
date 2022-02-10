#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> arr;
int parent[100001];

int getParent(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = getParent(parent[a]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

bool sameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b, c;
	int sum = 0;
	int last = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr.push_back({ c,a,b });
	}

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < m; i++) {
		a = get<0>(arr[i]);
		b = get<1>(arr[i]);
		c = get<2>(arr[i]);
		if (sameParent(b, c) == false) {
			Union(b, c);
			sum += a;
			last = a;
		}
	}

	cout << sum - last;
	
	return 0;
}