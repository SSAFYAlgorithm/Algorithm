#include<iostream>
#include<queue>
using namespace std;

int arr[301][301] = { 0 };
int cnt[301][301] = { 0 };
int N;
bool check[301][301] = { 0 };
void bfs(int y, int x) {
    int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
    int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
    queue<pair<int, int>>que;
    que.push(pair<int, int>(y, x));

    while (1) {
        if (que.empty()) break;
        arr[y][x] = 1;
        y = que.front().first;
        x = que.front().second;
        que.pop();
        for (int i = 0;i < 8;i++) {
            int tempX = dx[i] + x;
            int tempY = dy[i] + y;
            if (!(tempX < 0 || tempY < 0 || tempX >= N || tempY >= N))
            {
                if (arr[tempY][tempX] == 0 && cnt[tempY][tempX] == 0) {
                    cnt[tempY][tempX] = cnt[y][x] + 1;
                    que.push(pair<int, int>(tempY, tempX));
                }
            }
        }
    }

}
int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0;i < testCase;i++) {
        cin >> N;
        int startX, startY;
        cin >> startX >> startY;
        int endX, endY;
        cin >> endX >> endY;

        bfs(startY, startX);
        cout << cnt[endY][endX] << '\n';
        //ÃÊ±âÈ­
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < N;j++) {
                arr[i][j] = 0;
                cnt[i][j] = 0;
            }
        }
    }
}