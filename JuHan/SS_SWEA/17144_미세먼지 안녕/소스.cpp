#include <iostream>

using namespace std;

int R, C, T;
int dust[50][50];
int dir[2][4] = {
	0,0,-1,1,
	-1,1,0,0
};
int airCleaner_topPoint[2]; // ����û���� ���κ� ��ǥ
int airCleaner_bottomPoint[2]; // ����û���� �Ʒ��κ� ��ǥ
int total_dust;
int add[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> R >> C >> T;
	bool part_check = false; // ����û���� ��-1, �Ʒ�-1 ����
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> dust[y][x];
			if (dust[y][x] == -1) {
				if (!part_check) {
					airCleaner_topPoint[0] = y;
					airCleaner_topPoint[1] = x;
					part_check = true;
				}
				else if (part_check) {
					airCleaner_bottomPoint[0] = y;
					airCleaner_bottomPoint[1] = x;
				}
			}
			else if (dust[y][x] != 0) {
				total_dust += dust[y][x];
			}
		}
	}

	while (T--) {
		// T�� �پ�鶧���� ���� Ȯ��
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				int block_cnt = 0; // ������ ���� ĭ ��
				int move_dust_amount = dust[y][x] / 5; // ���� �̵�
				if (dust[y][x] == 0 || dust[y][x] == -1) continue;
				for (int d = 0; d < 4; d++) {
					int dy = y + dir[0][d];
					int dx = x + dir[1][d];
					if (dy < 0 || dy >= R || dx < 0 || dx >= C)continue; // ������
					if (dust[dy][dx] == -1) continue; // �̵��ϴ� ������ ����û���� ������
					add[dy][dx] += move_dust_amount;
					block_cnt++;
				}
				add[y][x] -= (block_cnt * move_dust_amount);
			}
		}

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				dust[y][x] += add[y][x];
				add[y][x] = 0; // �����迭 �����ְ� �ʱ�ȭ
			}
		}

		total_dust -= dust[airCleaner_topPoint[0] - 1][0];
		total_dust -= dust[airCleaner_bottomPoint[0] + 1][0];

		// ���κ� (�ݽð�ȸ��)
		for (int i = airCleaner_topPoint[0] - 1; i > 0; i--) {
			dust[i][0] = dust[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			dust[0][i] = dust[0][i + 1];
		}
		for (int i = 1; i <= airCleaner_topPoint[0]; i++) {
			dust[i - 1][C - 1] = dust[i][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			dust[airCleaner_topPoint[0]][i] = dust[airCleaner_topPoint[0]][i - 1];
		}
		dust[airCleaner_topPoint[0]][1] = 0;


		// �Ʒ��κ� (�ð�ȸ��)
		for (int i = airCleaner_bottomPoint[0] + 1; i < R - 1; i++) {
			dust[i][0] = dust[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			dust[R - 1][i] = dust[R - 1][i + 1];
		}
		for (int i = R - 1; i >= airCleaner_bottomPoint[0]; i--) {
			dust[i][C - 1] = dust[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			dust[airCleaner_bottomPoint[0]][i] = dust[airCleaner_bottomPoint[0]][i - 1];
		}
		dust[airCleaner_bottomPoint[0]][1] = 0;
	}
	cout << total_dust << '\n';

	return 0;
}