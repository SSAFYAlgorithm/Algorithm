#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

char arr[51][51];
bool visited[51][51] = { 0 };
int height[51][51];
int Knum = 0;
int Kcount = 0;
int n;
int startX, startY;
vector<int>uniqueHeight;
vector<int>piro;

int dfs(int y, int x, int left, int right)
{
    if (height[startY][startX] != right) return 0;

    if (arr[y][x] == 'K') {
        Kcount++;

        if (Kcount == Knum) {

            return 1;
        }
    }

    int dx[8] = { -1,0,1,-1,1,-1,0,1 };
    int dy[8] = { -1,-1,-1,0,0,1,1,1 };
    for (int i = 0;i < 8;i++) {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
        if (visited[ty][tx] == true)continue;
        if (height[ty][tx]<left && height[ty][tx]>right)continue;
        visited[ty][tx] = 1;
        dfs(ty, tx, left, right);
        visited[ty][tx] = 0;

        if (arr[ty][tx] == 'K') {
            Kcount--;
        }

    }

    return 0;
}
int compareTwo(int y, int x)
{
    int left = 0;
    int right = 0;
    int a = dfs(y, x, uniqueHeight[left], uniqueHeight[right]);//0으로만 갈수있을때
    if (a == 1) {
        piro.push_back(0);
    }
    right++;
    while (1)
    {
        int flag = dfs(y, x, uniqueHeight[left], uniqueHeight[right]);

        if (flag) {
            left++;
            if (!dfs(y, x, uniqueHeight[left], uniqueHeight[right])) break;
        }
        else {
            right++;
        }
        if (right > uniqueHeight.size() - 1) break;
        piro.push_back(uniqueHeight[right] - uniqueHeight[left]);

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;
    int y, x;
    for (int i = 0;i < n;i++) {
        string str;
        cin >> str;
        for (int j = 0;j < n;j++) {
            arr[i][j] = str[j];
            if (str[j] == 'P') {
                y = i;
                x = j;
            }
            if (str[j] == 'K') {
                Knum++;
            }
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> height[i][j];
            uniqueHeight.push_back(height[i][j]);
        }
    }
    uniqueHeight.erase(unique(uniqueHeight.begin(), uniqueHeight.end()), uniqueHeight.end());
    visited[y][x] = 1;
    startY = y;
    startX = x;

    compareTwo(startY, startX);
    //dfs(y, x);

}