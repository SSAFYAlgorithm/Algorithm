#include <iostream>
#include <vector>

using namespace std;

int dat[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	else if (a < b && b < c) {
		if (dat[a][b][c] != 0)return dat[a][b][c];
		else return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		if (dat[a][b][c] != 0)return dat[a][b][c];
		else return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	for (a = 0; a < 21; a++) {
		for (b = 0; b < 21; b++) {
			for (c = 0; c < 21; c++) {
				dat[a][b][c] = w(a, b, c);
			}
		}
	}

	int a_in, b_in, c_in;
	while (1) {
		cin >> a_in >> b_in >> c_in;
		if (a_in == -1 && b_in == -1 && c_in == -1) break;
		cout << "w(" << a_in << ", " << b_in << ", " << c_in << ") = " << w(a_in, b_in, c_in) << "\n";
	}




	return 0;
}