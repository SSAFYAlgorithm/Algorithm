#include <iostream>
#include <vector>
#include <cstring>
#include<string>

using namespace std;
int n, m;
int arr[21][21];

int find(int y, int x, int k)
{
    int cnt = 0;
    for (int i = y - k + 1; i <= y + k - 1;i++) {
        for (int j = x - k + 1;j <= x + k - 1;j++) {
            if (abs(i + j - x - y) <= k - 1) {
                if (i < 0 || j < 0 || i >= n || j >= n)continue;
                if (arr[i][j] == 1) {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int solve()
{
    cin >> n >> m;
    memset(arr, 0, sizeof(arr));
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
            if (arr[i][j])cnt++;
        }
    }
    int k = 1;
    int maxCnt = -1;
    for (int k = 1; k <= n + 1; k++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                int now = find(i, j, k);
                if (pow(k, 2) - pow(k - 1, 2) < now * m) {
                    if (now > maxCnt) {
                        maxCnt = now;
                    }

                }
            }
        }
    }
    int answer = maxCnt;
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    cin >> test;
    for (int t = 1;t < test + 1;t++) {
        cout << "#" << t << " " << solve() << endl;

    }
    return 0;

}