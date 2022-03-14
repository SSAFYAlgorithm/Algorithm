#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		int ans = 0;
		char before = ' ';
		vector<char> st;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			st.push_back(s[i]);
		}
		int temp = 0;
		for (int i = 0; i < st.size(); i++) {
			if (st[i] == '(')
				temp++;
			else {
				temp--;
				if (before == '(')
					ans += temp;
				else
					ans += 1;
			}
			before = st[i];
		}
		cout << "#" << i + 1 << " " << ans << "\n";
	}
	return 0;
}