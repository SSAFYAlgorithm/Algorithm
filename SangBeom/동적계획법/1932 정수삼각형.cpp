#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int arr[501][501] = { 0 };
int main() {
    int a;
    cin >> a;
    for (int i = 0;i < a;i++)
    {
        for (int j = 0;j <= i;j++)
        {
            int tri;
            cin >> tri;
            if (j == 0) {
                if (i == 0) {
                    arr[i][j] = tri;
                }
                else {
                    arr[i][j] = tri + arr[i - 1][j];
                }
            }
            else if (j == i) {
                arr[i][j] = tri + arr[i - 1][j - 1];
            }
            else {
                arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + tri;
            }

        }
    }
    int maxNum = -1;
    for (int i = 0;i < a;i++)
    {
        if (arr[a - 1][i] > maxNum) {
            maxNum = arr[a - 1][i];
        }
    }
    cout << maxNum;
}