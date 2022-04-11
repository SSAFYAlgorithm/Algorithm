#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int mountain[8][8];
int used[8][8];
int N, K, MAX; // MAX는 배열중 최대값
int res;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
struct Node {
    int y;
    int x;
};

vector <Node> High;

void init() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            mountain[y][x] = 0;
            used[y][x] = 0;
        }
    }
    N = 0; K = 0; MAX = -21e8;
    High = vector <Node>();
    res = 0;
}

void input() {
    cin >> N >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> mountain[y][x];
            if (mountain[y][x] > MAX) {
                MAX = mountain[y][x];
            }
        }
    }
}

void FindHigh() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (mountain[y][x] == MAX) {
                High.push_back({ y,x });
            }
        }
    }
}

void dfs(int y, int x, int height,int len) {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (mountain[ny][nx] >= height) continue;
        flag = 1;
        dfs(ny, nx, mountain[ny][nx], len + 1);
    }

    if (!flag) {
        if (len > res) {
            res = len;
        }
        return;
    }
    else {
        return;
    }
}

void solution() {
    for (int i = 0; i < High.size(); i++) {
        int start_y = High[i].y;
        int start_x = High[i].x;
        used[start_y][start_x] = 1;
        dfs(start_y, start_x, mountain[start_y][start_x], 1);
        used[start_y][start_x] = 0;
    }
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        FindHigh();
        // 출발지가 정해지면, 모든 지점을 각각 1~k만큼 깎아서 길이를 구해본다
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                for (int k = 0; k <= K; k++) {
                    mountain[y][x] -= k;
                    solution();
                    mountain[y][x] += k;
                }
            }
        }

        cout << "#" << tc << " " << res << endl;

    }

    return 0;
}