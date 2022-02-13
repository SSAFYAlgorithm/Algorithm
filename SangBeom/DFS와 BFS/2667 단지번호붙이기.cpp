#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int arr[26][26];
bool check[26][26] = { 0 };
vector<int> countArr;
int cnt = 0;
int n;
void dfs(int y, int x)
{
	if (!check[y][x]) {
		cnt++;
	}
	check[y][x] = 1;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	for (int i = 0;i < 4;i++) {
		int tempX = dx[i] + x;
		int tempY = dy[i] + y;
		if (!(tempX < 0 || tempY < 0 || tempX >= n || tempY >= n)) {
			if (arr[tempY][tempX]) {
				if (!check[tempY][tempX]) {
					dfs(tempY, tempX);
				}
			}
		}
	}
}
int main()
{
	cin >> n;

	for (int i = 0;i < n;i++) {
		string num;
		cin >> num;
		for (int j = 0;j < n;j++) {
			arr[i][j] = (int)(num[j] - '0');
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j]) {
				dfs(i, j);
				if (cnt > 0) {
					countArr.push_back(cnt);
					cnt = 0;
				}
			}
		}
	}
	sort(countArr.begin(), countArr.end());
	cout << countArr.size() << '\n';
	for (int i = 0;i < countArr.size();i++) {
		cout << countArr[i] << '\n';
	}
}