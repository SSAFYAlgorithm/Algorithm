#include<iostream>
#include<vector>
using namespace std;


int n, m;
vector<int>res(9, 0);
vector<bool>check(9, 0);
void dfs(int depth)
{
	if (depth == m) {
		for (int i = 0;i < m;i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++) {
		if (!check[i])
		{
			check[i] = true;
			res[depth] = i;
			dfs(depth + 1);
			check[i] = false;
		}
	}
}



int main()
{
	cin >> n >> m;
	dfs(0);
}