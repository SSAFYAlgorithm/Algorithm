#include <iostream>
#include <cmath>

using namespace std;

int T;
int K;
int set[4][8];
int num;
int direct;

// 각 배열의 2번 - 6번 맞닿아 있음
void clockwise(int n) {
	int temp = set[n][7];
	for (int i = 6; i >= 0; i--) {
		set[n][i + 1] = set[n][i];
	}
	set[n][0] = temp;
}
void counterClockwise(int n) {
	int temp = set[n][0];
	for (int i = 0; i < 7; i++) {
		set[n][i] = set[n][i + 1];
	}
	set[n][7] = temp;
}

int main() {
	cin >> T;
	for (int j = 1; j <= T; j++) {
		cin >> K;
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 8; x++) {
				cin >> set[y][x];
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> num >> direct;
			if (num == 1) {
				if (set[num - 1][2] != set[num][6]) {
					if (set[num][2] != set[num + 1][6]) {
						if (set[num + 1][2] != set[num + 2][6]) {
							if (direct == -1)clockwise(3);
							else if (direct == 1)counterClockwise(3);
						}
						if (direct == 1)clockwise(2);
						else if (direct == -1)counterClockwise(2);
					}
					if (direct == -1)clockwise(1);
					else if (direct == 1)counterClockwise(1);
				}
				if (direct == 1)clockwise(0);
				else if (direct == -1)counterClockwise(0);
			}
			else if (num == 2) {
				if (set[num - 1][6] != set[num - 2][2]) {
					if (direct == -1)clockwise(0);
					else if (direct == 1)counterClockwise(0);
				}
				if (set[num - 1][2] != set[num][6]) {
					if (set[num][2] != set[num + 1][6]) {
						if (direct == 1)clockwise(3);
						else if (direct == -1)counterClockwise(3);
					}
					if (direct == -1)clockwise(2);
					else if (direct == 1)counterClockwise(2);
				}
				if (direct == 1)clockwise(1);
				else if (direct == -1)counterClockwise(1);
			}
			else if (num == 3) {
				if (set[num - 1][2] != set[num][6]) {
					if (direct == -1)clockwise(3);
					else if (direct == 1)counterClockwise(3);
				}
				if (set[num - 1][6] != set[num - 2][2]) {
					if (set[num - 2][6] != set[num - 3][2]) {
						if (direct == 1)clockwise(0);
						else if (direct == -1)counterClockwise(0);
					}
					if (direct == -1)clockwise(1);
					else if (direct == 1)counterClockwise(1);
				}
				if (direct == 1)clockwise(2);
				else if (direct == -1)counterClockwise(2);
			}
			else if (num == 4) {
				if (set[num - 1][6] != set[num - 2][2]) {
					if (set[num - 2][6] != set[num - 3][2]) {
						if (set[num - 3][6] != set[num - 4][2]) {
							if (direct == -1)clockwise(0);
							else if (direct == 1)counterClockwise(0);
						}
						if (direct == 1)clockwise(1);
						else if (direct == -1)counterClockwise(1);
					}
					if (direct == -1)clockwise(2);
					else if (direct == 1)counterClockwise(2);
				}
				if (direct == 1)clockwise(3);
				else if (direct == -1)counterClockwise(3);
			}
		}
		int sum = 0;
		for (int y = 0; y < 4; y++) {
			sum += pow(2, y) * set[y][0];
		}
		cout << "#" << j << " " << sum << endl;
	}


	return 0;
}