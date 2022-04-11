#include <iostream>

using namespace std;


int mem[41][2] = {
	1,0,
	0,1,
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int y = 2; y < 41; y++) {
		mem[y][0] = mem[y - 1][0] + mem[y - 2][0];
		mem[y][1] = mem[y - 1][1] + mem[y - 2][1];
	}

	int times;
	cin >> times;
	for (int i = 0; i < times; i++) {
		int n;
		cin >> n;
		for (int x = 0; x < 2; x++) {
			cout << mem[n][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}