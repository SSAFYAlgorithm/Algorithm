#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int arr[52][52];

int dy[] = {9, 0,-1,-1,-1,0,1,1,1 };
int dx[] = {9, -1,-1,0,1,1,1,0,-1 };
struct Node {
	int y, x;
};


vector <Node> Cloud;
vector <Node> LastCloud;

void MoveCloud(int d, int s) {
	for (int i = 0; i < Cloud.size(); i++) {
		int y = Cloud[i].y;
		int x = Cloud[i].x;
		int ny = y + dy[d] * s;
		int nx = x + dx[d] * s;
		if (ny <= 0) {
			ny = N + -1*(abs(ny)%N);
		}
		else if (ny > N) {
			ny = ny%N;
			if (ny == 0) {
				ny = N;
			}
		}
		if (nx <= 0) {
			nx = N + -1 * (abs(nx) % N);
		}
		else if (nx > N) {
			nx = nx%N;
			if (nx == 0) {
				nx = N;
			}
		}
		Cloud[i] = { ny,nx };
	}
}

void Rain() {
	for (int i = 0; i < Cloud.size(); i++) {
		int y = Cloud[i].y;
		int x = Cloud[i].x;
		arr[y][x]++;
	}
}

void Bug() {
	for (int i = 0; i < Cloud.size(); i++) {
		int y = Cloud[i].y;
		int x = Cloud[i].x;
		int cnt = 0;
		for (int dir = 2; dir <= 8; dir += 2) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny <= 0 || nx <= 0 || ny > N || nx > N)continue;
			if(arr[ny][nx] == 0) continue;
			cnt++;
		}
		arr[y][x] += cnt;
	}
}

int isExist(int y, int x) {
	for (int i = 0; i < LastCloud.size(); i++) {
		if (y == LastCloud[i].y && x == LastCloud[i].x) {
			return 1;
		}
	}
	return 0;
}

void MakeCloud() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (arr[y][x] >= 2) {
				if (isExist(y, x)) continue;
				arr[y][x] -= 2;
				Cloud.push_back({ y,x });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}

	Cloud.push_back({ N,1 });
	Cloud.push_back({ N,2 });
	Cloud.push_back({ N-1,1 });
	Cloud.push_back({ N-1,2 });

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		//←, ↖, ↑, ↗, →, ↘, ↓, ↙
		MoveCloud(d,s);
		Rain();
		Bug();
		LastCloud = vector <Node> ();
		LastCloud = Cloud;
		Cloud = vector <Node>();
		MakeCloud();
	}

	int res = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			res += arr[y][x];
		}
	}
	cout << res;
	return 0;
}