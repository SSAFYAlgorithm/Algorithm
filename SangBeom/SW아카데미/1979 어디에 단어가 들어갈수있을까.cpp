#include<iostream>
#include<vector>
#include<string>
using namespace std;

int arr[16][16];
int n, k;

int word(int y, int x)
{
	if (arr[y][x] == 0) return 0;
	int cnt = 0;
	int sum = 0;
	for (int i = y;i < n;i++) {
		if (arr[i][x] == 0) break;
		cnt++;
	}
	if (y - 1 >= 0) {
		if (cnt == k && arr[y - 1][x] == 0)sum++;
	}
	else {
		if (cnt == k)sum++;
	}

	cnt = 0;
	for (int i = x;i < n;i++) {
		if (arr[y][i] == 0)break;
		cnt++;
	}

	if (x - 1 >= 0) {
		if (cnt == k && arr[y][x - 1] == 0)sum++;
	}
	else {
		if (cnt == k)sum++;
	}

	int de = -1;
	return sum;


}

int main()
{
	int t;
	cin >> t;
	for (int test = 0;test < t;test++) {
		cin >> n >> k;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cin >> arr[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cnt += word(i, j);
			}
		}
		cout << "#" << test + 1 << " " << cnt << "\n";
	}
}
