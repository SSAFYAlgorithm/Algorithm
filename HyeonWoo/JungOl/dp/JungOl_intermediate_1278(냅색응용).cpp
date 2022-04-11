#include <iostream>
#include <vector>
using namespace std;

int N, W;
struct Backpack {
	int w;
	int p;
};

vector <Backpack> Back;
int dp[1001][10001];


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> W;
	Back.push_back({ -1,-1 });
	for (int i = 0; i < N; i++) {
		int w, p;
		cin >> w >> p;
		Back.push_back({ w,p });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			int a = dp[i - 1][j];
			int b;
			if (j - Back[i].w < 0) {
				b = 0;
			}
			else {
				// 이전문제와는 다르게 한번밖에 못 넣기때문에, 이전 인덱스에서 가져오면 이전 인덱스에서는
				// 현재 인덱스의 가방을 넣지 않았기 때문에 한번만 넣을 수 있다.
				b = dp[i - 1][j - Back[i].w] + Back[i].p;
			}
			dp[i][j] = max(a, b);
		}
	}

	cout << dp[N][W];


	

	return 0;
}
