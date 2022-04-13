#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int N;
long long arr[100005];
long long dp[100005];

long long TopDown(int n) {
    if (n == 1 || n == 2) {
        dp[n] = 1;
        return 1;
    }
    if (dp[n] > 0) {
        return dp[n];
    }
    long long a = TopDown(n - 2) % 1000000007;
    long long b = TopDown(n - 1) % 1000000007;
    dp[n] = (a + b) % 1000000007;
    return dp[n];
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    
    cin >> N;
    cout << TopDown(N);
    
    
    return 0;
}