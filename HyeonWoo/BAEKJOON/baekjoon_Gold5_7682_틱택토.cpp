#include <iostream>
#include <cstring>
using namespace std;

string input;
int arr[3][3];

int winX() {
	// 대각선
	if (arr[1][1] == arr[0][0] && arr[0][0] == arr[2][2] && arr[1][1] == 1) {
		return 1;
	}
	if (arr[1][1] == arr[2][0] && arr[1][1] == arr[0][2] && arr[1][1] == 1) {
		return 1;
	}
	
	// 가로
	if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] == 1) {
		return 1;
	}
	if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] == 1) {
		return 1;
	}
	if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] == 1) {
		return 1;
	}

	// 세로
	if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] == 1) {
		return 1;
	}
	if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] == 1) {
		return 1;
	}
	if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] == 1) {
		return 1;
	}
	return 0;
}

int winO() {
	// 대각선
	if (arr[1][1] == arr[0][0] && arr[0][0] == arr[2][2] && arr[1][1] == 2) {
		return 2;
	}
	if (arr[1][1] == arr[2][0] && arr[1][1] == arr[0][2] && arr[1][1] == 2) {
		return 2;
	}

	// 가로
	if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] == 2) {
		return 2;
	}
	if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] == 2) {
		return 2;
	}
	if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] == 2) {
		return 2;
	}

	// 세로
	if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] == 2) {
		return 2;
	}
	if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] == 2) {
		return 2;
	}
	if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] == 2) {
		return 2;
	}
	return 0;
}
int isValid() {
	// X수가 O수보다 1개 많으면 일단 가능
	int flag = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (arr[y][x] == 0) {
				flag = 1;
			}
			else if (arr[y][x] == 1) {
				cnt1++;
			}
			else if (arr[y][x] == 2) {
				cnt2++;
			}
		}
	}
	// 0이 없을때 X만이기거나 무승부
	if (!flag) {
		if (winX()) {
			if (winO()) return 0;
			if (cnt1 == cnt2 + 1) return 1;
		}
		if (winO()) {
			return 0;
		}
		// 이긴사람이 없더라도 cnt1이 cnt2+1이면 가능
		if (cnt1 == cnt2 + 1) return 1;
		else return 0;
	}
	// 0이 존재한다면 누가 이겼는지확인
	else {
		if (winX()) {
			if (winO()) return 0;
			if (cnt1 == cnt2 + 1) return 1;
			else return 0;
		}
		if (winO()) {
			if (cnt1 == cnt2) return 1;
			if (winX()) return 0;
		}
		// 승자가 없으면 유효하지 않다
		else {
			return 0;
		}
	}
	return 0;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	while (1) {
		memset(arr, 0, sizeof(arr));
		cin >> input;
		if (input == "end") break;
		int y = 0;
		int x = 0;
		// O : 1  /  X : 2  /  . : 0
		for (int i = 0; i < 9; i++) {
			if (input[i] == 'X') {
				arr[y][x] = 1;
			}
			else if (input[i] == 'O') {
				arr[y][x] = 2;
			}
			x++;
			if (x == 3) {
				x = 0;
				y++;
			}
		}
		if (isValid()) {
			cout << "valid\n";
		}
		else {
			cout << "invalid\n";
		}

		
	}
	return 0;
}