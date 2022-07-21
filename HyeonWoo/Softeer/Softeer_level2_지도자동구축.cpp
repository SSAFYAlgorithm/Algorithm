#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	int n;
	int arr[16] = { 0 };
	cin >> n;
	arr[0] = 2;
	for (int i = 1; i <= 15; i++) {
		arr[i] = arr[i - 1] + (arr[i - 1] - 1);
	}

	cout << arr[n] * arr[n];
	return 0;
}