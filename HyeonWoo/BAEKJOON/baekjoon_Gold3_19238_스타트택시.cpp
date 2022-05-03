#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
// 도착지가 겹치는 경우도 있다;; 이렇게 말고 다시풀어보자;
//  여러 승객이 같이 탑승하는 경우는 없다. 출발지는 다 다르다.
int N, M, F;
int TaxiY, TaxiX;
int map[25][25]; //벽을 -1, 출발지점을 1,2,3 이렇게 표현할예정
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int totFlag = 0;
struct Node {
	int y, x;
};
struct Info {
	int y, x, num,dis;
};
vector <Node> EndPoint;

struct comp {
	bool operator()(Info right, Info left) {
		if (left.dis == right.dis) {
			if (left.y == right.y) {
				return left.x < right.x;
			}
			return left.y < right.y;
		}
		return left.dis < right.dis;
	}
};

int ZeroToStart() { // 타겟번호 찍어줄거임
	queue <Node> q;
	priority_queue<Info, vector<Info>, comp> pq;
	int distance[25][25] = { 0 };

	q.push({ TaxiY,TaxiX });
	distance[TaxiY][TaxiX] = -1;
	int tempDis = 0;
	int flag = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dis = distance[y][x];
		if (dis == -1) {
			dis = 0;
		}
		if (!flag && map[y][x] > 0) {
			pq.push({ y,x,map[y][x],dis });
			tempDis = dis;
			flag = 1;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx <= 0 || ny <= 0 || ny > N || nx > N) continue;
			if (distance[ny][nx] != 0) continue;
			if (map[ny][nx] == -1)continue;
			//만약 출발지점 도착했다면 해당 거리랑 작은 값만 push가능
			distance[ny][nx] = dis + 1;
			// 만약 최단거리 출발지점을 찾으면 해당 거리까지만 탐색하도록
			if (flag && map[ny][nx] > 0) {// 가능한 정보를 pq에 넣어줄거임
				pq.push({ ny,nx,map[ny][nx],distance[ny][nx] });
			}
			if (!flag && map[ny][nx] > 0) {
				tempDis = distance[ny][nx]; // MaxDis를 최단거리로 설정
				flag = 1;
				pq.push({ ny,nx,map[ny][nx],distance[ny][nx] });
				continue;
			}

			// 만약 flag==1이면 거리가 MaxDis보다 크다면 continue
			if (flag && distance[ny][nx] >tempDis) continue;
			q.push({ ny,nx });
		}
	}

	if (pq.empty()) {
		return -1;
	}

	TaxiY = pq.top().y;
	TaxiX = pq.top().x;
	map[TaxiY][TaxiX] = 0; // 태웠으니까 없애줘야함
	F -= pq.top().dis;
	return pq.top().num;
}

void StartToEnd(int target) {
	int ey = EndPoint[target].y;
	int ex = EndPoint[target].x;

	queue <Node> q;
	int distance[25][25] = { 0 };
	q.push({ TaxiY,TaxiX });
	distance[TaxiY][TaxiX] = -1;
	int flag = 0; // 성공 여부
	while (!q.empty()) {
		if (flag) break;
		int y = q.front().y;
		int x = q.front().x;
		int dis = distance[y][x];
		if (dis == -1) {
			dis = 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx <= 0 || ny <= 0 || ny > N || nx > N) continue;
			if (distance[ny][nx] != 0) continue;
			if (map[ny][nx] == -1)continue;
			distance[ny][nx] = dis + 1;
			if (ny == ey && nx == ex) {
				TaxiX = nx;
				TaxiY = ny;
				flag = 1;
				break;
			}
			q.push({ ny,nx });
		}
	}
	if (!flag) {
		totFlag = 1;
		return;
	}
	if (F - distance[TaxiY][TaxiX] < 0) {
		totFlag = 1;
		return;
	}
	F = F + distance[TaxiY][TaxiX];
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> F;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				map[y][x] = -1;
			}
		}
	}

	cin >> TaxiY >> TaxiX;
	EndPoint.push_back({ -1,-1 }); // 일단 더미데이터 하나 넣어줌
	
	for (int i = 1; i <= M; i++) {
		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;
		map[sy][sx] = i;
		EndPoint.push_back({ ey,ex });
	}

	for (int i = 1; i <= M; i++) {
		int target = ZeroToStart();
		if (target == -1) {
			cout << -1;
			return 0;
		}
		StartToEnd(target);
		if (totFlag) break;
	}

	if (totFlag) {
		cout << -1;
	}
	else {
		cout << F;
	}

	return 0;
}