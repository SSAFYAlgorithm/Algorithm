#include <iostream>

using namespace std;

long long num[1000001] = { 0,1,2 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		num[i] = (num[i - 1] + num[i - 2]) % 15746;
	}


	cout << num[n] % 15746;

	return 0;
}