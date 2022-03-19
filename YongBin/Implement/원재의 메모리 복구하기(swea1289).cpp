#include <iostream>

using namespace std;

string change(string temp, int idx) {
	if (temp[idx] == '0') {
		for (int i = idx; i < temp.length(); i++) {
			temp[i] = '1';
		}
	}
	else {
		for (int i = idx; i < temp.length(); i++) {
			temp[i] = '0';
		}
	}
	return temp;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string result;
		string start = "";
		int ans = 0;

		cin >> result;
		for (int i = 0; i < result.length(); i++) {
			start += '0';
		}

		for (int i = 0; i < result.length(); i++) {
			if (result[i] != start[i]) {
				ans++;
				start = change(start, i);
			}
		}
		
		cout << "#" << i + 1 << " " << ans << "\n";

	}
	return 0;
}