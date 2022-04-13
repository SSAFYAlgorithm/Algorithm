#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
long long dp[1000005];


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = ((dp[i - 1]%15746) + (dp[i - 2]%15746))%15746;
    }
    cout << dp[N];

    return 0;
}