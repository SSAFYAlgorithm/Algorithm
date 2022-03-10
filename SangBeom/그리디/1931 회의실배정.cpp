#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main()
{
	vector<pair<int, int>>vect;
	int a;
	cin >> a;

	for (int i = 0;i < a;i++) {
		int first, last;
		cin >> first >> last;
		vect.push_back(pair<int, int>(first, last));
	}

	sort(vect.begin(), vect.end(), cmp);
	int cnt = 1;
	int now = vect[0].second;
	for (int i = 1;i < a;i++) {
		if (now <= vect[i].first) {
			cnt++;
			now = vect[i].second;
		}
	}
	cout << cnt;
}