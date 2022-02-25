#include<iostream>
#include<queue>
#include<vector>
#include <string>
using namespace std;


int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++) {
		string a; // 정답
		cin >> a;
		string b = a;

		for (int j = 0; j < a.length(); j++) {
			b[j] = '0';
		}

		int ans = 0;
		int startindex = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == '1') {
				startindex = j;
				break;
			}
		}

		for (int j = startindex; j < a.length(); j++) {
			if (a[j] == '1') {
				ans++;
				for (int k = j; k < a.length(); k++) {
					b[k] = '1';
				}
			}
			else if (a[j] == '0') {
				ans++;
				for (int k = j; k < a.length(); k++) {
					b[k] = '0';
				}
			}
			if (a == b) {
				break;
			}
			for (int k = 0; k < a.length(); k++) {
				if (a[k] != b[k]) {
					j = k-1;
					break;
				}
			}
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}