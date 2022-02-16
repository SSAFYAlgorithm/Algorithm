#include<iostream>
#include<queue>
using namespace std;

int arr[301][301] = { 0 };
int N;
int startX, startY;
int endX, endY;
int flag = 0;
void bfs(int y, int x) {
    queue<pair<int, int>>que;
    que.push(pair<int, int>(y, x));
    arr[y][x] = 1;
    while (1) {
        que.pop();
        int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
        int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
        for (int i = 0;i < 8;i++) {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if (!(tempX < 0 || tempY < 0 || tempX >= N || tempY >= N)) {
                if (arr[tempX][tempY]) {
                    arr[y][x] = arr[tempX][tempY] + 1;
                    break;
                }
            }
        }

        for (int i = 0;i < 8;i++) {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if (!(tempX < 0 || tempY < 0 || tempX >= N || tempY >= N)) {
                if (!arr[tempY][tempX]) {
                    que.push(pair<int, int>(tempY, tempX));

                }
            }
        }
        if (que.empty()) {
            flag = 1;
            break;
        }
        y = que.front().first;
        x = que.front().second;
        if (y == endY && x == endX) {
            break;
        }
    }
    while (!que.empty()) que.pop();
}
int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0;i < testCase;i++) {
        cin >> N;

        cin >> startX >> startY;
        cin >> endX >> endY;
        bfs(startY, startX);
        if (flag) {
            cout << "0\n";
        }
        else {
            cout << arr[startY][startX] << '\n';
        }
        flag = 0;
        for (int k = 0;k < N;k++) {
            for (int j = 0;j < N;j++) {
                arr[k][j] = 0;
            }
        }
    }
}\


