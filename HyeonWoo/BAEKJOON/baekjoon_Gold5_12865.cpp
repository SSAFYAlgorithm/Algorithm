#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
int dp[101][100001];
int W[101];
int V[101];
int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N >> K;
    for(int i=1; i<=N;i++){
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j < W[i]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i-1][j - W[i]] + V[i]);
            }
        }
    }
    cout << dp[N][K];
    return 0;
}
