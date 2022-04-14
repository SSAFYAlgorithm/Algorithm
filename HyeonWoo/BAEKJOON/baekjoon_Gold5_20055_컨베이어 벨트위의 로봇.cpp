#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int Life[220];
int Robot[220]; // 1이면 로봇있는상태
int level = 1;
int Cnt; // 0의개수
void Turn() {
	int temp = Life[2*N];
	int RobotTmp = Robot[2*N];
	for (int i = 2*N; i >= 2; i--) {
		Life[i] = Life[i - 1];
		Robot[i] = Robot[i - 1];
	}
	Life[1] = temp;
	Robot[1] = RobotTmp;
}

// 로봇이동
void Move() {
	for (int i = N-1; i >= 1; i--) {
		// 만약 움직이려하는 곳의 수명이 1이상이고, 해당칸에 로봇이 없다면 이동
		if (Robot[i] == 1) {
			if (Life[i + 1] > 0 && Robot[i + 1] == 0) {
				Robot[i + 1] = 1;
				Robot[i] = 0;
				Life[i + 1]--;
				// 만약 수명이 0에 도달하면 0카운트 증가
				if (Life[i + 1] == 0) {
					Cnt++;
				}
				// 만약 Cnt가 K라면 바로 return 후 정답출력할예정
				if (Cnt == K) {
					return;
				}
			}
		}
	}
	// 만약 Robot[N] == 1이면 탈출
	if (Robot[N] == 1) {
		Robot[N] = 0;
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i <= 2*N; i++) {
		cin >> Life[i];
	}

	while (1) {
		// 1. 회전
		Turn();
		// 회전 후 로봇이 N번에있다면 Robot 탈출;
		if (Robot[N] == 1) {
			Robot[N] = 0;
		}

		// 2. 로봇이동
		Move();
		if (Cnt >= K) {
			break;
		}

		// 3. 로봇올리기
		if (Life[1] > 0) {
			Robot[1] = 1;
			Life[1]--;
			// 또, 0에도달하면 개수센다
			if (Life[1] == 0) {
				Cnt++;
				// Cnt가 늘어났으니 K랑 비교 같거나 크면 종료
				if (Cnt >= K) {
					break;
				}
			}
		}

		//모든작업이 끝나면 level 늘리고 반복
		level++;

	}

	cout << level;
	return 0;
}