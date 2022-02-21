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
	priority_queue<int, vector<int>, less<int>>minus_q;//top이 최댓값 = 절댓값 최소
	priority_queue<int, vector<int>, greater<int>>plus_q;//top이 최솟값 = 절댓값 최소
	for (i = 0; i < time; i++) {
		cin >> x;
		if (x == 0) {
			// 두 큐 모두 비어있을때
			if (minus_q.empty() && plus_q.empty()) cout << 0 << '\n';
			else {
				// minus_q가 비어있고, plus_q가 있는경우
				if (minus_q.empty()) {
					cout << plus_q.top() << '\n';
					plus_q.pop();
				}
				// plus_q가 비어있고, minus_q가 있는경우
				else if (plus_q.empty()) {
					cout << minus_q.top() << '\n';
					minus_q.pop();
				}
				else {
					//두큐중에서 절댓값이 작은 순으로 출력
					if (-minus_q.top() > plus_q.top()) {
						cout << plus_q.top() << '\n';
						plus_q.pop();
					}
					else {
						cout << minus_q.top() << '\n';
						minus_q.pop();
					}
				}
			}
		}
		else {
			if (x >= 0) plus_q.push(x);
			else minus_q.push(x);
		}

	}
	return 0;
}