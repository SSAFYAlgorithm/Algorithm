#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int result[10001];
vector<pair<int, pair<int, int>>> arr;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int getParent(int x) {
	if (result[x] == x)
		return x;
	return result[x] = getParent(result[x]);
}

int find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return 1;
	else
		return 0;
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b)
		result[b] = a;
}

int main() {
	int v, e, a, b, c;
	int sum = 0;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr.push_back({ c,{a,b} });
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i <= v; i++) {
		result[i] = i;
	}

	for (int i = 0; i < e; i++) {
		if (find(arr[i].second.first, arr[i].second.second) == false) {
			Union(arr[i].second.first, arr[i].second.second);
			sum += arr[i].first;
		}
	}

	cout << sum;

	return 0;
}