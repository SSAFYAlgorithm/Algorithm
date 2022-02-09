#include<iostream>
#include<stack>
using namespace std;

int main() {
	int k;
	stack<int>s;
	int sum = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if (a == 0) s.pop();
		else s.push(a);
	}
	int ss = s.size();
	for (int i = 0; i <ss; i++) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}