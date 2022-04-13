#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int price[4];
int plan[13];
int res = 0;
int minimum = 21e8;

void init() {
    for (int i = 0; i < 4; i++) {
        price[i] = 0;
    }
    for (int i = 1; i <= 12; i++) {
        plan[i] = 0;
    }
    res = 0;
    minimum = 21e8;
}

void input() {
    for (int i = 0; i < 4; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= 12; i++) {
        cin >> plan[i];
    }
}


void dfs(int month) {
    if (month > 12) {
        if (res < minimum) {
            minimum = res;
        }
        return;
    }
    // 1일 이용권
    res += (plan[month] * price[0]);
    dfs(month + 1); // 1일 이용권;
    res -= (plan[month] * price[0]);

    res += price[1];
    dfs(month + 1); // 1개월 이용권
    res -= price[1];

    res += price[2];
    dfs(month + 3); // 3개월 이용권
    res -= price[2];

    if (month == 1) {
        res += price[3];
        dfs(month + 12);
        res -= price[3];
    }
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        dfs(1);
        
        cout << "#" << tc << " " << minimum << endl;

    }

    return 0;
}