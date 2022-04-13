#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[50][50];
int used[50][50];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int type[8][4] = { // 1은 이동 가능한 경우 0은 이동 못하는 경우
    {0,0,0,0},
    {1,1,1,1},
    {1,1,0,0},
    {0,0,1,1},
    {1,0,0,1},
    {0,1,0,1},
    {0,1,1,0},
    {1,0,1,0},
};
int N, M, R, C, L; // N 세로길이 M 가로길이 R 맨홀세로 C 맨홀가로 L시간

struct Node {
    int y;
    int x;
    int hour;
};

void init() {
    N = 0; M = 0; R = 0; C = 0; L = 0;
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 50; x++) {
            arr[y][x] = 0;
            used[y][x] = 0;
        }
    }
}

void input() {
    cin >> N >> M >> R >> C >> L;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> arr[y][x];
        }
    }
}

int check(int now_y, int now_x, int next_y, int next_x, int next_type) {
    for (int i = 0; i < 4; i++) {
        if (type[next_type][i] == 0)continue;
        int temp_y = next_y + dy[i];
        int temp_x = next_x + dx[i];
        if (temp_y == now_y && temp_x == now_x) {
            return 0;
        }
    }
    return 1;
}

void solution() {
    queue <Node> q;
    q.push({ R,C,1 });
    used[R][C] = 1;
    int hour = 0;
    while (!q.empty()) {
        int now_y = q.front().y;
        int now_x = q.front().x;
        int hour = q.front().hour;
        if (hour >= L) break;
        q.pop();
        int now_type = arr[now_y][now_x];
        for (int i = 0; i < 4; i++) {
            if (type[now_type][i] == 0) continue;
            int next_y = now_y + dy[i];
            int next_x = now_x + dx[i];
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
            if (used[next_y][next_x] != 0) continue;
            if (arr[next_y][next_x] == 0) continue;
            int next_type = arr[next_y][next_x];
            if (check(now_y, now_x, next_y, next_x, next_type)) {
                continue;
            }
            used[next_y][next_x] = 1;
            q.push({ next_y,next_x,hour + 1 });
        }
    }

}

int Count() {
    int sum = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (used[y][x] == 1) {
                sum++;
            }
        }
    }
    return sum;
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        solution();
        int res = Count();
        cout << "#" << tc << " " << res << endl;
    }

    return 0;
}