#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


int main()
{
	for (int test = 1;test <= 10;test++) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		stack<char>stk;
		int i = 0;
		int flag = 0;
		while (1)
		{
			if (stk.empty()) {
				if (str[i] == '>' || str[i] == '}' || str[i] == ']' || str[i] == ')') {
					flag = 1;
					break;
				}
				else {
					stk.push(str[i]);
				}
			}
			else {

				if (stk.top() == '(') {
					if (str[i] == ')') {
						stk.pop();
					}
					else if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(') {
						stk.push(str[i]);
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (stk.top() == '{') {
					if (str[i] == '}') {
						stk.pop();
					}
					else if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(') {
						stk.push(str[i]);
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (stk.top() == '<') {
					if (str[i] == '>') {
						stk.pop();
					}
					else if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(') {
						stk.push(str[i]);
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (stk.top() == '[') {
					if (str[i] == ']') {
						stk.pop();
					}
					else if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(') {
						stk.push(str[i]);
					}
					else {
						flag = 1;
						break;
					}
				}
			}
			i++;
			if (str.size() == i) break;
		}
		if (flag) {
			cout << "#" << test << " 0" << endl;

		}
		else {
			cout << "#" << test << " 1" << endl;
		}
		while (!stk.empty())stk.pop();
	}

}
