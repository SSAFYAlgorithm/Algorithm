#include <iostream>
#include <cstring>
using namespace std;

int arr[13][20];
int D, W, K;
int res;
int res_0;
int res_1;
int lastValue;
int cnt = 0;
void init() {
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 20; x++) {
            arr[y][x] = 0;
        }
    }
    D = 0;
    W = 0;
    K = 0;
    res = 9999; cnt = 0;
}

void input() {
    cin >> D >> W >> K;
    for (int y = 0; y < D; y++) {
        for (int x = 0; x < W; x++) {
            cin >> arr[y][x];
        }
    }
}

// 각 column만 check할예정 (한 column만 탐색)

int Check() {
    for (int x = 0; x < W; x++) {
        int Allflag = 0;
        for (int y = 0; y < D - (K - 1); y++) {
            // flag 한줄이 가능한가 0: 가능하다
            int flag = 0;
            for (int i = 1; i < K; i++) {
                if (arr[y][x] != arr[y + i][x]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                Allflag = 1;
                break;
            }
        }
        //Allflag = 1이면 해당 줄은 가능하다 0이면 불가능하다
        if (!Allflag) {
            return 1;
        }
    }
    return 0;
}

void dfs(int level, int last_y) {
    if (level > K) {
        return;
    }

    int temp[13][20];

    for (int y = last_y + 1; y < D; y++) {
        memcpy(temp, arr, sizeof(temp));
        //먼저 0으로 칠하는 경우
        for (int x = 0; x < W; x++) {
            arr[y][x] = 0;
        }
        if (!Check()) {
            if (level < res) {
                res = level;
            }
            return;
        }
        dfs(level + 1, y);
        memcpy(arr, temp, sizeof(arr));

        for (int x = 0; x < W; x++) {
            //1로 칠하는 경우
            arr[y][x] = 1;
        }
        if (!Check()) {
            if (level < res) {
                res = level;
            }
            return;
        }
        dfs(level + 1, y);
        memcpy(arr, temp, sizeof(arr));
    }


}

void solution() {
    // K가 1이면 막 추가 안해도 무조건 K조건 성립
    if (K == 1) {
        res = 0;
        return;
    }

    if (!Check()) {
        res = 0;
    }
    else {
        dfs(1, -1);
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