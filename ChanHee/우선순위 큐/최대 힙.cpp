#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;


int main() {
	int a;
	priority_queue<int> q;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		if (b == 0) {
			if (q.empty()) cout << '0' << '\n';

			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(b);
		}
	}
	return 0;
}
