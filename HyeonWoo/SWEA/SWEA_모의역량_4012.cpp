#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[17][17];
int N;
vector <int> group1;
vector <int> group2;
int synergy1;
int synergy2;
int res;
void init() {
    int N = 0;
    for (int y = 0; y < 17; y++) {
        for (int x = 0; x < 17; x++) {
            arr[y][x] = 0;
        }
    }
    group1 = vector <int>();
    group2 = vector <int>();
    synergy1=0;
    synergy2=0;
    res = 21e8;
}

void input() {
    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> arr[y][x];
        }
    }
}

int synergy() {
    synergy1 = 0;
    synergy2 = 0;
    for (int i = 0; i < group1.size(); i++) {
        for (int j = i+1; j < group1.size(); j++) {
            int from = group1[i];
            int to = group1[j];
            synergy1 += arr[from][to];
            synergy1 += arr[to][from];
        }
    }

    for (int i = 0; i < group2.size(); i++) {
        for (int j = i + 1; j < group2.size(); j++) {
            int from = group2[i];
            int to = group2[j];
            synergy2 += arr[from][to];
            synergy2 += arr[to][from];
        }
    }

    return abs(synergy1 - synergy2);
}

void group(int idx) {
    if (idx > N) {
        // 그룹 1과 그룹2 따로 시너지 계산
        int temp = synergy();
        if (temp < res) {
            res = temp;
        }
        return;
    }
   
    group1.push_back(idx);
    group(idx + 1);
    group1.pop_back();

    group2.push_back(idx);
    group(idx + 1);
    group2.pop_back();



}

void solution() {
    group(1);
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