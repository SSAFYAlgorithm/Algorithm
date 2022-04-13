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

	// i는 해당 배낭 index, w는 0 ~ W까지의 무게를 하나씩 증가시키며 비교할 예정임
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= W; w++) {
			int a = dp[i - 1][w];
			int b = 0;
			if (w - Back[i].w >= 0) {
				// w-Back[i].w 가 음수인덱스이면 0 , 아니면 현재 배낭 index의 무게만큼 전에있는 값에 현재 배낭 index의 가치만큼 추가
				b = dp[i][w - Back[i].w] + Back[i].p;
			}
			else {
				b = 0;
			}
			dp[i][w] = max(a, b);
		}
	}

	cout << dp[N][W];


	

	return 0;
}
