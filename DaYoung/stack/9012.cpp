#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		stack<char>s;
		int flag = 0;
		char buf[51];
		cin >> buf;
		for (int j = 0; j < strlen(buf); j++) {
			if (buf[j] == '(') {
				s.push(buf[j]);
			}
			else if (buf[j] == ')') {
				if (s.empty()) {
					flag = 1;
					break;
				}
				else s.pop();
			}
		}
		if (flag||!s.empty()) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}