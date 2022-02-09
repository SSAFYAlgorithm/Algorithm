#include<iostream>
#include<queue>

using namespace std;

int main()
{
	deque<int> deq;

	int n, k;
	cin >> n >> k;
	
	for (int i = 1;i <= n;i++) {
		deq.push_back(i);
	}
	int cnt = 1;
	cout << "<";
	while (deq.size()) {
		if (deq.size() == 1) {
			cout << deq.front();
			deq.pop_front();
		}
		else if (cnt % k == 0) {
			cout << deq.front() << ", ";
			deq.pop_front();
		}
		else {
			int temp = deq.front();
			deq.pop_front();
			deq.push_back(temp);
		}
	cnt++;
	}
	cout << ">";
}
