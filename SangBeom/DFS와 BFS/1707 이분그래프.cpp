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

vector<int>vect[20001];
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
	for (int i = 0; i < vect[level].size();i++) {
		if (check[vect[level][i]] == 0) {
			if (check[level] == 1) {
				check[vect[level][i]] = -1;
			}
			else if (check[level] == -1) {
				check[vect[level][i]] = 1;
			}
			flag = 1;
			dfs(vect[level][i]);
		}
		if (check[level] == check[vect[level][i]]) {
			flag2 = 0;
			break;
		}
	}
	if (!flag)return;
}


int main()
{
	int K; //testcase
	cin >> K;
	for (int i = 0;i < K;i++) {
		cin >> V >> E;

		for (int j = 0;j < E;j++) {
			int from, to;
			cin >> from >> to;
			vect[from].push_back(to);
			vect[to].push_back(from);
		}
		for (int i = 1;i <= V;i++) {
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
		memset(vect, 0, sizeof(vect));
		memset(check, 0, sizeof(check));
	}
}