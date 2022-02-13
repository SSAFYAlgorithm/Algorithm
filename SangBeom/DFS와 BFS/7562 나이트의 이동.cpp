#include<iostream>
#include<queue>
using namespace std;

int arr[301][301] = { 0 };
int cnt[301][301] = { 0 };
int N;
bool check[301][301] = { 0 };
void bfs(int y, int x) {
    queue<pair<int, int>>que;
    que.push(pair<int, int>(y, x));
    check[y][x] = 1;
    cnt[y][x] = 1;
    while (1) {

        int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
        int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
        for (int i = 0;i < 8;i++) {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if (!(tempX < 0 || tempY < 0 || tempX >= N || tempY >= N)) {
                if (cnt[tempX][tempY]) {
                    cnt[y][x] = cnt[tempX][tempY] + 1;
                    break;
                }
            }
        }
        que.pop();
        for (int i = 0;i < 8;i++) {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if (!(tempX < 0 || tempY < 0 || tempX >= N || tempY >= N)) {
                if (!check[tempY][tempX]) {
                    que.push(pair<int, int>(tempY, tempX));
                    check[y][x] = true;
                }
            }
        }
        if (que.empty()) {
            break;
        }
        y = que.front().first;
        x = que.front().second;

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
        arr[startY][startX] = 1;   //시작점
        arr[endY][endX] = 100;      //종점
        bfs(startY, startX);
        cout << cnt[endY][endX] << '\n';
    }
}