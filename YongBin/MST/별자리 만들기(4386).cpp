#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<tuple<double, double, double>> v;
vector<pair<double, double>> star;
int parent[101];

int getParent(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = getParent(parent[a]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b)
		parent[b] = a;
}

bool sameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return true;
	return false;
}

double getDist(pair<double, double> a, pair<double, double> b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
	int n;
	double a, b;
	double ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		star.push_back({ a,b });
	}
	
	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			v.push_back({ getDist(star[i],star[j]), i,j });
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		double temp1 = get<0>(v[i]);
		double temp2 = get<1>(v[i]);
		double temp3 = get<2>(v[i]);
		if (sameParent(temp2, temp3) == false) {
			Union(temp2, temp3);
			ans += temp1;
		}
	}

	printf("%.2lf", ans);

	return 0;
}