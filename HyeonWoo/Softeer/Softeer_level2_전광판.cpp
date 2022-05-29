#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int boardA[5][7];
int boardB[5][7];
void changeBoard(string NUM , int type) { // type == 0이면 A 아니면 B
	int board[5][7] = { 0 };
	int s = 0;
	if (NUM.size() < 5) {
		s = 5 - NUM.size();
	}
	for (int i = s; i < 5; i++) {
		if (NUM[i-s] == '0') {
			for (int j = 0; j <= 6; j++) {
				if (j == 3) continue;
				board[i][j] = 1;
			}
		}
		else if (NUM[i - s] == '1') {
			board[i][2] = 1;
			board[i][5] = 1;
		}
		else if (NUM[i - s] == '2') {
			board[i][0] = 1;
			board[i][2] = 1;
			board[i][3] = 1;
			board[i][4] = 1;
			board[i][6] = 1;
		}
		else if (NUM[i - s] == '3') {
			board[i][0] = 1;
			board[i][2] = 1;
			board[i][3] = 1;
			board[i][5] = 1;
			board[i][6] = 1;
		}
		else if (NUM[i - s] == '4') {
			board[i][1] = 1;
			board[i][3] = 1;
			board[i][2] = 1;
			board[i][5] = 1;
		}
		else if (NUM[i - s] == '5') {
			board[i][0] = 1;
			board[i][1] = 1;
			board[i][3] = 1;
			board[i][5] = 1;
			board[i][6] = 1;
		}
		else if (NUM[i - s] == '6') {
			board[i][0] = 1;
			board[i][1] = 1;
			board[i][3] = 1;
			board[i][5] = 1;
			board[i][6] = 1;
			board[i][4] = 1;
		}
		else if (NUM[i - s] == '7') {
			board[i][0] = 1;
			board[i][1] = 1;
			board[i][2] = 1;
			board[i][5] = 1;
		}
		else if (NUM[i - s] == '8') {
			for (int j = 0; j <= 6; j++) {
				board[i][j] = 1;
			}
		}
		else if (NUM[i - s] == '9') {
			for (int j = 0; j <= 6; j++) {
				if (j == 4) continue;
				board[i][j] = 1;
			}
		}
	}

	if (!type) {
		memcpy(boardA, board, sizeof(board));
	}
	else {
		memcpy(boardB, board, sizeof(board));
	}
}

void CompareAB() {
	int res = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 7; x++) {
			if (boardA[y][x] != boardB[y][x]) res++;
		}
	}
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int tc = 0; tc < N; tc++) {
		string A, B;
		cin >> A >> B;

		changeBoard(A,0);
		changeBoard(B,1);

		CompareAB();
	}
	
	return 0;
}