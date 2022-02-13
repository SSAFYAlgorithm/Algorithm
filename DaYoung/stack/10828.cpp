#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

char buf[6];
stack<int> s;
int n;
int x;

void doit() {
	cin >> buf;
	if (!strcmp(buf, "push")) {
		cin >> x;
		s.push(x);
	}
	else if (!strcmp(buf, "pop")) {
		if (s.empty())cout << -1 << endl;
		else {
			cout << s.top() << endl;
			s.pop();
		}
	}
	else if (!strcmp(buf, "size")) {
		cout << s.size() << endl;
	}
	else if (!strcmp(buf, "empty")) {
		cout << s.empty() << endl;
	}
	else if (!strcmp(buf, "top")) {
		if (s.empty())cout << -1 << endl;
		else {
			cout << s.top() << endl;
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		doit();
	}
	return 0;
}