#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp의 101부분은 코인의 종류를 나타내는것이고, dp의 100001부분은 금액을 의미
// dp[i][j] 의 의미는 i번째의 코인을 사용했을때 j금액까지의 가능한 경우의 수를 누적한다.
// 경우의수는 현재 코인의 개수만큼 for문을 돌려서 dp[i-1][j-현재코인의 가치*개수(0,1,2...)] 만큼씩 누적하여 더한다
//

int T;
int K;
struct Coin {
    int P;
    int N;
};

int dp[101][10001];
vector <Coin> coin;

bool comp(Coin a, Coin b) {
    return a.P < b.P;
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> T >> K;
    for (int i = 0; i < K; i++) {
        int price, count;
        cin >> price >> count;
        coin.push_back({ price,count });
    }
    sort(coin.begin(), coin.end(), comp);
    
    for (int i = 0; i < K; i++) {
        dp[i][0] = 1;
        if (i == 0) {
            for (int j = coin[i].P; j <= coin[i].P * coin[i].N; j += coin[i].P) {
                dp[i][j]++;
            }
            continue;
        }
        for (int j = 1; j <= T; j++) {
            for (int k = 0; k <= coin[i].N; k++) {
                if (j - coin[i].P * k < 0) continue;
                dp[i][j] = dp[i][j] + dp[i - 1][j - coin[i].P * k];
            }
        }
    }

    cout << dp[K - 1][T];

    return 0;
}
