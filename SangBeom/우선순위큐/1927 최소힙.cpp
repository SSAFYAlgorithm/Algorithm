#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//priority_queue<int> pq;
	priority_queue< int, vector<int>, greater<int> > pq;


	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		if (a > 0) {
			pq.push(a);
		}
		else {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}


}