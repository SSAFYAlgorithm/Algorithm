#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
    int y;
    int x;
    int cnt;
};


int N, W, H;
int arr[20][20];
int used[20][20] = { 0 };
vector <Node> Top;
int res;

// 초기화 진행
void init() {
    N = 0; W = 0; H = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            arr[i][j] = 0;
            used[i][j] = 0;
        }
    }
    Top = vector<Node>();
    res = 21e8;
}

// input 기입
void input() {
    cin >> N >> W >> H;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> arr[y][x];
        }
    }
}

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

// 구슬을 떨어뜨려 벽돌이 터지는 것을 BFS로 표현
void Bomb(int y, int x, int cnt) {
    queue <Node> q;
    q.push({ y,x,cnt });
    arr[y][x] = 0;

    while (!q.empty()) {
        int now_y = q.front().y;
        int now_x = q.front().x;
        int now_cnt = q.front().cnt;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = now_y + dy[i];
            int next_x = now_x + dx[i];
            int next_cnt = arr[next_y][next_x];
            for (int j = 0; j < now_cnt-1; j++) {
                // 처음일때는 now위치로 다음위치를 계산하지만 그 이후는 변한 위치에서 그 다음위치를 계산하기 때문에 if/else 사용
                if (j == 0) {
                    next_y = now_y + dy[i];
                    next_x = now_x + dx[i];
                    next_cnt = arr[next_y][next_x];
                }
                else {
                    next_y = next_y + dy[i];
                    next_x = next_x + dx[i];
                    next_cnt = arr[next_y][next_x];
                }
                if (next_y < 0 || next_x < 0 || next_y >= H || next_x >= W) continue;
                if (arr[next_y][next_x] == 0) continue;
                arr[next_y][next_x] = 0;
                if (next_cnt > 1) {
                    q.push({ next_y,next_x,next_cnt });
                }
            }
        }
        

    }
}

// 벽돌이 터지고 블록을 아래로 떨어뜨리기 위해서 y,ny 이용했고, 거꾸로 탐색진행함
void Gravity() {
    for (int x = 0; x < W; x++) {
        for (int y = H-1; y >= 1; y--) {
            for (int ny = y-1; ny >= 0; ny--) {
                if (arr[y][x] == 0 && arr[ny][x] > 0) {
                    swap(arr[y][x], arr[ny][x]);
                    break;
                }
                if (arr[y][x] > 0 && arr[ny][x] > 0) {
                    break;
                }
            }
        }
    }
}

// 벽돌의 맨위에만 구슬을 떨어뜨릴 수 있기때문에 맨위의 위치들을 탐색
vector <Node> FindTop() {
    Top = vector<Node>();
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            if (arr[y][x] > 0) {
                Top.push_back({ y,x,arr[y][x] });
                break;
            }
        }
    }
    return Top;
}


//DFS로 모든 경우의 수를 탐색함
vector <Node> path;
void DFS(int level) {
    if (level == N) {
        // 남은 벽돌개수 세고 리턴
        int cnt = 0;
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (arr[y][x] > 0) {
                    cnt++;
                }
            }
        }
        if (cnt < res) {
            res = cnt;
        }
        return;
    }

    vector <Node> Top = FindTop();
    int temp[20][20] = { 0 };
    memcpy(temp, arr, sizeof(arr));
    for (int i = 0; i < Top.size(); i++) {
        Bomb(Top[i].y, Top[i].x, Top[i].cnt);
        Gravity();
        path.push_back({ Top[i].y, Top[i].x, Top[i].cnt });
        DFS(level + 1);
        memcpy(arr, temp, sizeof(arr));
        path.pop_back();
    }
}

void solution() {
    DFS(0);
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        solution();
        if (res == 21e8) {
            cout << "#" << tc << " " << 0 << endl;
        }
        else {
            cout << "#" << tc << " " << res << endl;
        }

    }
    return 0;
}