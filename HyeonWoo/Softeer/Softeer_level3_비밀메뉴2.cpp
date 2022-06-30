#include <iostream>
#include <cstring>
using namespace std;

int N, M, K;
//string str1; // 길이가 작은거
//string str2; // 길이가 큰거
int flag;
int res;
int arr1[3001];
int arr2[3001];
int dp[3001][3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> K;
	// 시간초과 났음
	/*if (N < M) {
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			str1 += temp;
		}
		for (int i = 0; i < M; i++) {
			string temp;
			cin >> temp;
			str2 += temp;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			str2 += temp;
		}
		for (int i = 0; i < M; i++) {
			string temp;
			cin >> temp;
			str1 += temp;
		}
	}

	for (int Cnt = str1.size(); Cnt >= 1; Cnt--) {
		if (flag) break;
		for (int i = 0; i <= str1.size() - Cnt; i++) {
			string CutStr = str1.substr(i, Cnt);
			if (str2.find(CutStr) != str2.npos) {
				res = Cnt;
				flag = 1;
				break;
			}
		}
	}
	if (!flag) {
		cout << 0;
	}
	else {
		cout << res;
	}*/

	for (int i = 1; i <= N; i++) {
		cin >> arr1[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> arr2[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr1[i] == arr2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(dp[i][j], res);
			}
		}
	}
	cout << res;
	return 0;
}