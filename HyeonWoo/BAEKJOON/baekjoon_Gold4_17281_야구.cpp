#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector <int> player;
int used[10];
int playerResult[51][10];
int ans = 0;
int tempres = 0; // 이닝별 max값 구하기 위함
int base[4] = { 0 };
int lastplayer = 0;
int Go(int n) { // 몇점 추가되는지
	// n루타 쳤을때
	int plus = 0;
	int tempBase[8] = {0};
	for (int i = 1; i < 4; i++) {
		tempBase[i + n] = base[i];
	}
	tempBase[n] = 1;

	for (int i = 1; i <= 3; i++) {
		base[i] = tempBase[i];
	}

	for (int i = 4; i <= 7; i++) {
		plus += tempBase[i];
	}

	return plus;
}

int play(int inig) { // 몇이닝인지
	int out = 0;
	int score = 0;
	memset(base, 0, sizeof(base));
	int i = lastplayer+1;
	if (i == 10) {
		i = 1;
	}
	while(1) {
		int NowPlayer = player[i];
		int NowPlayerRes = playerResult[inig][NowPlayer];
		if (NowPlayerRes == 0) {
			out++;
			if (out == 3) {
				lastplayer = i;
				break;
			}
		}
		else {
			score += Go(NowPlayerRes);
		}
		i++;
		if (i == 10) {
			i = 1;
		}
	}

	return score;
}

int Debug() {
	int temp[10] = { 0,2,3,4,1,6,7,8,9,5 };
	for (int i = 1; i <= 9; i++) {
		if (temp[i] != player[i]) {
			return 0;
		}
	}
	return 1;
}

void dfs(int num) { // num : 몇번타석인지
	if (num == 9) {
		/*if (Debug()) {
			int de = -1;
		}*/
		lastplayer = 0;
		int score = 0;
		for (int i = 1; i <= N; i++) {
			score += play(i);
		}
		ans = max(ans,score);
		return;
	}

	if (num == 3) {
		player.push_back(1);
		used[1] = 1;
		dfs(num + 1);
		player.pop_back();
		used[1] = 0;
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (used[i] != 0) continue;
			player.push_back(i);
			used[i] = 1;
			dfs(num + 1);
			used[i] = 0;
			player.pop_back();
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	player.push_back(-1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> playerResult[i][j];
		}
	}

	dfs(0);

	cout << ans;
	return 0;
}