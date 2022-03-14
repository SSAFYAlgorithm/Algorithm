#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx1[] = { 1,-1 };
int dy1[] = { 1, -1 };

int dx2[] = { 0,0 };
int dy2[] = { -1,1 };

int dx3[] = { 1,-1 };
int dy3[] = { 0,0 };

int dx4[] = { -1,1 };
int dy4[] = { 1,-1 };

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int arr[21][21] = { 0 };
		cin >> n;
		vector<pair<int, int>> v;
		string temp;
		int flag = 0;

		for (int j = 0; j < n; j++) {
			cin >> temp;
			for (int k = 0; k < temp.length(); k++) {
				if (temp[k] == '.')
					arr[j][k] = 0;
				else {
					arr[j][k] = 1;
					v.push_back({ j,k });
				}
			}
		}
		//---------------------대각1----------------------
		for (int j = 0; j < v.size(); j++) {
			int visited[21][21] = { 0 };
			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ v[j].first, v[j].second });
			
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				visited[x][y] = 1;
				q.pop();

				if (cnt >= 5) {
					flag = 1;
					break;
				}

				for (int k = 0; k < 2; k++) {
					int nx = x + dx1[k];
					int ny = y + dy1[k];

					if (nx < n && nx >= 0 && ny < n && ny >= 0 && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
						q.push({ nx,ny });
						cnt++;
					}
				}
			}
			if (flag == 1)
				break;
		}

		//---------------------대각2----------------------
		for (int j = 0; j < v.size(); j++) {
			int visited[21][21] = { 0 };
			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ v[j].first, v[j].second });

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				visited[x][y] = 1;
				q.pop();

				if (cnt >= 5) {
					flag = 1;
					break;
				}

				for (int k = 0; k < 2; k++) {
					int nx = x + dx4[k];
					int ny = y + dy4[k];

					if (nx < n && nx >= 0 && ny < n && ny >= 0 && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
						q.push({ nx,ny });
						cnt++;
					}
				}
			}
			if (flag == 1)
				break;
		}

		//---------------------상하----------------------
		for (int j = 0; j < v.size(); j++) {
			if (flag == 1)
				break;
			int visited[21][21] = { 0 };
			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ v[j].first, v[j].second });

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				visited[x][y] = 1;
				q.pop();
				if (cnt >= 5) {
					flag = 1;
					break;
				}

				for (int k = 0; k < 2; k++) {
					int nx = x + dx2[k];
					int ny = y + dy2[k];

					if (nx < n && nx >= 0 && ny < n && ny >= 0 && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
						q.push({ nx,ny });
						cnt++;
					}
				}
			}
			if (flag == 1)
				break;
		}
		//---------------------좌우----------------------
		for (int j = 0; j < v.size(); j++) {
			if (flag == 1)
				break;
			int visited[21][21] = { 0 };
			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ v[j].first, v[j].second });

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				visited[x][y] = 1;
				q.pop();
				if (cnt >= 5) {
					flag = 1;
					break;
				}

				for (int k = 0; k < 2; k++) {
					int nx = x + dx3[k];
					int ny = y + dy3[k];

					if (nx < n && nx >= 0 && ny < n && ny >= 0 && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
						q.push({ nx,ny });
						cnt++;
					}
				}
			}
			if (flag == 1)
				break;
		}

		if (flag == 1)
			cout << "#" << i+1 <<" YES\n";
		else
			cout << "#" << i+1 <<" NO\n";


	}
	return 0;
}