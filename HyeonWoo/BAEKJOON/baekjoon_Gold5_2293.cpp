#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
int dp[10001];
int coin[101];

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j < coin[i]) continue;
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[K];
    return 0;
}
