#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int initmap[23][23];
int map[23][23];
int res = -21e8;
void LEFT() {
	int arr[23][23];
	memcpy(arr, map, sizeof(arr));
	for (int y = 0; y < n; y++) {
		queue <int> temp;
		for (int x = 0; x < n; x++) {
			if (arr[y][x] > 0) {
				temp.push(arr[y][x]);
			}
		}

		if (temp.size() == 0) continue;

		int temparr[23] = {0};
		int idx = 0;
		temparr[idx] = temp.front();
		temp.pop();

		while (!temp.empty()) {
			int now = temp.front();
			temp.pop();
			if (temparr[idx] == now) {
				temparr[idx] += now;
				idx++;
			}
			else if (temparr[idx] == 0) {
				temparr[idx] = now;
			}
			else {
				idx++;
				temparr[idx] = now;
			}
		}

		memcpy(arr[y], temparr, sizeof(temparr));
	}
	memcpy(map, arr, sizeof(map));
}

void RIGHT() {
	int arr[23][23];
	memcpy(arr, map, sizeof(arr));
	for (int y = 0; y < n; y++) {
		queue <int> temp;
		for (int x = n-1; x >= 0; x--) {
			if (arr[y][x] > 0) {
				temp.push(arr[y][x]);
			}
		}

		if (temp.size() == 0) continue;

		int temparr[23] = { 0 };
		int idx = n-1;
		temparr[idx] = temp.front();
		temp.pop();

		while (!temp.empty()) {
			int now = temp.front();
			temp.pop();
			if (temparr[idx] == now) {
				temparr[idx] += now;
				idx--;
			}
			else if (temparr[idx] == 0) {
				temparr[idx] = now;
			}
			else {
				idx--;
				temparr[idx] = now;
			}
		}

		memcpy(arr[y], temparr, sizeof(temparr));
	}
	memcpy(map, arr, sizeof(map));
}

void UP() {
	int arr[23][23];
	memcpy(arr, map, sizeof(arr));
	for (int x = 0; x < n; x++) {
		queue <int> temp;
		for (int y = 0; y < n; y++) {
			if (arr[y][x] > 0) {
				temp.push(arr[y][x]);
			}
		}

		if (temp.size() == 0) continue;

		int temparr[23] = { 0 };
		int idx = 0;
		temparr[idx] = temp.front();
		temp.pop();

		while (!temp.empty()) {
			int now = temp.front();
			temp.pop();
			if (temparr[idx] == now) {
				temparr[idx] += now;
				idx++;
			}
			else if (temparr[idx] == 0) {
				temparr[idx] = now;
			}
			else {
				idx++;
				temparr[idx] = now;
			}
		}

		for (int y = 0; y < n; y++) {
			arr[y][x] = temparr[y];
		}
	}
	memcpy(map, arr, sizeof(map));
}

void DOWN() {
	int arr[23][23];
	memcpy(arr, map, sizeof(arr));
	for (int x = 0; x < n; x++) {
		queue <int> temp;
		for (int y = n-1; y >= 0; y--) {
			if (arr[y][x] > 0) {
				temp.push(arr[y][x]);
			}
		}

		if (temp.size() == 0) continue;

		int temparr[23] = { 0 };
		int idx = n-1;
		temparr[idx] = temp.front();
		temp.pop();

		while (!temp.empty()) {
			int now = temp.front();
			temp.pop();
			if (temparr[idx] == now) {
				temparr[idx] += now;
				idx--;
			}
			else if (temparr[idx] == 0) {
				temparr[idx] = now;
			}
			else {
				idx--;
				temparr[idx] = now;
			}
		}

		for (int y = 0; y < n; y++) {
			arr[y][x] = temparr[y];
		}
	}
	memcpy(map, arr, sizeof(map));
}

int FindMaximum() {
	int max = -21e8;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] > max) {
				max = map[y][x];
			}
		}
	}

	return max;
}

char dir[4] = { 'L','R','U','D' };
vector <char> path;
void DFS(int cnt) {
	if (cnt == 5) {
		int de = -1;
		memcpy(map, initmap, sizeof(map));
		for (int i = 0; i < 5; i++) {
			if (path[i] == 'L') {
				LEFT();
			}
			else if (path[i] == 'R') {
				RIGHT();
			}
			else if (path[i] == 'U') {
				UP();
			}
			else if (path[i] == 'D') {
				DOWN();
			}
		}

		int Max = FindMaximum();
		if (Max > res) {
			res = Max;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		path.push_back(dir[i]);
		DFS(cnt + 1);
		path.pop_back();
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	memcpy(initmap, map, sizeof(map));
	
	DFS(0);

	cout << res;
	return 0;
}