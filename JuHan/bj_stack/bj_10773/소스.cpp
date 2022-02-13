#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> stack_arr;

	int input_cnt;
	cin >> input_cnt;

	for (int i = 0; i < input_cnt; i++) {
		int input;
		cin >> input;
		if (input != 0) {
			stack_arr.push(input);
		}
		else if (input == 0) {
			stack_arr.pop();
		}
	}

	int sum = 0;
	int size = stack_arr.size();
	for (int i = 0; i < size; i++) {
		sum += stack_arr.top();
		stack_arr.pop();
	}

	cout << sum;
	return 0;
}