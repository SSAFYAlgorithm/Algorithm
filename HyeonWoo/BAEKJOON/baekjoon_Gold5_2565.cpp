#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dp[105];

struct Line {
	int from;
	int to;
};

vector <Line> vect;
bool comp(Line left, Line right) {
	return left.to < right.to;
}
bool comp2(Line left, Line right) {
	return left.from < right.from;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		vect.push_back({ from,to });
	}

	// to를 기준으로 오른차순 정렬
	sort(vect.begin(), vect.end(), comp);
	
	dp[0] = 1;
	int res1 = 0;
	// from이 최대가되는 오름차순 설정
	for (int i = 1; i < n; i++) {
		for (int j =0; j < i; j++) {
			if (vect[j].from < vect[i].from) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == 0) {
			dp[i] = 1;
		}
		if (dp[i] > res1) {
			res1 = dp[i];
		}
	}
	

	// 반대의 경우도 고려해준다.
	// 
	// from를 기준으로 오른차순 정렬
	sort(vect.begin(), vect.end(), comp2);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int res2 = 0;
	// from이 최대가되는 오름차순 설정
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vect[j].to < vect[i].to) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == 0) {
			dp[i] = 1;
		}
		if (dp[i] > res1) {
			res2 = dp[i];
		}
	}
	cout << n - max(res1,res2);


	return 0;
}