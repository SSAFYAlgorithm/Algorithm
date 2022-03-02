#include <iostream>

using namespace std;

int main() {
	string s;
	int a = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i + 1])
			a++;
	}
	cout << a / 2;
	return 0;
}