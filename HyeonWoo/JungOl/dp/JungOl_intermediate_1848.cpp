#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int N;
int dp[100005];
int Fix[100005];
int TopDown(int n) {
    if (n == 1) {
        dp[n] = 1;
        return 1;
    }
    else if (n == 2) {
        if (Fix[n] == 1 || Fix[n-1] == 1) {
            dp[n] = 1;
            return 1;
        }
        dp[n] = 2;
        return 2;
    }
    if (dp[n] > 0) {
        return dp[n];
    }

    int a = TopDown(n - 1);
    int b = TopDown(n - 2);
    dp[n] = a + b;
    if (Fix[n] == 1 || Fix[n - 1] == 1) {
        dp[n] = dp[n - 1];
        return dp[n];
    }
    return dp[n];

}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        Fix[tmp] = 1;
    }
    
    cout << TopDown(N);


    return 0;
}