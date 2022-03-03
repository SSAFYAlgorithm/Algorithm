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
priority_queue<int, vector<int>, greater<int>>pq;
vector<int>route;
struct Piro
{
    int maxHeight;
    int minHeight;
};

void dfs(int y, int x, Piro now)
{
    //route.push_back(height[y][x]);
    if (height[y][x] > now.maxHeight) {
        now.maxHeight = height[y][x];
    }
    if (height[y][x] < now.minHeight) {
        now.minHeight = height[y][x];
    }
    if (arr[y][x] == 'K') {
        Kcount++;

        if (Kcount == Knum) {
            //            int max = *max_element(route.begin(), route.end());
              //          int min = *min_element(route.begin(), route.end());
            pq.push(now.maxHeight - now.minHeight);
            return;
        }
    }

    int dx[8] = { -1,0,1,-1,1,-1,0,1 };
    int dy[8] = { -1,-1,-1,0,0,1,1,1 };
    for (int i = 0;i < 8;i++) {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
        if (visited[ty][tx] == true)continue;
        visited[ty][tx] = 1;
        dfs(ty, tx, now);
        visited[ty][tx] = 0;
        //  route.pop_back();
        if (arr[ty][tx] == 'K') {
            Kcount--;
        }

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
    Piro now;
    now.maxHeight = height[y][x];
    now.minHeight = height[y][x];
    dfs(y, x, now);

    cout << pq.top();

}