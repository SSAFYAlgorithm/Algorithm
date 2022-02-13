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
	priority_queue<int, vector<int>, less<int>>minus_q;//top�� �ִ� = ���� �ּ�
	priority_queue<int, vector<int>, greater<int>>plus_q;//top�� �ּڰ� = ���� �ּ�
	for (i = 0; i < time; i++) {
		cin >> x;
		if (x == 0) {
			// �� ť ��� ���������
			if (minus_q.empty() && plus_q.empty()) cout << 0 << '\n';
			else {
				// minus_q�� ����ְ�, plus_q�� �ִ°��
				if (minus_q.empty()) {
					cout << plus_q.top() << '\n';
					plus_q.pop();
				}
				// plus_q�� ����ְ�, minus_q�� �ִ°��
				else if (plus_q.empty()) {
					cout << minus_q.top() << '\n';
					minus_q.pop();
				}
				else {
					//��ť�߿��� ������ ���� ������ ���
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