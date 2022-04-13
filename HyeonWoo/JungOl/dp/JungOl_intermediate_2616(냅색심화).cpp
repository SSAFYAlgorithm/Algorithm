#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int mem[101];
int cost[101];
// dp는 [사용할 메모리의 idx][cost] 일때 최대로 사용할 수 있는 메모리의 크기
int dp[100][10001];

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N >> M;
    int totcost = 0;
    for (int i = 0; i < N; i++) {
        cin >> mem[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        totcost += cost[i];
    }
    for (int j = 0; j <= totcost; j++) {
        if (j / cost[0] >= 1) {
            dp[0][j] = mem[0];
        }
        else {
            dp[0][j] = 0;
        }
    }
    int res = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= totcost; j++) {
            if (j >= cost[i]) {
                // dp는 바로 위칸과 위의줄에서 현재 cost값을 뺀 값에 현재 memory 값을 더한 값과 비교를 통해 max를 구한다
                // 냅색 알고리즘
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
            }
            else {
                // j-cost 가 음수이면 위의줄로 받아온다
                dp[i][j] = dp[i - 1][j];
            }
            if (i == N - 1 && dp[i][j] >= M) {
                cout << j;
                break;
            }
        }
    }

    int de = -1;

    return 0;
}
