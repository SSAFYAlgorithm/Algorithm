#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100][100];
int visited[100][100] = { 0 };

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

int n, m, k;
int sum = 0;

void dfs(int x, int y) {
	visited[x][y] = 1;
	sum++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && arr[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	vector<int> result;
	int x1, x2, y1, y2;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				arr[j][k]++;
				visited[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && arr[i][j] == 0) {
				sum = 0;
				dfs(i, j);
				result.push_back(sum);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}