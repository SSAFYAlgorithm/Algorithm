#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int N;
int arr[100005];
int dp[100005];

int TopDown(int n) {
    if (n == 2) {
        dp[n] = 3;
        return 3;
    }
    else if (n == 1) {
        dp[n] = 1;
        return 1;
    }

    if (dp[n] > 0) {
        return dp[n];
    }

    int a = TopDown(n - 1) % 20100529;
    int b = TopDown(n - 2) % 20100529;
    dp[n] = (a + b * 2) % 20100529;
    return dp[n];
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);

    cin >> N;
    cout << TopDown(N);


    return 0;
}