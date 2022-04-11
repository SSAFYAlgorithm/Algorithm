#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[5][8];
int K;
struct Node {
    int num;
    int dir;
};

vector <Node> info;

void init() {
    for (int y = 1; y < 5; y++) {
        for (int x = 0; x < 8; x++) {
            arr[y][x] = 0;
        }
    }
    K = 0;
    info = vector<Node>();
}

void input() {
    cin >> K;
    for (int y = 1; y < 5; y++) {
        for (int x = 0; x < 8; x++) {
            cin >> arr[y][x];
        }
    }
    for (int i = 0; i < K; i++) {
        int num, dir;
        cin >> num >> dir;
        info.push_back({ num,dir });
    }
}

void turnRight(int num) {
    int temp = arr[num][7];
    for (int i = 7; i >= 1; i--) {
        arr[num][i] = arr[num][i - 1];
    }
    arr[num][0] = temp;
}

void turnLeft(int num) {
    int temp = arr[num][0];
    for (int i = 0; i < 7; i++) {
        arr[num][i] = arr[num][i + 1];
    }
    arr[num][7] = temp;
}

void Turn(int num, int dir) {

    if (dir == 1) {
        if (num == 1) {
            if (arr[1][2] != arr[2][6]) {
                if (arr[2][2] != arr[3][6]) {
                    if (arr[3][2] != arr[4][6]) {
                        turnLeft(num + 3);
                    }
                    turnRight(num+2);
                }
                turnLeft(num + 1);
            }
            turnRight(num);
        }
        else if (num == 2) {
            if (arr[2][6] != arr[1][2]) {
                turnLeft(num-1);
            }
            if (arr[2][2] != arr[3][6]) {
                if (arr[3][2] != arr[4][6]) {
                    turnRight(num + 2);
                }
                turnLeft(num + 1);
            }
            turnRight(num);
        }
        else if (num == 3) {
            if (arr[3][2] != arr[4][6]) {
                turnLeft(num + 1);
            }
            if (arr[3][6] != arr[2][2]) {
                if (arr[2][6] != arr[1][2]) {
                    turnRight(num - 2);
                }
                turnLeft(num - 1);
            }
            turnRight(num);
        }
        else if (num == 4) {
            if (arr[4][6] != arr[3][2]) {
                if (arr[3][6] != arr[2][2]) {
                    if (arr[2][6] != arr[1][2]) {
                        turnLeft(num - 3);
                    }
                    turnRight(num - 2);
                }
                turnLeft(num - 1);
            }
            turnRight(num);
        }
        
    }
    else {
        if (num == 1) {
            if (arr[1][2] != arr[2][6]) {
                if (arr[2][2] != arr[3][6]) {
                    if (arr[3][2] != arr[4][6]) {
                        turnRight(num + 3);
                    }
                    turnLeft(num + 2);
                }
                turnRight(num + 1);
            }
            turnLeft(num);
        }
        else if (num == 2) {
            if (arr[2][6] != arr[1][2]) {
                turnRight(num - 1);
            }
            if (arr[2][2] != arr[3][6]) {
                if (arr[3][2] != arr[4][6]) {
                    turnLeft(num + 2);
                }
                turnRight(num + 1);
            }
            turnLeft(num);
        }
        else if (num == 3) {
            if (arr[3][2] != arr[4][6]) {
                turnRight(num + 1);
            }
            if (arr[3][6] != arr[2][2]) {
                if (arr[2][6] != arr[1][2]) {
                    turnLeft(num - 2);
                }
                turnRight(num - 1);
            }
            turnLeft(num);
        }
        else if (num == 4) {
            if (arr[4][6] != arr[3][2]) {
                if (arr[3][6] != arr[2][2]) {
                    if (arr[2][6] != arr[1][2]) {
                        turnRight(num - 3);
                    }
                    turnLeft(num - 2);
                }
                turnRight(num - 1);
            }
            turnLeft(num);
        }
    }
}

int Score() {
    int score = arr[1][0] + arr[2][0] * 2 + arr[3][0] * 4 + arr[4][0] * 8;
    return score;
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        for (int i = 0; i < K; i++) {
            int num = info[i].num;
            int dir = info[i].dir;
            // dir == 1 => turnright 아니면 turnleft
            Turn(num, dir);
        }
        int res = Score();
        cout << "#" << tc << " " << res << endl;

    }
    return 0;
}