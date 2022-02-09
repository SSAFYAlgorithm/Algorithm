#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	while(1) {
		stack<char>s;
		int flag = 0;
		string buf;
		getline(cin,buf);
		if (buf==".") return 0;
		for (int i = 0; i < buf.length(); i++) {
			if (buf[i] == '(') {
				s.push(buf[i]);
			}
			else if (buf[i] == ')') {
				if (s.empty()|| s.top()== '[') {
					flag = 1;
					break;
				}
				else s.pop();
			}
			else if (buf[i] == '[') {
				s.push(buf[i]);
			}
			else if (buf[i] == ']') {
				if (s.empty() || s.top() == '(') {
					flag = 1;
					break;
				}
				else s.pop();
			}
		}
		if (flag || !s.empty()) {
			cout << "no" << endl;
		}
		else cout << "yes" << endl;
	}
	return 0;
}