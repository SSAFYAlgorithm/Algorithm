#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

vector<pair<int, int>> v;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	int nowe = v[0].second;
	for (int i = 1; i < n; i++) {
		if (nowe <= v[i].first) {
			cnt++;
			nowe = v[i].second;
		}
	}
	
	cout << cnt;

	return 0;
}