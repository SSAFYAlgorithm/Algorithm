#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;

int n, m, res;
int arr[1010][1010];
int dp[1010][1010];
int dy[3] = { 0,-1,-1 };
int dx[3] = { -1,-1,0 };

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> n >> m;
    for (int y = 1; y <= n; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < m; x++) {
            arr[y][x+1] = (int)(temp[x] - '0');
        }
    }

    memcpy(dp, arr, sizeof(arr));

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (dp[y][x] != 0)  {
                // dp[i][j] = 최소값 +1의 제곱을 가져올 수 있음 => 그려보면 이해가능
                int l = dp[y + dy[0]][x + dx[0]];
                int lu = dp[y + dy[1]][x + dx[1]];
                int u = dp[y + dy[2]][x + dx[2]];
                
                dp[y][x] = min({ l,lu,u }) + 1;

                if (dp[y][x] > res) {
                    res = dp[y][x];
                }
            }
        }
    }
    
    cout << res*res;
    
    return 0;
}