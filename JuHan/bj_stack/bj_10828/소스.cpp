#include <iostream>
using namespace std;

int stack[10000];
int last_index;
int top_data;

void push(int x) {
	stack[last_index] = x;
	last_index++;
}
int pop() {
	if (last_index != 0) {
		top_data = stack[last_index-1];
		last_index--;
		return top_data;
	}
	else if (last_index == 0) {
		return -1;
	}
}
int size() {
	return last_index;
}
int empty() {
	if (last_index == 0)return 1;
	else return 0;
}
int top() {
	if (last_index != 0) return stack[last_index-1];
	else if (last_index == 0)return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int command_cnt;
	cin >> command_cnt;

	for (int i = 0; i < command_cnt; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (command == "pop") {
			cout << pop() << '\n';
		}
		else if (command == "size") {
			cout << size() << '\n';
		}
		else if (command == "empty") {
			cout << empty() << '\n';
		}
		else if (command == "top") {
			cout << top() << '\n';
		}
	}
	return 0;
}