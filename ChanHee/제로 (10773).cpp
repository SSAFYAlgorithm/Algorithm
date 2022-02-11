#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int order;
	cin >> order; //명령 수

	stack<int> stack;
	
	int a; // 명령, 0이면 pop, 아닐경우 push


	for (int i = 0; i < order; i++) {
		cin >> a;
		if (a == 0) {
			stack.pop();
		}
		else {
			stack.push(a);
		}
	}
	int sum = 0;
	while (!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}

	cout << sum << '\n';
	
}