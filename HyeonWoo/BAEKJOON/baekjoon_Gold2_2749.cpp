#include <iostream>
#include <cmath>
using namespace std;

// 피사노 주기 (피보나치 수열은 항상 주기를 가진다)
// M = 10^k 일경우 주기는 항상 15*10^(k-1)


unsigned long long M = 1000000;
unsigned long long K;
unsigned long long N;
unsigned long long JuGi;
unsigned long long dp[1500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N;
	K = 6;

	JuGi = 15 * pow(10, K - 1);
	// 주기까지의 피보나치 수열을 구합니다
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < JuGi; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % M;
	}
	
	cout << dp[N % JuGi];



	return 0;
}