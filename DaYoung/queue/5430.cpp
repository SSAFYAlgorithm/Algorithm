#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int testCase, n;
	string p, arr;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		deque<string> ans;
		cin >> p >> n >> arr;
		arr = arr.substr(1, arr.length() - 1);
		int a = 0, eflag = 0, rcnt = 0;
		for (int j = 0; j < arr.length(); j++) {
			if (n == 0) break;
			if (arr[j] == ',' || arr[j]==']') {
				ans.push_back(arr.substr(a, j-a));
				a = j+1;
			}
		}

		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') rcnt++;
			else if (p[j] == 'D') {
				if (ans.empty()) {
					eflag = 1;
					break;
				}
				else if (rcnt % 2) ans.pop_back();
				else ans.pop_front();
			}
		}
		if (eflag) cout << "error\n";
		else {
			cout << "[";
			if (rcnt % 2) {
				while (!ans.empty()) {
					if (ans.size() == 1) cout << ans.back();
					else cout << ans.back() << ",";
					ans.pop_back();
				}
			}
			else {
				while (!ans.empty()) {
					if (ans.size() == 1) cout << ans.front();
					else cout << ans.front() << ",";
					ans.pop_front();
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}