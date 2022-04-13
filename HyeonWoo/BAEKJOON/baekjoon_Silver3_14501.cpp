#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int N;
int T[20];
int P[20];
int profit[20];
int cost = 0;
vector <int> path;
int DFS(int day) {
    if (day >= N + 1) {
        return 0;
    }

    if (profit[day] > 0) {
        return profit[day];
    }

    // 해당날짜 상담받음
    int CostA = DFS(day + T[day]);
    if (day + T[day] - 1 < N + 1) {
        CostA += P[day];
    }
    // 해당날짜 건너 뜀
    int CostB = DFS(day + 1);
    
    profit[day] = max(CostA, CostB);

    return profit[day];
}


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    DFS(1);
    cout << profit[1];
    return 0;
}