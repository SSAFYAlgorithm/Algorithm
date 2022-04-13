#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int SCV[3];
int dp[61][61][61]; // scv 각각 남은 체력일 때 횟수
int dmg[3] = { 9, 3, 1 };

int TopDown(int i, int j, int k) {
    

    // SCV의 피가 0이하로 떨어지면 0으로 세팅하고 나머지 두개를 위해서 TopDown 실행
    if (i < 0) return TopDown(0, j, k);
    if (j < 0) return TopDown(i, 0, k);
    if (k < 0) return TopDown(i, j, 0);

    // 3개다 0이되면 return 0
    if (i == 0 && j == 0 && k == 0) {
        return 0;
    }
    
    

    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    dp[i][j][k] = 21e8;
    dp[i][j][k] = min(dp[i][j][k], TopDown(i - 9, j - 3, k - 1) + 1);
    dp[i][j][k] = min(dp[i][j][k], TopDown(i - 9, j - 1, k - 3) + 1);
    dp[i][j][k] = min(dp[i][j][k], TopDown(i - 3, j - 9, k - 1) + 1);
    dp[i][j][k] = min(dp[i][j][k], TopDown(i - 3, j - 1, k - 9) + 1);
    dp[i][j][k] = min(dp[i][j][k], TopDown(i - 1, j - 9, k - 3) + 1);
    dp[i][j][k] = min(dp[i][j][k], TopDown(i - 1, j - 3, k - 9) + 1);
    return dp[i][j][k];

}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> SCV[i];
    }
    cout << TopDown(SCV[0], SCV[1], SCV[2]);
    
    return 0;
}