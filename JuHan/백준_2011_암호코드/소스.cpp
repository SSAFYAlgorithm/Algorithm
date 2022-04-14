#include <iostream>
#include <string>

using namespace std;

long long dp[5001];
int mod = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
 
    dp[0] = 1;
    dp[1] = 1;
    if ((input[0] - '0') == 0) cout << 0;
    else {
        for (int i = 2; i <= input.length(); i++) {
            if ((input[i - 1] - '0') > 0) {
                dp[i] = dp[i - 1] % mod;
            }
            int x = (input[i - 2] - '0') * 10 + (input[i - 1] - '0');
            if (10 <= x && x <= 26) {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
        }
        cout << dp[input.length()];
    }


     return 0;
}