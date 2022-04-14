#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

string arr;
int dp[5010];
// dp 알고리즘
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> arr;
	// 첫번째는 무조건 1개 (0이면 0) , 0이면 무조건 불가능
	if (arr[0] == '0') {
		cout << 0;
		return 0;
	}
	else {
		dp[1] = 1;
	}

	// 두번째 경우도 미리 초기화
	if (arr.size() >= 2) {
		int two = arr[1] - '0';
		int one = arr[0] - '0';
		int num12 = one * 10 + two;
		if (two == 0) {
			if (num12 > 26) {
				cout << 0;
				return 0;
			}
			else {
				dp[2] = 1;
			}
		}
		else {
			if (num12 > 26) {
				dp[2] = 1;
			}
			else {
				dp[2] = 2;
			}
		}

		// 3번부터 for문
		for (int i = 3; i <= arr.size(); i++) {
			int now = arr[i - 1] - '0';
			int last = arr[i - 2] - '0';
			int num = last * 10 + now;
			if (now == 0) {
				if (num <= 26 && num>0) {
					// 0이오는경우는 i-2 경우에 십의자리 하나를 붙힌것과 같기 때문에
					dp[i] = dp[i - 2];
				}
			}
			else {
				// last가 0인경우도 존재 이경우 직전의 경우에 1의자리 하나만 붙힌것만 인정
				if (last == 0) {
					dp[i] = dp[i - 1];
				}
				// last와 now가 둘다 0이 아닌 경우
				else {
					if (num <= 26) {
						dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
					}
					else {
						dp[i] = dp[i - 1];
					}
				}
			}
		}
	}

	cout << dp[arr.size()];
	
	
	return 0;
}