#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int time;
	cin >> time;
	int i, j, k, x;
	priority_queue<int, vector<int>, greater<int>>q;
	//int* sub_q = new int[time];
	vector<int> sub_q(time);
	int offset = 0;
	for (i = 0; i < time; i++) {
		cin >> x;

		sub_q[offset] = x;
		offset++;
		for (j = 0; j < offset; j++) {
			q.push(sub_q[j]);
		}

		// 큐 사이즈 1
		int size = q.size();
		if (size == 1) {
			cout << q.top() << '\n';
			q.pop();
		}
		else if (size == 2) {
			cout << q.top() << '\n';
			q.pop();
			q.pop();
		}
		else {
			// 큐 사이즈 짝수
			if (size % 2 == 0) {
				// 중간값의 위치가 최상위로 이동할때까지 pop실행
				int repeat = (size / 2) - 1;
				for (k = 0; k < repeat; k++) {
					q.pop();
				}
				cout << q.top() << '\n';
			}
			// 큐 사이즈 홀수
			else if (size % 2 == 1) {
				// 중간값의 위치가 최상위로 이동할때까지 pop실행
				int repeat = size / 2;
				for (k = 0; k < repeat; k++) {
					q.pop();
				}
				cout << q.top() << '\n';
			}

			// 큐 남은 데이터 삭제
			int garbage_size = q.size();
			for (int j = 0; j < garbage_size; j++) {
				q.pop();
			}
		}

	}
	return 0;
}