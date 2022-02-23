#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;
//192MB -> 2억바이트
int N, M;
int arr[1002][1002] = { 0 }; // 800만
bool check[1002][1002] = { 0 }; //800만

/*
7 10
0000000000
1010101010
1111111111
1111111110
0000000000
0111111111
0000000000
*/

void bfs(int y, int x) {
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,-1,0,1 };
    bool flag = false;
    int cnt = 1;
    queue<tuple<int, int, bool, int>> que;
    que.push(tuple<int, int, bool, int>(y, x, flag, cnt));
    int nowX;
    int nowY;
    while (1)
    {
        if (que.empty()) {
            cout << -1;
            break;
        }

        nowY = get<0>(que.front());
        nowX = get<1>(que.front());

        if (nowX == M && nowY == N) {
            cout << cnt;
            break;
        }

        for (int i = 0;i < 4;i++) {
            int tempX = nowX + dx[i];
            int tempY = nowY + dy[i];
            if (!(tempX <= 0 || tempY <= 0 || tempX > M || tempY > N)) {
                if (check[tempY][tempX])continue;
                check[tempY][tempX] = 1;
                if (arr[tempY][tempX] == 0) {
                    cnt = get<3>(que.front()) + 1;
                    flag = get<2>(que.front());
                    que.push(tuple<int, int, bool, int>(tempY, tempX, flag, cnt));
                }
                else {// 벽이있다면
                    if (!get<2>(que.front())) {//하나도안부셨으면
                        flag = true;
                        cnt = get<3>(que.front()) + 1;
                        que.push(tuple<int, int, bool, int>(tempY, tempX, flag, cnt));
                    }
                }
            }
        }
        que.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1;i <= N;i++) {
        string str;
        cin >> str;
        for (int j = 0;j < M;j++) {
            arr[i][j + 1] = (int)(str[j] - '0');
        }
    }
    bfs(1, 1);
}