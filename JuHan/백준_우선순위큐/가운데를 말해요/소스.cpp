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

		// ť ������ 1
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
			// ť ������ ¦��
			if (size % 2 == 0) {
				// �߰����� ��ġ�� �ֻ����� �̵��Ҷ����� pop����
				int repeat = (size / 2) - 1;
				for (k = 0; k < repeat; k++) {
					q.pop();
				}
				cout << q.top() << '\n';
			}
			// ť ������ Ȧ��
			else if (size % 2 == 1) {
				// �߰����� ��ġ�� �ֻ����� �̵��Ҷ����� pop����
				int repeat = size / 2;
				for (k = 0; k < repeat; k++) {
					q.pop();
				}
				cout << q.top() << '\n';
			}

			// ť ���� ������ ����
			int garbage_size = q.size();
			for (int j = 0; j < garbage_size; j++) {
				q.pop();
			}
		}

	}
	return 0;
}