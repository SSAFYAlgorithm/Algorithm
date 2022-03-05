#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string str;
	cin >> str;

	stack<char>stk;
	int cnt = 0;
	for (int i = 0;i < str.length();i++) {
		if (str[i] == '(') {
			stk.push('(');
		}
		else if (str[i] == ')')
		{
			stk.pop();
			if (str[i - 1] == '(') {
				cnt += stk.size();
			}
			else {
				cnt += 1;
			}
		}
	}
	cout << cnt;
}