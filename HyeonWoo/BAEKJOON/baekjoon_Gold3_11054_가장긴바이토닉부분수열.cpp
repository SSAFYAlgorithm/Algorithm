#include <iostream>
#include <algorithm>
using namespace std;

int n,res;
int arr[1001];
int dp[1010][3];



int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    // 0번 인덱스는 해당인덱스 이전까지의 LIS 1번은 해당 인덱스 이후부터 끝까지의 내림차순 LIS
    // 0번인덱스부터 구해준다
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] <= arr[j]) continue;
            dp[i][0] = max(dp[i][0], dp[j][0] + 1);
        }
    }

    // 1번인덱스 구해준다
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i][1] = max(dp[i][1], dp[j][1] + 1);
        }
    }

    // 2번인덱스에는 총 바이토닉 수열개수를 적어줌 (올림 내림 둘다 자기자신 포함하기때문에 1빼줬음)
    for (int i = 1; i <= n; i++) {
        dp[i][2] = dp[i][0] + dp[i][1] - 1;
        if (dp[i][2] > res) {
            res = dp[i][2];
        }
    }
    cout << res;

    
    
    return 0;
}