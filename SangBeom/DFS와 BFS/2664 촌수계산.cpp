#include<iostream>
using namespace std;

int arr[101][101];
int check[101];
int n;
int p1, p2;
int flag;
int res;
void dfs(int from, int cnt)
{
	if (from == p2) {
		flag = 1;
		res = cnt;
		return;
	}
	for (int i = 1;i <= n;i++) {
		if (check[i])continue;
		if (arr[from][i] == 1) {
			check[i] = 1;
			dfs(i, cnt + 1);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	cin >> p1 >> p2;
	int k;
	cin >> k;
	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	check[p1] = 1;
	dfs(p1, 0);
	if (flag) cout << res;
	else cout << -1;
}