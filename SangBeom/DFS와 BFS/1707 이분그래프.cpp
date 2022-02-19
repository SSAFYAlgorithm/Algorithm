#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
1
5 4
1 2
3 4
4 5
3 5
NO
*/

int arr[20001][20001] = { 0 };
int check[20001] = { 0 };
//vector<int>check(20001);
int V, E;	//정점,간선
int flag;
int flag2 = 1;
void dfs(int level) {

	flag = 0;
	if (check[level] == 0) {
		check[level] = 1;
	}
	for (int i = 1;i <= V;i++) {
		if (arr[level][i]) {
			if (check[i] == 0) {
				if (check[level] == 1) {
					check[i] = -1;
				}
				if (check[level] == -1) {
					check[i] = 1;
				}
				flag = 1;
				dfs(i);

			}
			if (check[i] == check[level]) {
				flag2 = 0;
				break;
			}
		}
	}
	if (!flag) return;

}


int main()
{
	int K; //testcase
	cin >> K;
	for (int i = 0;i < K;i++) {
		cin >> V >> E;
		for (int j = 0;j < E;j++) {
			int u, v;
			cin >> u >> v;
			arr[u][v] = 1;
			arr[v][u] = 1;
		}
		for (int i = 1;i < V;i++) {
			if (check[i] == 0) {
				dfs(i);
			}
		}

		if (flag2) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		flag2 = 1;
		/*
		for (int i = 0;i < E;i++) {
			for (int j = 0;j < E;j++) {
				arr[i][j] = 0;
			}
			check[i] = 0;
		}
		*/
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(arr));
	}
}