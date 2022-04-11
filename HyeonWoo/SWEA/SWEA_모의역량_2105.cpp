#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dy[] = { 1,1,-1,-1 };
int dx[] = { 1,-1,-1,1 };
int n;
int arr[20][20];
int res;
int desert[101];
vector <int> path;
void init() {
    n = 0; res = -1;
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            arr[y][x] = 0;
        }
    }
    for (int i = 1; i <= 100; i++) {
        desert[i] = 0;
    }
}

void input() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }
}


void dfs(int y, int x, int sy, int sx, int dir, int cnt) {
    
    if (dir == 4) {
        return;
    }

    if (y == sy && x == sx) {
        if (cnt > res) {
            res = cnt;
        }
        return;
    }

    if (y < 0 || x < 0 || y >= n || x >= n) return;

    if (desert[arr[y][x]] == 1) return;

    desert[arr[y][x]] = 1;
    path.push_back(arr[y][x]);
    //현재방향
    dfs(y + dy[dir], x + dx[dir], sy, sx, dir, cnt + 1);

    //다음방향
    dfs(y + dy[dir+1], x + dx[dir+1], sy, sx, dir+1, cnt+1);
    desert[arr[y][x]] = 0;
    path.pop_back();


    
}

void solution() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (y == 0 && x == 0 || y == 0 && x == n - 1 || y == n - 1 && x == 0 || y == n - 1 && x == n-1) continue;
            // 사각형 그리기 시작
            desert[arr[y][x]] = 1;
            path = vector <int>();
            path.push_back(arr[y][x]);
            dfs(y+dy[0], x+dx[0], y, x, 0, 1);
            desert[arr[y][x]] = 0;
            path.pop_back();

        }
    }

}


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        solution();
        cout << "#" << tc << " " << res << endl;
    }
    return 0;
}