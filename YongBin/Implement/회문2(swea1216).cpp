#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans = 0;
char arr[100][100];

void check1(int x, int y, int len) { // 가로
	int nx = x + len - 1;
	int flag = 0;
	while (1) {
		if (x > nx) {
			flag = 1;
			break;
		}

		if (arr[x][y] == arr[nx][y]) {
			x++;
			nx--;
		}
		else
			break;
	}
	if (flag == 1)
		ans = max(ans, len);
}

void check2(int x, int y, int len) { // 세로
	int ny = y + len - 1;
	int flag = 0;

	while (1) {
		if (y > ny) {
			flag = 1;
			break;
		}

		if (arr[x][y] == arr[x][ny]) {
			y++;
			ny--;
		}
		else
			break;
	}
	if (flag == 1)
		ans = max(ans, len);
}

int main() {
	for (int i = 1; i <= 10; i++) {
		int n;
		ans = 1;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		for (int k = 0; k < 100; k++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[k][j];
			}
		}

		for (int k = 0; k < 100; k++) {
			for (int j = 0; j < 100; j++) {
				for (int m = 2; m < 100; m++) { //길이
					if (j + m <= 100) //가로
						check2(k, j, m);
					if (k + m <= 100) //세로
						check1(k, j, m);
				}
			}
		}

		cout << "#" << i << " " << ans << "\n";
	}
	return 0;
}