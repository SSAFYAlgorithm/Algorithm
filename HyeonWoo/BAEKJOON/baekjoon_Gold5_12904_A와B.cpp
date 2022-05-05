#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	string S, T;
	cin >> S >> T;
	 // T에서 맨 뒤에서부터 하나씩 줄여온다/

	string str;
	str = T;
	while(S.size() < str.size()) {
		string temp;
		temp = str.substr(0, str.size() - 1);
		if (str[str.size() - 1] == 'B') {
			reverse(temp.begin(), temp.end());
		}
		str = temp;
	}
	if (str == S) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}