#include <iostream>
using namespace std;

int N, M, K;
int Weight[14];
// DFS로 순서 배열하고
// 뽑는거 수행해주면 되겠네? ㅇㅋ?

int path[14];
int used[14];
int ans = 21e8;
void Take() {
	int nowIdx = 0;
	int res = 0;
	int SUM = 0;
	int Cnt = 0;
	while (1) {
		if (Cnt == K) break;
		SUM = 0;
		while (1) {
			SUM += path[nowIdx];
			if (SUM > M) {
				SUM -= path[nowIdx];
				res += SUM;
				Cnt++;
				break;
			}
			nowIdx++;
			if (nowIdx == N) {
				nowIdx = 0;
			}
		}
	}
	ans = min(ans, res);
}

void MakePath(int lv) {
	if (lv == N) {
		// 택배 가져가는거 ㄱㄱ
		Take();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		used[i] = 1;
		path[lv] = Weight[i];
		MakePath(lv + 1);
		path[lv] = 0;
		used[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> Weight[i];
	}

	MakePath(0);
	
	cout << ans;
	return 0;
}