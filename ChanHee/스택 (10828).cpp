#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int order;
	cin >> order; //명령 수

	stack<int> stack;
	string str; // 명령문

	for (int i = 0; i < order; i++) {
		cin >> str;

		if (str == "push") {
			int a;
			cin >> a;
			stack.push(a);
		}
		else if (str == "pop") {
			if (stack.empty()) { // stack이 비어있으면 -1 출력
				cout << "-1" << '\n';
			}
			else {
				cout << stack.top() << '\n';
				stack.pop();
			}
		}
		else if (str == "size") {
			cout << stack.size() << '\n';
		}
		else if (str == "empty") {
			if (stack.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (str == "top") {
			if (stack.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << stack.top() << '\n';
			}
		}
	}
}