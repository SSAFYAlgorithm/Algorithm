#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int width,height,k;
bool visited[51][51];
int graph[51][51];

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

int cnt;

void init() {
	int y, x;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			graph[y][x] = 0;
		}
	}
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			visited[y][x] = false;
		}
	}
}


void dfs(int y, int x) {
	int i;
	int dy, dx;

	visited[y][x] = true;
	for (i = 0; i < 4; i++) {
		dy = y + direct[i][0];
		dx = x + direct[i][1];
		if (dy < 0 || dy >= height || dx < 0 || dx >= width) continue;
		else {
				if (graph[dy][dx] == 1 && !visited[dy][dx]) {
				dfs(dy, dx);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int times;
	cin >> times;

	int i, j, y, x;

	for (i = 0; i < times; i++) {
		cin >> width >> height >> k;
		
		init();

		while (k--) {
			cin >> x >> y;
			graph[y][x] = 1;
		}

		cnt = 0;
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (graph[y][x] == 1 && !visited[y][x]) {
					dfs(y, x);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

	}

	return 0;
}