#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
9%
dfs 없이 풀수있나
*/
int n;
int check[100000];
vector<int>vect;
vector<int>mem;
vector<int>res;
int cnt = 0;
int m = 210000000;
void dfs(int level)
{
	if (level == n) {
		//check결정 토글
		cnt = 0;
		for (int i = 0;i < n;i++) {
			if (check[i] == 1) {
				for (int j = 0;j < 3;j++) {
					int d[3] = { -1,0,1 };
					int temp = d[j] + i;
					if (temp < 0 || temp >= n)continue;
					vect[temp] = 1 - vect[temp];
				}
				cnt++;
			}
		}
		if (res == vect) {
			if (m > cnt) {
				m = cnt;
			}
		}
		vect = mem;
		return;
	}
	for (int i = 0;i < 2;i++) {
		check[level] = i;
		dfs(level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string num;
	cin >> num;
	string ans;
	cin >> ans;

	for (int i = 0;i < n;i++) {
		vect.push_back((int)(num[i] - '0'));
		mem.push_back((int)(num[i] - '0'));
		res.push_back((int)(ans[i] - '0'));
	}
	//t=i-t; ,dfs
	dfs(0);

	if (m == 210000000) {// 불가능
		cout << -1;
	}
	else
		cout << m;
}
