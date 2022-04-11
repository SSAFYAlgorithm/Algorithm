#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int price[1006];
int dp[1006];

int DFS(int n) {
    if (n == 0) {
        return 0;
    }

    if (dp[n] > 0) {
        return dp[n];
    }
    // i는 무슨 카드팩 n까지이므로 가능한 카드팩만 for문
    for (int i = 1; i <= n; i++) {
        int cnt1 = DFS(n - i)+price[i];
        int cnt2 = dp[n];
        // 이미 기록한것과 새로 구한값중 더 큰값을 저장
        dp[n] = max(cnt1, cnt2);
    }
    return dp[n];

}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }
    cout << DFS(N);

    return 0;
}