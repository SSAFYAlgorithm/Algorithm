#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int n, m;
	vector<pair<int, int>> line;
	cin >> n >> m;
	int k = n / 6; //몫
	int o = n % 6; //나머지
	int temp1 = 0, temp2 = 0, temp3 = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a,b });
	}

	//패키지 전부 구매
	sort(line.begin(), line.end());
	temp1 = line[0].first * (k + 1);

	//섞어서 구매
	temp2 = line[0].first * k;
	sort(line.begin(), line.end(), cmp);
	temp2 += line[0].second * o;

	//전부 낱개
	temp3 = line[0].second * n;

	cout << min(min(temp1, temp2), temp3);

	return 0;
}