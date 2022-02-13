#include <iostream>
#include <stack>
using namespace std;

int main() {

	int command_cnt;
	cin >> command_cnt;

	for (int i = 0; i < command_cnt; i++) {
		stack<char> ps_stack;
		char ps[50];
		cin >> ps;
		
		int flag = 0;
		for (int j = 0; j < 50; j++) {
			if (ps[j] == 0) {
				flag = j;
				break;
			}
		}

		for (int j = 0; j < flag; j++) {
			if (ps_stack.empty() || ps[j] == '(')ps_stack.push(ps[j]);
			else if (ps[j] == ')' && ps_stack.top() == '(')ps_stack.pop();

		}
		if (ps_stack.empty())cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}