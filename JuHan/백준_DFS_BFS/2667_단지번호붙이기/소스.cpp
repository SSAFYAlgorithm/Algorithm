#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
bool visited[25][25];
int graph[25][25];

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

int cnt;

vector<int> apart_complex;

void dfs(int y, int x) {
	int i;
	int dy, dx;

	cnt++;
	visited[y][x] = true;
	for (i = 0; i < 4; i++) {
		dy = y + direct[i][0];
		dx = x + direct[i][1];
		if (dy < 0 || dy>=N || dx < 0 || dx >= N) continue;
		if (graph[dy][dx] == 1 && !visited[dy][dx]) {
			dfs(dy,dx);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int i,j,y,x;
	int bin;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			graph[i][j] = str[j] - '0';
		}
	}
	for (y = 0; y < N; y++) {
		for (x = 0; x < N; x++) {
			if (graph[y][x] == 1 && !visited[y][x]) {
				cnt = 0;
				dfs(y, x);
				apart_complex.push_back(cnt);
			}
		}
	}
	sort(apart_complex.begin(), apart_complex.end());
	cout << apart_complex.size() << "\n";

	for (i = 0; i < apart_complex.size(); i++) {
		cout << apart_complex[i] << "\n";
	}

	return 0;
}