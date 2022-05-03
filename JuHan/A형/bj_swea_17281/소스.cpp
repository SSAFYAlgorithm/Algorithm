#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N; // ���;��� �̴� ��
int hit_res[51][10]; // ������(0���� 1~9)�� �� �̴׿��� ���� ��� ����
// �ƿ� : 0
// 1��Ÿ : 1
// 2��Ÿ : 2
// 3��Ÿ : 3
// Ȩ�� : 4
int order[10]; // Ÿ�� ����
bool used[10]; // �̹� �� ���� ���

int score;
int cur_player_num; // ���� ���� ��ȣ
bool base[5];
// base[1] 1��
// base[2] 2��
// base[3] 3��
// base[4] Ȩ

int maxScore;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> hit_res[i][j];
			// i�̴� j�� ����
		}
	}
}

void set_fourth_hitter() {
	// 4�� Ÿ�� ����
	order[4] = 1; // 4�� Ÿ�� = 1�� ����
	used[4] = true; // 4�� Ÿ�� �ڸ� ����
}

void set_match_start() {
	// ��� ����
	score = 0;
	cur_player_num = 1; // 1��Ÿ�ں��� ����
}

int compareScore(int maxScore, int score) {
	if (maxScore > score)return maxScore;
	else return score;
}

void match_process() {
	for (int N_inning = 1; N_inning <= N; N_inning++) {
		//�̴׽���
		int outCnt = 0; // 0�ƿ�����
		memset(base, 0, sizeof(base)); //base �ʱ�ȭ
		bool end_inning = false; // �̴� ���� ����

		while (1) {
			for (int i = cur_player_num; i < 10; i++) { // 1�� ��������
				int cur_player_hit = hit_res[N_inning][order[i]]; // ���缱���� ���� ���

				// ���缱���� ���� ����� ���� �б�-------------------------------------------------------------------------
				if (cur_player_hit == 0) {
					// ���� ������ �ƿ��� ��������
					outCnt++;
					if (outCnt == 3) {
						//3�ƿ�
						cur_player_num = i + 1; // �����̴��� ���� ��������
						end_inning = true; // �̴� ����
						break;
					}
				}
				else if (cur_player_hit == 1) {
					// ���� ������ ��Ÿ ������, ������ �ִ� ���� ����
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// ��� ���� 1�羿 ����
							if (j == 3) {
								base[j] = false;
								score++; // Ȩ�� ������ �����ϸ� ����+1
							}
							else {
								base[j + 1] = true;
								base[j] = false;
							}
						}
					}
					// ���� ��Ÿ ģ ���� ����
					base[1] = true;
				}
				else if (cur_player_hit == 2) {
					// ���� ������ 2��Ÿ ������
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// ��� ���� 2�羿 ����
							if (j >= 2) {
								base[j] = false;
								score++; // Ȩ�� ������ �����ϸ� ����+1
							}
							else {
								base[j + 2] = true;
								base[j] = false;
							}
						}
					}
					// ���� ��Ÿ ģ ���� ����
					base[2] = true;
				}
				else if (cur_player_hit == 3) {
					// ���� ������ 3��Ÿ ������
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// ��� ���� 3�羿 ����
							if (j >= 1) {
								base[j] = false;
								score++; // Ȩ�� ������ �����ϸ� ����+1
							}
						}
					}
					// ���� ��Ÿ ģ ���� ����
					base[3] = true;
				}
				else if (cur_player_hit == 4) {
					// ���� ������ Ȩ�� ������
					for (int j = 3; j >= 1; j--) {
						if (base[j] == true) {
							// ��� ���� Ȩ���� ����
							if (j >= 1) {
								base[j] = false;
								score++; // Ȩ�� ������ �����ϸ� ����+1
							}
						}
					}
					// ���� ��Ÿ ģ ���� �ѹ��� ���� Ȩ����
					score++;
				}
				//----------------------------------------------------------------------------------------------------------
			}
			if (end_inning) break;
			cur_player_num = 1;
		}
	}
	maxScore = compareScore(maxScore, score); // �ְ��� ��
}

void match_res() {
	set_match_start();
	match_process(); // ��� ����
}

void dfs(int playerCnt) {
	if (playerCnt == 10) {
		// 10��° ������ �����Ƿ� ����
		match_res(); // ��� ��� ���
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (used[i] == true) continue;
		order[i] = playerCnt;
		used[i] = true;
		dfs(playerCnt + 1); // ���� ����
		used[i] = false;
	}
}

void solution() {
	input();
	// 1�� ������ 4�� Ÿ�ڷ� ����
	set_fourth_hitter(); // 4��Ÿ�� ����
	dfs(2); // 1�������� �̹� 4��Ÿ�ڷ� ���õǾ� �����Ƿ� 2��°������ ��ġ�� ���Ҷ� 2���� ������ ����Ͽ���.
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