#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) {
			return true;
		}
		else if (abs(a) == abs(b)) {
			if (a > b) {
				return true;
			}
			else {
				return false;
			}
		}
		else
			return false;
		
	}
};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	priority_queue<int, vector<int>, cmp> q;

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			if (q.size() == 0) {
				cout << '0' << '\n';
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(a);
		}
	}
}
