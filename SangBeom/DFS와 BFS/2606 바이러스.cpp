#include<iostream>
#include<queue>

using namespace std;
int node;//정점
int v;//간선
int arr[101][101] = { 0 };
bool check[101] = { 0 };
int cnt = -1;
int flag;
void dfs(int level)
{
	check[level] = true;
	flag = 0;
	cnt++;
	for (int i = 1;i <= node;i++) {
		if (arr[level][i] == 1) {
			if (!check[i]) {
				flag = 1;
				dfs(i);
			}
		}
	}
	if (!flag) {
		return;
	}

}


int main()
{
	cin >> node;
	cin >> v;

	for (int i = 0;i < v;i++) {
		int start, end;
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}
	dfs(1);
	cout << cnt;
}