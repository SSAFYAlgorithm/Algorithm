#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[10] = { 0 };
int sosu(int level)
{

	int now = 0;
	for (int i = 0;i <= level; i++) {
		if (!arr[i])return 0;
		now += arr[i];
		now *= 10;
	}
	now /= 10;

	for (int i = 2;i <= now / 2; i++) {
		if (now % i == 0)return 0;
	}
	return 1;
}
void dfs(int level)
{
	if (level == n) {
		//if (!sosu(n - 1))return;
		for (int i = 0;i < n;i++) {
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0;i <= 9;i++) {
		arr[level] = i;
		if (arr[0] == 0 || arr[0] == 1)continue;
		if (!sosu(level))continue;
		dfs(level + 1);
	}
}

void solve()
{
	dfs(0);

}
int main()
{
	cin >> n;
	solve();
}