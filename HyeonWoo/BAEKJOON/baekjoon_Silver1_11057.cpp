#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1001][10];

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])%10007;
        }
    }
    cout << dp[n][9];
    return 0;
}
