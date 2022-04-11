#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp�� 101�κ��� ������ ������ ��Ÿ���°��̰�, dp�� 100001�κ��� �ݾ��� �ǹ�
// dp[i][j] �� �ǹ̴� i��°�� ������ ��������� j�ݾױ����� ������ ����� ���� �����Ѵ�.
// ����Ǽ��� ���� ������ ������ŭ for���� ������ dp[i-1][j-���������� ��ġ*����(0,1,2...)] ��ŭ�� �����Ͽ� ���Ѵ�
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
