#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a;
	int flag = 1;
	for (int i = 0;i < n;i++) {
		stack<int> stack;
		string str;
		cin >> str;
		for (int i = 0;i < str.size();i++) {
			if (str[i] == '(') {
				stack.push(1);
			}
			else if (str[i] == ')') {
				if (stack.empty()) {
					flag = 0;
					break;
				}
				else {
					stack.pop();
				}
			}
		}
		if (!stack.empty()) {
			flag = 0;
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		flag = 1;
	}

}