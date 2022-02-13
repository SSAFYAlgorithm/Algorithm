#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int time;
	cin >> time;
	int i, x;
	priority_queue<int>q;
	for (i = 0; i < time; i++) {
		cin >> x;
		// x=0�̸� �ִ밪 ����ϰ� ����
		if (x == 0) {
			// ť ���������
			if (q.empty()) cout << 0 << '\n';
			// �� ���������
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		// x!=0�̸� x����
		else q.push(x);
	}
	return 0;
}