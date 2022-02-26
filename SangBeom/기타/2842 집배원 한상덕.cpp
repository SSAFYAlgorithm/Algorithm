#include<iostream>
#include<string>
#include<queue>
using namespace std;

char arr[51][51];
bool visited[51][51] = { 0 };
int height[51][51];
int Knum = 0;
int Kcount = 0;
int maxHeight = 0;
int minHeight = 10000001;
int n;
int startX, startY;
priority_queue<int, vector<int>, greater<int>>pq;

//각 경로마다 피로도 최대값과 최소값을 어떻게 구할까
void dfs(int y, int x)
{

    if (y == startY && x == startX) {
        maxHeight = 0;
        minHeight = 10000001;
        Kcount = 0;
    }
    if (height[y][x] > maxHeight) {
        maxHeight = height[y][x];
    }
    if (height[y][x] < minHeight) {
        minHeight = height[y][x];
    }
    if (arr[y][x] == 'K') {
        Kcount++;
        if (Kcount == Knum) {
            pq.push(maxHeight - minHeight);

            return;
        }
    }

    int dx[8] = { -1,0,1,-1,1,-1,0,1 };
    int dy[8] = { -1,-1,-1,0,0,1,1,1 };
    for (int i = 0;i < 8;i++) {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
        if (visited[ty][tx])continue;
        visited[ty][tx] = 1;
        dfs(ty, tx);
        visited[ty][tx] = 0;


    }

    return;
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
        }
    }
    visited[y][x] = 1;
    startY = y;
    startX = x;
    dfs(y, x);
    cout << pq.top();

}