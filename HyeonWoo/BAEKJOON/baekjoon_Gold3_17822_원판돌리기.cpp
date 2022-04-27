#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, T;

vector<vector <int>> Circle;
struct Node {
	int y;
	int x;
};

void ReverseClock(int x, int k) {
	for (int i = 1; i <= N; i++) {
		if (i % x != 0) continue;
		vector <int> temp;
		// mid이후부터 끝까지 넣고, mid까지 넣고
		int mid = k % M;
		for (int j = mid; j < M; j++) {
			temp.push_back(Circle[i][j]);
		}
		for (int j = 0; j < mid; j++) {
			temp.push_back(Circle[i][j]);
		}
		Circle[i] = temp;
	}
}

void Clock(int x, int k) {
	for (int i = 1; i <= N; i++) {
		if (i % x != 0) continue;
		vector <int> temp;
		// mid 이후부터 끝까지 넣고, mid까지 넣고
		int mid = M - k % M;
		for (int j = mid; j < M; j++) {
			temp.push_back(Circle[i][j]);
		}
		for (int j = 0; j < mid; j++) {
			temp.push_back(Circle[i][j]);
		}
		Circle[i] = temp;
	}
}

void ChangeSame() {
	int dy[] = { -1,1,0,0};
	int dx[] = { 0,0,-1,1 }; 
	int totflag = 0; // 만약 한번이라도 변한게 있다면 totflag를 1로 만들어줄 예정
	int totsum = 0;
	int cnt = 0; // 0이아닌것의 개수
	vector <vector <int>> tempCircle;
	tempCircle = Circle;
	
	// 처음과 끝이 이어져있기때문에 x가 0인인덱스를 뒤에 붙혀준다.
	for (int y = 1; y <= N; y++) {
		tempCircle[y].push_back(tempCircle[y][0]);
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 0; x < M; x++) {
			if (tempCircle[y][x] == 0) continue; // 이미 없애줬으면 스킵
			//BFS로 인접한게 있다면 0으로 바꿔줄 예정 (주위에 같은게 있다면 BFS돌림)
			totsum += tempCircle[y][x];
			cnt++;
			int flag = 0;

			if (y == 1 && x == 0) { //우,하만 가능 (1 3) 0 상 1 하 2 좌 3 우
				if (tempCircle[y + dy[1]][x + dx[1]] == tempCircle[y][x] ||
					tempCircle[y + dy[3]][x + dx[3]] == tempCircle[y][x]) {
					flag = 1;
					totflag = 1;
				}
			}
			else if (y == 1) { // 좌 , 우 , 하 1,2,3
				if (tempCircle[y + dy[1]][x + dx[1]] == tempCircle[y][x] ||
					tempCircle[y + dy[2]][x + dx[2]] == tempCircle[y][x] ||
					tempCircle[y + dy[3]][x + dx[3]] == tempCircle[y][x]) {
					flag = 1;
					totflag = 1;
				}
			}
			else if (y == N && x == 0) { //상, 우만 가능 (0 3)
				if (tempCircle[y + dy[0]][x + dx[0]] == tempCircle[y][x] ||
					tempCircle[y + dy[3]][x + dx[3]] == tempCircle[y][x]) {
					flag = 1;
					totflag = 1;
				}
			}
			else if (y == N) { //좌, 상, 우만 가능 (0 2 3)
				if (tempCircle[y + dy[0]][x + dx[0]] == tempCircle[y][x] ||
					tempCircle[y + dy[2]][x + dx[2]] == tempCircle[y][x] ||
					tempCircle[y + dy[3]][x + dx[3]] == tempCircle[y][x]) {
					flag = 1;
					totflag = 1;
				}
			}
			else if (x == 0) { //상, 하, 우만 가능 (0 1 3)
				if (tempCircle[y + dy[0]][x + dx[0]] == tempCircle[y][x] ||
					tempCircle[y + dy[1]][x + dx[1]] == tempCircle[y][x] ||
					tempCircle[y + dy[3]][x + dx[3]] == tempCircle[y][x]) {
					flag = 1;
					totflag = 1;
				}
			}
			else {
				if (tempCircle[y + dy[0]][x + dx[0]] == tempCircle[y][x] ||
					tempCircle[y + dy[1]][x + dx[1]] == tempCircle[y][x] ||
					tempCircle[y + dy[2]][x + dx[2]] == tempCircle[y][x] ||
					tempCircle[y + dy[3]][x + dx[3]] == tempCircle[y][x]) {
					flag = 1;
					totflag = 1;
				}
			
			}
			if (flag) {
				queue <Node> q;
				q.push({ y,x });
				int standard = tempCircle[y][x];
				tempCircle[y][x] = 0;
				while (!q.empty()) {
					int nowy = q.front().y;
					int nowx = q.front().x;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = nowy + dy[i];
						int nx = nowx + dx[i];
						if (ny <= 0 || nx<0 || ny>N || nx > M) continue;
						if (tempCircle[ny][nx] != standard) continue;
						tempCircle[ny][nx] = 0;
						q.push({ ny,nx });
					}
				}
			}
			
		}

	}

	// 끝나면 x=1부터 x=M 까지를 본 Circle에 담는다
	for (int y = 1; y <= N; y++) {
		for (int x = 0; x <M; x++) {
			
			Circle[y][x] = tempCircle[y][x];
			if (x == 0 && tempCircle[y][M] == 0) {
				Circle[y][x] = 0;
			}
		}
	}

	if (!totflag) { // 한개라도 0으로 바뀌지 않는 경우
		// 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
		float mean = (float)totsum / (float)cnt;
		for (int y = 1; y <= N; y++) {
			for (int x = 0; x < M; x++) {
				if (Circle[y][x] == 0) continue;
				if (Circle[y][x] > mean) Circle[y][x]--;
				else if (Circle[y][x] < mean) Circle[y][x]++;
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> T;
	Circle.push_back({}); // 0번으로 더미배열 푸시
	for (int i = 1; i <= N; i++) {
		Circle.push_back({});
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			Circle[i].push_back(temp);
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		// 번호가 x의 배수인 원판을 d방향으로 k칸 회전시킨다. 
		// d가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.

		if (d == 0) {
			Clock(x,k);
		}
		else if (d == 1) {
			ReverseClock(x,k);
		}

		// 회전후 같은부분이 있는지 탐색 y가 나란히 있거나 x가 나란히 있으면 0으로 바꿔준다.
		ChangeSame();
	}

	// 마지막 원판에 있는 값들의 합 출력
	int res = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 0; x < M; x++) {
			if (Circle[y][x] == 0) continue;
			res += Circle[y][x];
		}
	}

	cout << res;

	
	return 0;
}