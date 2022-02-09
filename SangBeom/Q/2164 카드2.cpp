#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	deque<int> q;
	for (int i = 1;i <= n;i++) {
		q.push_back(i);
	}
	int a = 0;
	while (q.size() > 1)
	{
		if (a % 2 == 0) {
			q.pop_front();
		}
		else {
			int temp = q.front();
			q.push_back(temp);
			q.pop_front();
		}
		a++;
	}
	cout << q.front();
}
