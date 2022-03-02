#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> p;
int sum[1000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time;
		cin >> time;
		p.push_back(time);
	}
	sort(p.begin(), p.end());
	sum[0] = p[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + p[i];
	}
	int ans=0;
	for (int i = 0; i < n; i++) {
		ans += sum[i];
	}
	cout << ans;
	return 0;
}