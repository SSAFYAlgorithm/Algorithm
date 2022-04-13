#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char arr[5][6];

void Turn(int yy, int xx) {
    char Turntemp[5][6];
    // 맨 yy,xx 좌측 맨위좌표로 설정
    yy--;
    xx--;
    memcpy(Turntemp, arr, sizeof(arr));
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            Turntemp[x + yy][2 - y + xx] = arr[y + yy][x + xx];
        }
    }
    memcpy(arr, Turntemp, sizeof(arr));
}

int Check() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n - 2; x++) {
            if (arr[y][x] == 'A' && arr[y][x + 1] == 'A' && arr[y][x + 2] == 'A') {
                return 1;
            }
        }
    }
    return 0;
}

int flag = 0;
void DFS(int level) {
    if (level >= 7) {
        return;
    }

    if (flag) {
        return;
    }

    if (Check()) {
        flag = 1;
        return;
    }

    for (int y = 1; y < n - 1; y++) {
        for (int x = 1; x < n - 1; x++) {
            char temp[5][6];
            memcpy(temp, arr, sizeof(arr));
            Turn(y, x);
            DFS(level + 1);
            memcpy(arr, temp, sizeof(arr)); 
        }
    }
    



}


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    DFS(0);
    if (flag) {
        cout << "가능";
    }
    else {
        cout << "불가능";
    }
   
    return 0;
}