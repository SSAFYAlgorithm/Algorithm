#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
//#include <fstream>
//#include <iomanip>

using namespace std;

vector<pair<int, int>> mst[12];
int check[12];
char map[21][21];

int w, h, flag, ans = 987654321;
char temp;
vector<pair<int, int>> dirty;
//queue<int> aaaa;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(int sx, int sy, int ex, int ey) {
	int visited[21][21] = { 0 };
	int k = 0;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == ex && y == ey) {
			//k = 1;
			//break;
			return visited[x][y] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < h && ny >= 0 && ny < w && visited[nx][ny] == 0 && map[nx][ny] != 'x') {
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	/*
	cout << "\n";
	if (k == 1) {
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				cout << setw(2) << visited[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		return visited[ex][ey] - 1;
	}
	*/
	return -1;
}

void makeMST() {
	for (int i = 0; i < dirty.size(); i++) {
		for (int j = i + 1; j < dirty.size(); j++) {
			int a = bfs(dirty[i].first, dirty[i].second, dirty[j].first, dirty[j].second);
			if (a == -1) {
				flag = 1;
				return;
			}
			mst[i].push_back({ j,a });
			mst[j].push_back({ i,a });
		}
	}
}

void dfs(int start, int cnt, int sum) {
	//cout << start << " ";
	if (cnt == dirty.size() - 1) {
		//cout << ans << " " << sum << "\n";
		ans = min(ans, sum);
		/*
		int addd = aaaa.size();
		int add = 0;
		while (add < addd) {
			int ad = aaaa.front();
			cout << ad <<" ";
			aaaa.pop();
			aaaa.push(ad);
			add++;
		}
		cout << "\n";
		*/
		return;
	}

	for (int i = 0; i < mst[start].size(); i++) {
		if (check[mst[start][i].first] == 0) {
			check[mst[start][i].first] = 1;
			//aaaa.push(mst[start][i].first);
			int next = sum + mst[start][i].second;
			//cout << start << " " << i << " " << next << "\n";
			dfs(mst[start][i].first, cnt + 1, next);
			//cout << "\n";
			//aaaa.pop();
			check[mst[start][i].first] = 0;
		}
	}
}

void init() {
	memset(check, 0, sizeof(check));
	dirty.clear();
	for (int i = 0; i < 12; i++) {
		mst[i].clear();
	}
	ans = 987654321;
	flag = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//ifstream is("pro.txt");
	//ifstream as("answer.txt");
	while (1) {
		cin >> w >> h;
		//is >> w >> h;
		if (w == 0 && h == 0) {
			return 0;
		}

		init();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//is >> temp;
				cin >> temp;
				if (temp == 'o') {
					dirty.insert(dirty.begin(), { i,j });
				}
				else if (temp == '*') {
					dirty.push_back({ i,j });
				}
				map[i][j] = temp;
			}
		}
		makeMST();
		/*
		for (int i = 0; i < dirty.size(); i++) {
			for (int j = 0; j < mst[i].size(); j++) {
				cout << i << " "<< mst[i][j].first << " " << mst[i][j].second << "\n";
			}
		}
		cout << "\n";
		
		int k;
		as >> k;
		*/
		if (flag == 1) {
			cout << -1 << "\n";
			/*
			if (k != -1) {
				cout << w << " "<< h << " " << k << " " << -1 << "\n";
			}
			*/
		}
		else {
			check[0] = 1;
			dfs(0, 0, 0);
			cout << ans << "\n";
			/*
			if (k != ans) {
				cout << w << " " << h <<  " " << k << " " << ans << "\n";
			}
			*/
		}
	}
	return 0;
}