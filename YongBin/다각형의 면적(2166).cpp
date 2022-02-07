#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<double, double>> v;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	return res / 2;
}

int main() {
	double n, a, b;
	double result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 1; i < n; i++) {
		result += ccw(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);
	}
	printf("%.1lf", abs(result));
	return 0;
}