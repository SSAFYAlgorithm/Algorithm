#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		q.pop();
		int f = q.front();
		q.pop();
		q.push(f);
	}
	cout << q.front();
	return 0;
}