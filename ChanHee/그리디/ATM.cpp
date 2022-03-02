#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int line;
	cin >> line;
	vector <int> time;
	for (int i = 0; i < line; i++) {
		int a;
		cin >> a;
		time.push_back(a);
	}
	sort(time.begin(), time.end());
	int cnt = 0;
	for (int i = 0; i < line; i++) {
		cnt += (line - i) * time[i];
	}

	cout << cnt;
}
