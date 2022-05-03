#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int res;
struct Node {
	int y, x;
};
vector <Node> place;

int isOK(int y, int x) {
	for (int i = 0; i < place.size(); i++) {
		if (place[i].x == x) {
			return 0;
		}
		if (abs(place[i].y - y) == (abs(place[i].x - x))) {
			return 0;
		}
	}
	return 1;
}

void dfs(int cnt, int lasty) {
	if (cnt == N) {
		res++;
		return;
	}

	int y = lasty + 1;
	for (int x = 0; x < N; x++) {
		if (isOK(y, x)) {
			place.push_back({ y,x });
			dfs(cnt + 1, y);
			place.pop_back();
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	dfs(0, -1);
	
	cout << res;
	return 0;
}