
#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
	int a;
	priority_queue<int> q;
	cin >> a;
	int i = 0;
	while(i < a) {
		int b;
		cin >> b;
		b = b * -1;
		if (b == 0) {
			if (q.empty()) cout << '0' << '\n';

			else {
				cout << q.top() * -1 << '\n';
				q.pop();
			}
		}
		else {
			q.push(b);
		}
		i++;
	}
	return 0;
}
