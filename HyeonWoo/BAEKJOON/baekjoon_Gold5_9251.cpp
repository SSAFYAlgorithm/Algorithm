#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string str1, str2;
int dp[1005][1005];


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> str1 >> str2;

    for (int y = 1; y <= str1.size(); y++) {
        for (int x = 1; x <= str2.size(); x++) {
            if (str1[y-1] == str2[x-1]) {
                if (y == 0 || x == 0) {
                    dp[y][x] = 1;
                }
                else {
                    dp[y][x] = dp[y - 1][x - 1] + 1;
                }
            }
            else {
                dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
            }
        }
    }
    cout << dp[str1.size()][str2.size()];
    
    
    return 0;
}