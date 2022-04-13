#include <iostream>
#include <vector>
using namespace std;

// 아이디어 메모리, 시간복잡도 때문에 2시간걸린 문제 ㅠㅠ

int a, b, d, N;
int dp[1000000];

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> a >> b >> d >> N;
    // 초기화
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        // 새끼낳는 구간 합부터 구해준다

        // dp[i-a] - dp[i-b] : a가 성체가 되는날 b는 새끼 못 낳는 날
        // b아래부터는 새끼를 못낳기 때문에 이 사이 수만큼만 새끼를 낳을 수 있다.
        // d는 아직 고려하지 않고 쌓아준다.
        if (i < a) {
            dp[i] = (dp[i - 1] + 1000) % 1000;
        }
        else if (i < b) {
            dp[i] = (dp[i - 1] + dp[i - a] + 1000) % 1000;
        }
        else {
            dp[i] = (dp[i - 1] + dp[i - a] - dp[i - b] + 1000) % 1000;
        }
    }
    // d이전의 날짜의 dp값에는 이미 죽은 애들이 들어있을 것이다.
    if (N - d >= 0) {
        dp[N] = (dp[N]+1000 - dp[N - d])%1000;
    }
    cout << dp[N];
    return 0;
}
