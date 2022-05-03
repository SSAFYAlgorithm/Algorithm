#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N; // 나와야할 이닝 수
int hit_res[51][10]; // 선수들(0제외 1~9)이 각 이닝에서 얻은 결과 저장
// 아웃 : 0
// 1루타 : 1
// 2루타 : 2
// 3루타 : 3
// 홈런 : 4
int order[10]; // 타순 저장
bool used[10]; // 이미 고른 선수 기록

int score;
int cur_player_num; // 현재 선수 번호
bool base[5];
// base[1] 1루
// base[2] 2루
// base[3] 3루
// base[4] 홈

int maxScore;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> hit_res[i][j];
			// i이닝 j번 선수
		}
	}
}

void set_fourth_hitter() {
	// 4번 타자 세팅
	order[4] = 1; // 4번 타자 = 1번 선수
	used[4] = true; // 4번 타자 자리 선택
}

void set_match_start() {
	// 경기 시작
	score = 0;
	cur_player_num = 1; // 1번타자부터 시작
}

int compareScore(int maxScore, int score) {
	if (maxScore > score)return maxScore;
	else return score;
}

void match_process() {
	for (int N_inning = 1; N_inning <= N; N_inning++) {
		//이닝시작
		int outCnt = 0; // 0아웃부터
		memset(base, 0, sizeof(base)); //base 초기화
		bool end_inning = false; // 이닝 종료 여부

		while (1) {
			for (int i = cur_player_num; i < 10; i++) { // 1번 선수부터
				int cur_player_hit = hit_res[N_inning][order[i]]; // 현재선수가 얻은 결과

				// 현재선수가 얻은 결과에 따라 분기-------------------------------------------------------------------------
				if (cur_player_hit == 0) {
					// 현재 선수가 아웃을 당했을때
					outCnt++;
					if (outCnt == 3) {
						//3아웃
						cur_player_num = i + 1; // 다음이닝은 다음 선수부터
						end_inning = true; // 이닝 종료
						break;
					}
				}
				else if (cur_player_hit == 1) {
					// 현재 선수가 안타 쳤을때, 진루해 있던 주자 진루
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// 모든 선수 1루씩 진루
							if (j == 3) {
								base[j] = false;
								score++; // 홈에 선수가 도착하면 점수+1
							}
							else {
								base[j + 1] = true;
								base[j] = false;
							}
						}
					}
					// 현재 안타 친 선수 진루
					base[1] = true;
				}
				else if (cur_player_hit == 2) {
					// 현재 선수가 2루타 쳤을때
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// 모든 선수 2루씩 진루
							if (j >= 2) {
								base[j] = false;
								score++; // 홈에 선수가 도착하면 점수+1
							}
							else {
								base[j + 2] = true;
								base[j] = false;
							}
						}
					}
					// 현재 안타 친 선수 진루
					base[2] = true;
				}
				else if (cur_player_hit == 3) {
					// 현재 선수가 3루타 쳤을때
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// 모든 선수 3루씩 진루
							if (j >= 1) {
								base[j] = false;
								score++; // 홈에 선수가 도착하면 점수+1
							}
						}
					}
					// 현재 안타 친 선수 진루
					base[3] = true;
				}
				else if (cur_player_hit == 4) {
					// 현재 선수가 홈런 쳤을때
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// 모든 선수 홈으로 복귀
							if (j >= 1) {
								base[j] = false;
								score++; // 홈에 선수가 도착하면 점수+1
							}
						}
					}
					// 현재 안타 친 선수 한바퀴 돌아 홈으로
					score++;
				}
				//----------------------------------------------------------------------------------------------------------
			}
			if (end_inning) break;
			cur_player_num = 1;
		}
	}
	maxScore = compareScore(maxScore, score); // 최고점 비교
}

void match_res() {
	set_match_start();
	match_process(); // 경기 진행
}

void dfs(int playerCnt) {
	if (playerCnt == 10) {
		// 10번째 선수는 없으므로 종료
		match_res(); // 경기 결과 계산
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (used[i] == true) continue;
		order[i] = playerCnt;
		used[i] = true;
		dfs(playerCnt + 1); // 다음 선수
		used[i] = false;
	}
}

void solution() {
	input();
	// 1번 선수를 4번 타자로 지정
	set_fourth_hitter(); // 4번타자 세팅
	dfs(2); // 1번선수는 이미 4번타자로 선택되어 있으므로 2번째선수의 위치를 정할때 2명의 선수를 사용하였다.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	cout << maxScore;

	return 0;
}