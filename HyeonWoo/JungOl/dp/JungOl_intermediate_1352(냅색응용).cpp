#include <iostream>
#include <vector>
using namespace std;

int N; // 추의개수
int chu[100];

int M; // 구슬의 개수
int marble[100];

int dp[100][40001];

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> chu[i];
	}
	cin >> M;
	int Max = 0;
	for (int i = 1; i <= M; i++) {
		cin >> marble[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 40000; j++) {
			if (j == chu[i]) {
				dp[i][j] = 1;
			}
			if (dp[i - 1][abs(j - chu[i])] == 1 || dp[i - 1][abs(j + chu[i])] == 1 || dp[i - 1][j] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		int weight = marble[i];
		if (dp[N][weight] == 1) {
			cout << "Y" << " ";
		}
		else {
			cout << "N" << " ";
		}
	}

	return 0;
}
