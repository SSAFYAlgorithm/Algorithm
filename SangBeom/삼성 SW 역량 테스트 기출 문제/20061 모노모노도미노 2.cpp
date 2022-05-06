#include<iostream>
using namespace std;
int N;
int green[7][5];
int blue[5][7];
int ans = 0;
void mvgreen(int x, int y, int t)
{
	int r = 0, c = y;
	int c2;
	if (t == 1) {
		while (r < 6)
		{
			r++;
			if (green[r][c])
				break;
		}
		green[r - 1][c] = 1;
	}
	else if (t == 2) {//x,y+1
		c2 = y + 1;
		while (r < 6) {
			r++;
			if (green[r][c] || green[r][c2])break;
		}
		green[r - 1][c] = 1;green[r - 1][c2] = 1;
	}
	else if (t == 3) {//x,y+1
		while (r < 6) {
			r++;
			if (green[r][c])break;
		}
		green[r - 1][c] = 1;green[r - 2][c] = 1;
	}
	int erase[6] = { 0 };
	for (int i = 2;i < 6;i++) {
		int cnt = 0;
		for (int j = 0;j < 4;j++) {
			if (green[i][j])cnt++;
		}
		if (cnt == 4) {
			erase[i] = 1; ans++;
			for (int j = 0;j < 4;j++) {
				green[i][j] = 0;
			}
		}
	}
	int a = 0; int index = -1;
	for (int i = 2;i < 6;i++) {
		if (erase[i]) {
			a++; index = i;
		}
	}
	if (a == 1) {
		for (int i = index;i >= 1;i--) {
			for (int j = 0;j < 4;j++) {
				green[i][j] = green[i - 1][j];
			}
		}
		for (int i = 0;i < 4;i++) {
			green[1][i] = 0;
		}
	}
	if (a == 2) {
		for (int i = index;i >= 2;i--) {
			for (int j = 0;j < 4;j++) {
				green[i][j] = green[i - 2][j];
			}
		}
		for (int i = 0;i < 2;i++) {
			for (int j = 0;j < 4;j++) {
				green[i][j] = 0;
			}
		}
	}
	int flag = 0;
	int index2 = -1;
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			if (green[i][j]) {
				flag = 1; index2 = i;break;
			}
		}
		if (flag)break;
	}
	if (index2 == 0) {
		for (int i = 5;i >= 2;i--) {
			for (int j = 0;j < 4;j++) {
				green[i][j] = green[i - 2][j];
			}
		}

	}
	if (index2 == 1) {
		for (int i = 5;i >= 2;i--) {
			for (int j = 0;j < 4;j++) {
				green[i][j] = green[i - 1][j];
			}
		}
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			green[i][j] = 0;
		}
	}
}
void mvblue(int x, int y, int t)
{
	int r = x, c = 0;
	int r2;
	if (t == 1) {
		while (c < 6)
		{
			c++;
			if (blue[r][c])
				break;
		}
		blue[r][c - 1] = 1;
	}
	else if (t == 2) {//x,y+1
		while (c < 6) {
			c++;
			if (blue[r][c])break;
		}
		blue[r][c - 1] = 1;blue[r][c - 2] = 1;
	}
	else if (t == 3) {//x+1,y
		r2 = x + 1;
		while (c < 6) {
			c++;
			if (blue[r][c] || blue[r2][c])break;
		}
		blue[r][c - 1] = 1;blue[r2][c - 1] = 1;
	}
	int erase[6] = { 0 };
	for (int i = 2;i < 6;i++) {
		int cnt = 0;
		for (int j = 0;j < 4;j++) {
			if (blue[j][i])cnt++;
		}
		if (cnt == 4) {
			erase[i] = 1; ans++;
			for (int j = 0;j < 4;j++) {
				blue[j][i] = 0;
			}
		}
	}
	int a = 0; int index = -1;
	for (int i = 2;i < 6;i++) {
		if (erase[i]) {
			a++; index = i;
		}
	}
	if (a == 1) {
		for (int i = index;i >= 1;i--) {
			for (int j = 0;j < 4;j++) {
				blue[j][i] = blue[j][i - 1];
			}
		}
		for (int i = 0;i < 4;i++) {
			blue[i][1] = 0;
		}
	}
	if (a == 2) {
		for (int i = index;i >= 2;i--) {
			for (int j = 0;j < 4;j++) {
				blue[j][i] = blue[j][i - 2];
			}
		}
		for (int i = 0;i < 2;i++) {
			for (int j = 0;j < 4;j++) {
				blue[j][i] = 0;
			}
		}
	}
	int flag = 0;
	int index2 = -1;
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			if (blue[j][i]) {
				flag = 1; index2 = i;break;
			}
		}
		if (flag)break;
	}
	if (index2 == 0) {
		for (int i = 5;i >= 2;i--) {
			for (int j = 0;j < 4;j++) {
				blue[j][i] = blue[j][i - 2];
			}
		}

	}
	if (index2 == 1) {
		for (int i = 5;i >= 2;i--) {
			for (int j = 0;j < 4;j++) {
				blue[j][i] = blue[j][i - 1];
			}
		}
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			blue[j][i] = 0;
		}
	}
}
void solve()
{
	for (int i = 0;i < N;i++) {
		int t, x, y;
		cin >> t >> x >> y;
		mvgreen(x, y, t);
		mvblue(x, y, t);
	}
	cout << ans << '\n';
	int sum = 0;
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 4;j++) {
			if (green[i][j])sum++;
		}
	}
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 6;j++) {
			if (blue[i][j])sum++;
		}
	}
	cout << sum;
}
int main()
{
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	solve();
}