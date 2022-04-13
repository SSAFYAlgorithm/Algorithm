#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, L;
int arr[110][110];
int res;
vector <int> vect;
int used[110];
int isOK() {
	// 투포인터 활용
	int Last = vect[0];
	int now = vect[0];
	int idx = 1;
	while (1) {
		if (idx == N) {
			break;
		}
		Last = vect[idx - 1];
		now = vect[idx];
		// 만약 경사 차이가 2이상이면 만들 수 없다.
		if (abs(now - Last) >= 2) return 1;
		if (Last > now) {
			// now가 전부 똑같아야한다 idx+L전까지는
			for (int i = idx; i < idx + L; i++) {
				if (used[i] == 1) return 1;
				if (i >= N) return 1;
				if (vect[i] != now) {
					return 1;
				}
				used[i] = 1; // 경사로를 만들었다.
			}
			idx++;
		}
		else if (Last < now) {
			for (int i = idx - 1; i >= idx - L; i--) {
				if (used[i] == 1) return 1;
				if (i < 0) return 1;
				if (vect[i] != Last) {
					return 1;
				}
				used[i] = 1; // 경사로를 만들었다.
			}
			idx++;
		}
		else {
			idx++;
			continue;
		}
	}

	return 0;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> L;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}

	// 가로줄부터
	for (int y = 0; y < N; y++) {
		vect = vector<int>();
		for (int x = 0; x < N; x++) {
			vect.push_back(arr[y][x]);
		}

		// 판별
		memset(used, 0, sizeof(used));
		if (!isOK()) {
			res++;
		}
	}

	// 세로줄
	for (int x = 0; x < N; x++) {
		vect = vector<int>();
		for (int y = 0; y < N; y++) {
			vect.push_back(arr[y][x]);
		}


		memset(used, 0, sizeof(used));
		if (!isOK()) {
			res++;
		}

		
	}
	cout << res;

	return 0;
}