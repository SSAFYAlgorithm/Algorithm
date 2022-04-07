#include <iostream>
#include <queue>

using namespace std;

int country_side[2][2] = {
	50, 30,
	20, 40
};
int visit[2][2];
int country_num;
int flag;

int L = 20;
int R = 50;

int d[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};

void bfs(int y, int x) {
	queue<pair<int, int>> q, copy_q;
	q.push(make_pair(y, x));
	copy_q.push(make_pair(y, x)); // q บนป็
	visit[y][x] = true;
	int sum = 0;
	int cnt = 0;

	while (!q.empty()) {
		int wy = q.front().first;
		int wx = q.front().second;
		q.pop();

		sum = sum + country_side[wy][wx];
		cnt = cnt + 1;
		for (int i = 0; i < 4; i++) {
			int dy = y + d[i][0];
			int dx = x + d[i][1];

			if (dy < 0 || dy >= 2 || dx < 0 || dx >= 2) continue;
			if (visit[dy][dx] != 0) continue;
			if ((20 <= abs(country_side[y][x] - country_side[dy][dx]) && abs(country_side[y][x] - country_side[dy][dx]) <= R) == true) {
				visit[dy][dx] = 1;
				q.push(make_pair(dy, dx));
				copy_q.push(make_pair(dy, dx));
			}
		}
	}
	int move_people = sum / cnt;
	while (!copy_q.empty()) {
		int y = copy_q.front().first;
		int x = copy_q.front().second;

		copy_q.pop();
		country_side[y][x] = move_people;
	}
}


int main() {
	int day_cnt = 0;
	flag = 1;
	while (flag) {
		flag = 0;
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 2; x++) {
				if (visit[y][x] == 0) {
					for (int i = 0; i < 4; i++)
					{
						int dy = y + d[i][0];
						int dx = x + d[i][1];
						if (dy >= 0 && dx >= 0 && dy < 2 && dx < 2)
						{
							if (L <= abs(country_side[y][x] - country_side[dy][dx]) && abs(country_side[y][x] - country_side[dy][dx]) <= R) {
								bfs(y, x);
								flag = 1;
							}
						}
					}
				}
			}
		}
		if (flag) day_cnt++;
		memset(visit, false, sizeof(visit));

	}
	cout << day_cnt << endl;

	return 0;
}