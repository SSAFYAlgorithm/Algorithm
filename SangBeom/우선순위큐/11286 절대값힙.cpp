#include<iostream>
#include<queue>

using namespace std;

struct  cmp
{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			if (a != b) {
				if (a < 0) {
					return (a) > (b);
				}
				else {
					return (b) < (a);
				}
			}
		}

		return abs(a) > abs(b); //a 부모노드, b 자식노드 오름차순
	}
};


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//priority_queue<int> pq;
	//priority_queue< int, vector<int>, greater<int> > pq;
	priority_queue<int, vector<int>, cmp> pq;

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		if (a != 0) {
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