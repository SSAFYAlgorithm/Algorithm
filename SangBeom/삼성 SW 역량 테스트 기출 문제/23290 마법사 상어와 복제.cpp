#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 5
using namespace std;

struct fish {
    int x;
    int y;
    int dir;
};

int n = 4, m, s, maxEating;
int tempRoute[3], route[3];
int smellMap[MAX][MAX];
vector<fish> fishMap[MAX][MAX], cMap[MAX][MAX];
pair<int, int> shark;

int fdx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int fdy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int sdx[] = { 0, -1, 0, 1, 0 };
int sdy[] = { 0, 0, -1, 0, 1 };


void input() {
    cin >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        x--; y--;
        fish f = { x, y, d };
        fishMap[x][y].push_back(f);
    }
    cin >> shark.first >> shark.second;
    shark.first--; shark.second--;
}

void copyMap(vector<fish> A[][MAX], vector<fish> B[][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void copyFish() {
    copyMap(cMap, fishMap);
}

int changeDir(int dir) {
    switch (dir) {
    case 1:
        return 8;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 4;
    case 6:
        return 5;
    case 7:
        return 6;
    case 8:
        return 7;
    }
}

void moveFish() {
    vector<fish> tempMap[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < fishMap[i][j].size(); k++) {
                int x = fishMap[i][j][k].x;
                int y = fishMap[i][j][k].y;
                int dir = fishMap[i][j][k].dir;
                int nx = x;
                int ny = y;
                bool Flag = false;
                for (int l = 0; l < 8; l++) {
                    nx = x + fdx[dir];
                    ny = y + fdy[dir];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if ((nx != shark.first || ny != shark.second) && smellMap[nx][ny] == 0) {
                            Flag = true;
                            break;
                        }
                    }
                    dir = changeDir(dir);
                }
                if (Flag == true) {
                    fish f = { nx, ny, dir };
                    tempMap[nx][ny].push_back(f);
                }
                else {
                    fish f = { x, y, dir };
                    tempMap[x][y].push_back(f);
                }
            }
        }
    }
    copyMap(fishMap, tempMap);
}

int routeSimulation() {
    bool visit[MAX][MAX] = { false, };
    int x = shark.first;
    int y = shark.second;
    int eat = 0;
    for (int i = 0; i < 3; i++) {
        int dir = tempRoute[i];
        int nx = x + sdx[dir];
        int ny = y + sdy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) return -1;
        if (visit[nx][ny] == false) {
            visit[nx][ny] = true;
            eat += fishMap[nx][ny].size();
        }
        x = nx;
        y = ny;
    }
    return eat;
}

void findRoute(int cnt) {
    if (cnt == 3) {
        int eatNum = routeSimulation();
        if (eatNum > maxEating) {
            for (int i = 0; i < 3; i++) {
                route[i] = tempRoute[i];
            }
            maxEating = eatNum;
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        tempRoute[cnt] = i;
        findRoute(cnt + 1);
    }
}

void moveShark(int time) {
    vector<fish> tempMap[MAX][MAX];
    copyMap(tempMap, fishMap);

    int x = shark.first;
    int y = shark.second;
    for (int i = 0; i < 3; i++) {
        int dir = route[i];
        int nx = x + sdx[dir];
        int ny = y + sdy[dir];
        if (tempMap[nx][ny].size() != 0) {
            smellMap[nx][ny] = time;
            tempMap[nx][ny].clear();
        }
        x = nx;
        y = ny;
        shark.first = x;
        shark.second = y;
    }
    copyMap(fishMap, tempMap);
}

void aboutShark(int time) {
    maxEating = -1;
    findRoute(0);
    moveShark(time);
}

void removeSmell(int time) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (smellMap[i][j] == 0) continue;
            if (time - smellMap[i][j] == 2) {
                smellMap[i][j] = 0;
            }
        }
    }
}

void bornFish() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < cMap[i][j].size(); k++) {
                fishMap[i][j].push_back(cMap[i][j][k]);
            }
        }
    }
}

int findAnswer() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += fishMap[i][j].size();
        }
    }
    return ret;
}

void solution() {
    for (int i = 1; i <= s; i++) {
        copyFish();
        moveFish();
        aboutShark(i);
        removeSmell(i);
        bornFish();
    }
    cout << findAnswer();
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    solve();

    return 0;
}