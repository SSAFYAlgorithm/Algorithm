#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long n;
long long b;
long long init[7][7];
long long arr[7][7];

void multi(long long A[][7], long long B[][7]) {
	long long Temparr[7][7] = { 0 };
	int r = 0;
	int c = 0;
	while (1) {
		long long SUM = 0;
		for (int i = 0; i < n; i++) {
			SUM += ( A[r][i] * B[i][c] );
		}
		Temparr[r][c] = SUM % 1000;
		c++;
		if (c == n) {
			c = 0;
			r++;
		}
		if (r == n) {
			break;
		}
	}
	memcpy(arr, Temparr, sizeof(arr));
}


void dfs (long long N) {
	if (N == 1) {
		return;
	}

	if (N % 2 == 1) {
		dfs(N / 2);
		multi(arr,arr);
		multi(arr, init);
	}
	else {
		dfs(N / 2);
		multi(arr, arr);
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> init[i][j];
			arr[i][j] = init[i][j] % 1000;
		}
	}
	
	dfs(b);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}