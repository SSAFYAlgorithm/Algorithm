#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int arr[6][21] = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
	{10,13,16,19,25},
	{20,22,24,25},
	{30,28,27,26,25},
	{25,30,35,40},
	{0}
};



struct INFO {
	int type, idx;
};



vector <int> player;
int info[10];

int ans = 0;

void play() {
	int score = 0;
	int used[6][21] = { 0 }; // type 5은 종료타입
	INFO playerInfo[5] = { // 현재위치 파악정보 (가장 Type이 큰것이 들어갈것)
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0}
	};
	vector <INFO> Last[5]; // 이전에 어디를 채웠는지 (과거정보)
	for (int i = 0; i < 10; i++) {
		int nowPlayer = player[i];
		int go = info[i]; // 몇칸갈지
		int nowType = playerInfo[nowPlayer].type;
		int nowIdx = playerInfo[nowPlayer].idx;
		int nextType = nowType;
		int nextIdx = nowIdx + go;
		if (nextType == 5) return; // 이미 완주했다. (dfs로 이미 순서 정했기 때문에 return)-> 될수없는 순서
		if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.

		// 이제 가능하다는것을 알았으니 이전 used배열 삭제
		for (int j = 0; j < Last[nowPlayer].size(); j++) {
			used[Last[nowPlayer][j].type][Last[nowPlayer][j].idx] = 0;
		}
		Last[nowPlayer] = vector <INFO>(); // 이제 갱신하는값 넣어줄것이므로 초기화

		// used배열 입력
		// 특정한 값인지부터 파악
		if (nextType == 0) {
			if (nextIdx == 5) {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
				nextType = 1;
				nextIdx = 0;
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx == 10) {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
				nextType = 2;
				nextIdx = 0;
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx == 15) {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
				nextType = 3;
				nextIdx = 0;
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx == 20) {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
				nextType = 4;
				nextIdx = 3;
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx > 20) {
				nextType = 5;
				nextIdx = 0;
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else {
				// 특정한 경우가 아니라면
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
		}
		else if(nextType == 1 || nextType == 3){
			// 넘쳐나는 경우 고려해야한다. (최대 4개)
			if (nextIdx > 4) {
				nextType = 4;
				nextIdx = (nextIdx - 4);
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx == 4) {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
				nextType = 4;
				nextIdx = (nextIdx - 4);
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}

		}
		else if (nextType == 2) {
			// 넘쳐나는 경우 고려해야한다. (최대 3개)
			if (nextIdx > 3) {
				nextType = 4;
				nextIdx = (nextIdx - 3);
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx == 3) {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
				nextType = 4;
				nextIdx = (nextIdx - 3);
				if (used[nextType][nextIdx] != 0) return; // 이미 다른플레이어가 들어가있다.
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}

		}
		else if (nextType == 4) {
			// 종료되는 조건을 파악해야한다.
			if (nextIdx > 3) {
				nextType = 5;
				nextIdx = 0;
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else if (nextIdx == 3) {
				// 0,20 도 같이 적용해줘야한다.
				used[0][20] = nowPlayer;
				Last[nowPlayer].push_back({ 0,20 });
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
			else {
				used[nextType][nextIdx] = nowPlayer;
				Last[nowPlayer].push_back({ nextType,nextIdx });
			}
		}
		if (nextType != 5) {
			score += arr[nextType][nextIdx];
		}
		playerInfo[nowPlayer] = { nextType,nextIdx };

	}

	if (score > ans) {
		ans = score;
	}
	return;
}

int isSame() {
	int temp[] = {1,1,1,1,2,2,2,2,2,2};
	for (int i = 0; i < 10; i++) {
		if (temp[i] != player[i]) {
			return 0;
		}
	}
	return 1;
}

void dfs(int level) {
	if (level == 10) {
		if (isSame()) {
			int de = -1; // 디버깅용
		}
		play();

		return;
	}
	// 첫스타트는 누가해도 상관없으니 0이 스타트하기로 생각하고 플레이
	for (int i = 1; i < min(level+2,5); i++) {
		player.push_back(i);
		dfs(level + 1);
		player.pop_back();
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		cin >> info[i];
	}

	dfs(0);
	cout << ans;
	
	return 0;
}