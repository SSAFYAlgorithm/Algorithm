#include<iostream>

using namespace std;

int map[505][505] = { 0 };
int N, M;

void solve()
{
	int sum = 0;
	int maxValue = -1;
	int now;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {

			now = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];//��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];//��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];//��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];//���α䤤
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];// ��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];//�ݴ� ��
			if (maxValue < now)maxValue = now;
			now = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 2][j];//�ݴ뼼�α� ��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];//��
			if (maxValue < now)maxValue = now;
			now = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 2];//�ݴ� ��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];//���α� ��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];//�ݴ� ���� �� ��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (maxValue < now)maxValue = now;
			now = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2];
			if (maxValue < now)maxValue = now;
			now = map[i + 1][j] + map[i + 2][j] + map[i][j + 1] + map[i + 1][j + 1];
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (maxValue < now)maxValue = now;
			now = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];//��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];//��
			if (maxValue < now)maxValue = now;
			now = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];//��
			if (maxValue < now)maxValue = now;
			now = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];//��
			if (maxValue < now)maxValue = now;
		}
	}
	cout << maxValue;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}
	solve();
}