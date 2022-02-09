#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int flag = 1;

	while (1)
	{
		string str;
		stack<char> stk;

		getline(cin, str);
		if (str == ".") break;
		else {
			for (int i = 0;i < str.size();i++) {
				if (str[i] == '(') {
					stk.push('(');

				}
				if (str[i] == '[') {
					stk.push('[');

				}
				if (str[i] == ')') {
					if (stk.empty()) {
						flag = 0;
						break;
					}
					if (stk.top() != '(') {
						flag = 0;
						break;
					}
					stk.pop();
				}
				if (str[i] == ']') {
					if (stk.empty()) {
						flag = 0;
						break;
					}
					if (stk.top() != '[') {
						flag = 0;
						break;
					}
					stk.pop();
				}
			}

		}
		if (!stk.empty()) {
			flag = 0;
		}
		if (flag) cout << "yes\n";
		else cout << "no\n";
		flag = 1;
		while (!stk.empty()) stk.pop();
	}
}
