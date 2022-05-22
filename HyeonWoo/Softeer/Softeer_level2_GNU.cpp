#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int N, M, res;
vector <int> vel, vel2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			vel.push_back(b);
		}
	}
	
	for (int i = 0; i < M; i++) {
		int h, v;
		cin >> h >> v;
		for (int j = 0; j < h; j++) {
			vel2.push_back(v);
		}
	}

	for (int i = 0; i < 100; i++) {
		res = max(res, vel2[i] - vel[i]);
	}
	cout << res;
	return 0;

}