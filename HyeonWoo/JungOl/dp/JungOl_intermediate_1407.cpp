#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string str;
int dp[100];

void BottomUp() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    if (str.size() > 1) {
        if (stoi(str.substr(0, 2)) <= 34) {
            dp[1] = 2;
        }
        else {
            dp[1] = 1;
        }
        for (int i = 2; i < str.size(); i++) {
            int num = stoi(str.substr(i - 1, 2));
            if (num == 10 || num == 20 || num == 30) {
                dp[i] = dp[i-2];
            }
            else if (num <= 34 && num>=10) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
    }

    cout << dp[str.size() - 1];

}

int TopDown(int n) {
    if (n == 0) {
        dp[n] = 1;
        return dp[n];
    }
    else if (n == 1) {
        if (stoi(str.substr(0, 2)) <= 34) {
            dp[n] = 2;
        }
        else {
            dp[n] = 1;
        }
        return dp[n];
    }
    if (dp[n] > 0) {
        return dp[n];
    }

    int a = TopDown(n - 2);
    int b = TopDown(n - 1);
    int num = stoi(str.substr(n - 1, 2));
    if (num == 10 || num == 20 || num == 30) {
        dp[n] = a;
    }
    else if (num <= 34 && num>=11) {
        dp[n] = a+b;
    }
    else {
        dp[n] = b;
    }
    return dp[n];

}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            if (stoi(str.substr(i - 1, 2)) >= 35) {
                cout << 0;
                    return 0;
            }
        }
    }
    BottomUp();
    memset(dp, 0, sizeof(dp));
    //cout << TopDown(str.size()-1);

    return 0;
}