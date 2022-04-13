#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int y;
    int x;
};


int isPartition(vector <string> vect, int sy,int sx, int ey, int ex) {
    if (abs(ey - sy) == 1 && abs(ex - sx) == 1) {
        if (vect[sy][ex] != 'X') {
            return 0;
        }
        else if (vect[ey][sx] != 'X') {
            return 0;
        }
        return 1;
    }
    else if (abs(ey - sy) == 2 && ex == sx) {
        if (vect[(ey + sy) / 2][ex] != 'X') {
            return 0;
        }
        return 1;
    }
    else if (abs(ex - sx) == 2 && ey == sy) {
        if (vect[ey][(ex + sx) / 2] != 'X') {
            return 0;
        }
        return 1;
    }

}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    // P위치 파악
   
    for (int idx = 0; idx < 5; idx++) {
        vector <Node> P;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (places[idx][y][x] == 'P') {
                    P.push_back({ y,x });
                }
            }
        }

        if (P.size() == 0) {
            answer.push_back(1);
            continue;
        }

        // 거리 비교함수
        int flag = 0;
        for (int i = 0; i < P.size() - 1; i++) {
            for (int j = i + 1; j < P.size(); j++) {
                int sub_y = abs(P[i].y - P[j].y);
                int sub_x = abs(P[i].x - P[j].x);
                if (sub_x + sub_y > 2) {
                    continue;
                }
                // 맨해튼거리가 2가 아니면 중간에 파티션이 있는지 파악해야한다.
                vector <string> temp = places[idx];
                // 만약 파티션으로 모두 가로막혀 있지 않다면? 거리두기 안지켜짐
                if (!isPartition(temp, P[i].y, P[i].x, P[j].y, P[j].x)) {
                    flag = 1;
                }

            }
        }

        // 거리두기가 안지켜 진다면
        if (flag) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }

    return answer;
}

int main() {

    solution({ 
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} 
        });

    return 0;
}