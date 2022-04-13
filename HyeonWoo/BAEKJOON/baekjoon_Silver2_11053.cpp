#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int arr[1005];
int dp[1005];

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int last_value = 0;
    int res = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(dp[i], res);
    }
    cout << res ;
    
    
    return 0;
}