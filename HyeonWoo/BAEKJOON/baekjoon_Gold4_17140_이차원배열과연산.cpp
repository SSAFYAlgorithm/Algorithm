#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, K; // arr[R][C] = K가 되는데 걸리는시간
int arr[101][101];
int temparr[101][101];
int used[101];
int res = 0;
int MaxR=3;
int MaxC=3;

struct ValCnt {
	int val;
	int cnt;
};

vector <ValCnt> v; // sort를 활용하기 위해 임시로 만드는 벡터
vector <int> temp;
bool comp(ValCnt a, ValCnt b) {
	if (a.cnt == b.cnt) return a.val < b.val;
	return a.cnt < b.cnt;
}

void CalR() {
	memset(temparr, -1, sizeof(temparr));
	for (int i = 1; i <= MaxR; i++) {
		v = vector <ValCnt> ();
		memset(used, 0, sizeof(used));
		int MaxVal = 0;
		for (int j = 1; j <= MaxC; j++) {
			if (arr[i][j] == -1) break;
			if (arr[i][j] > MaxVal) {
				MaxVal = arr[i][j];
			}
			used[arr[i][j]]++;
		}

		// 구조체 벡터에 정렬되지 않은상태로 넣어줌
		for (int j = 1; j <= MaxVal; j++) {
			if (used[j] > 0) {
				v.push_back({ j,used[j] });
			}
		}

		// 정렬
		sort(v.begin(), v.end(), comp);

		// 새로운벡터에 규칙맞춰서 넣어줌 (값, 개수)
		temp = vector <int>();
		for (int j = 0; j < v.size(); j++) {
			temp.push_back(v[j].val);
			temp.push_back(v[j].cnt);
		}

		// MaxC갱신
		int len = temp.size();
		if (len > 100) len = 100;
		if (len > MaxC) {
			MaxC = len;
		}

		// arr 갱신
		for (int j = 1; j <= len; j++) {
			temparr[i][j] = temp[j - 1];
		}
	}

	// 마지막 0자리 채우기
	for (int i = 1; i <= MaxR; i++) {
		for (int j = 1; j <= MaxC; j++) {
			if (temparr[i][j] == -1)
				temparr[i][j] = 0;
		}
	}
	memcpy(arr, temparr, sizeof(arr));
}

void CalC() {
	memset(temparr, -1, sizeof(temparr));
	for (int j = 1; j <= MaxC; j++) {
		v = vector <ValCnt>();
		memset(used, 0, sizeof(used));
		int MaxVal = 0;
		for (int i = 1; i <= MaxR; i++) {
			if (arr[i][j] == -1) break;
			if (arr[i][j] > MaxVal) {
				MaxVal = arr[i][j];
			}
			used[arr[i][j]]++;
		}

		// 구조체 벡터에 정렬되지 않은상태로 넣어줌
		for (int j = 1; j <= MaxVal; j++) {
			if (used[j] > 0) {
				v.push_back({ j,used[j] });
			}
		}

		// 정렬
		sort(v.begin(), v.end(), comp);

		// 새로운벡터에 규칙맞춰서 넣어줌 (값, 개수)
		temp = vector <int>();
		for (int j = 0; j < v.size(); j++) {
			temp.push_back(v[j].val);
			temp.push_back(v[j].cnt);
		}

		// MaxC갱신
		int len = temp.size();
		if (len > 100) len = 100;
		if (len > MaxR) {
			MaxR = len;
		}

		// arr 갱신
		for (int i = 1; i <= len; i++) {
			temparr[i][j] = temp[i - 1];
		}

	}
	// 마지막 0자리 채우기
	for (int j = 1; j <= MaxC; j++) {
		for (int i = 1; i <= MaxR; i++) {
			if (temparr[i][j] == -1)
				temparr[i][j] = 0;
		}
	}
	memcpy(arr, temparr, sizeof(arr));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	memset(arr, -1, sizeof(arr));
	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}


	while (1) {
		if (res == 101) {
			res = -1;
			break;
		}
		if (arr[R][C] == K) {
			break;
		}

		if (MaxR >= MaxC) CalR();
		else CalC();
		res++;
	}

	cout << res;

	return 0;
}