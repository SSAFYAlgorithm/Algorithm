#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[30][30];
int res;
int Move[30][30];
struct Node {
	int y;
	int x;
};

// flag = 1 이전에 우 flag = 2 이전에 대각선 flag 3 이전에 밑
void DFS(int y, int x, int flag) {
	if (flag == 2 && (arr[y - 1][x] == 1 || arr[y][x - 1] == 1)) {
		return;
	}
	if (arr[y][x] == 1) {
		return;
	}
	if (y == n && x == n) {
		res++;
		return;
	}
	if (y <= 0 || x <= 0 || y > n || x > n) {
		return;
	}
	


	// 밑으로갈때 (3)
	if (flag == 2 || flag == 3) {
		Move[y + 1][x] = 1;
		DFS(y + 1, x, 3);
		Move[y + 1][x] = 0;
	}

	// 대각선으로 갈때(2)
	Move[y + 1][x+1] = 1;
	DFS(y + 1, x + 1, 2);
	Move[y + 1][x+1] = 0;
	
	// 우로갈때 (1) (flag == 1, flag == 2)
	if (flag == 1 || flag == 2) {
		Move[y][x+1] = 1;
		DFS(y, x + 1, 1);
		Move[y][x + 1] = 0;
	}
	return;
}

int main() {
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	DFS(1, 2, 1);
	cout << res;
	
	

	return 0;
}