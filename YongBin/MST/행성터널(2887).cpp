#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

vector<pair<int, int>> xnode;
vector<pair<int, int>> ynode;
vector<pair<int, int>> znode;
vector<tuple<int, int, int>> result;
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
		parent[a] = b;
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
	int n, a, b, c;
	int sum = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		xnode.push_back({ a,i });
		ynode.push_back({ b,i });
		znode.push_back({ c,i });
	}

	sort(xnode.begin(), xnode.end());
	sort(ynode.begin(), ynode.end());
	sort(znode.begin(), znode.end());

	for (int i = 0; i < n - 1; i++) {
		result.push_back({ xnode[i+1].first - xnode[i].first, xnode[i].second, xnode[i+1].second});
		result.push_back({ ynode[i + 1].first - ynode[i].first, ynode[i].second, ynode[i + 1].second });
		result.push_back({ znode[i + 1].first - znode[i].first, znode[i].second, znode[i + 1].second });
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		a = get<0>(result[i]);
		b = get<1>(result[i]);
		c = get<2>(result[i]);
		if (sameParent(b, c) == false) {
			Union(b, c);
			sum += a;
		}
	}

	cout << sum;

	/*
	vector<pair<int, pair<int, int>>> arr;
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,{b,c} });
	}
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int temp = min(abs(v[i].first - v[j].first), min(abs(v[i].second.first), abs(v[i].second.second)));
				arr.push_back({ temp,{i,j} });
			}
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		if (sameParent(arr[i].second.first, arr[i].second.second) == false) {
			Union(arr[i].second.first, arr[i].second.second);
			sum += arr[i].first;
		}
	}
	*/
	return 0;
}
