#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int time;
	cin >> time;
	int i, x;
	priority_queue<int, vector<int>, greater<int>>q;
	for (i = 0; i < time; i++) {
		cin >> x;
		// x=0이면 최솟값 출력하고 제거
		if (x == 0) {
			// 큐 비어있으면
			if (q.empty()) cout << 0 << '\n';
			// 안 비어있으면
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		// x!=0이면 x삽입
		else q.push(x);
	}
	return 0;
}