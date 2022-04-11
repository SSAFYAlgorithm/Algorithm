#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N;
int dp[350][3];
int arr[350];
void BottomUp() {
    memset(dp, 0, sizeof(dp));

    dp[1][1] = arr[1];
    dp[2][1] = dp[1][1] + arr[2];
    dp[2][2] = arr[2];
    for (int i = 3; i <= N; i++) {
        dp[i][1] = dp[i - 1][2] + arr[i];
        dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
    }
    
    cout << max(dp[N][1], dp[N][2]) << endl;
}



int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    BottomUp();

    return 0;
}