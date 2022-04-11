#include <string>
#include <vector>
#include <cstring>
using namespace std;

int arr[105][105];

int TURN(int sy, int sx, int ey, int ex) {

    // 비교하면서 최소값 발견
    int min = 21e8;

    // 맨 윗줄 부터
    int temp[105][105] = {0};
    memcpy(temp, arr, sizeof(arr));
    for (int i = sx; i <= ex-1; i++) {
        temp[sy][i + 1] = arr[sy][i];
        if (temp[sy][i + 1] < min) {
            min = temp[sy][i + 1];
        }
    }
    temp[sy][sx] = arr[sy + 1][sx];
    if (temp[sy][sx] < min) {
        min = temp[sy][sx];
    }


    // 오른쪽
    for (int y = sy; y <= ey - 1; y++) {
        temp[y + 1][ex] = arr[y][ex];
        if (temp[y + 1][ex] < min) {
            min = temp[y + 1][ex];
        }
    }
    
    // 아래
    for (int x = sx; x <= ex-1; x++) {
        temp[ey][x] = arr[ey][x + 1];
        if (temp[ey][x] < min) {
            min = temp[ey][x];
        }
    }

    // 왼쪽
    for (int y = sy + 1; y <= ey - 1; y++) {
        temp[y][sx] = arr[y + 1][sx];
        if (temp[y][sx] < min) {
            min = temp[y][sx];
        }
    }




    memcpy(arr, temp, sizeof(arr));
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int n = 1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = n++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {

        // 시작점 끝점 명시
        int sy = queries[i][0];
        int sx = queries[i][1];
        int ey = queries[i][2];
        int ex = queries[i][3];

        // 턴
        int min = TURN(sy, sx, ey, ex);
        answer.push_back(min);

    }


    return answer;
}

int main() {

    solution(100, 97, { {1,1,100,97} });


    return 0;
}