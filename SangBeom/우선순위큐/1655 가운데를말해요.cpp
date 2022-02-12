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
	priority_queue< int, vector<int>, greater<int> > tempPQ;	//temp에서 출력
	//priority_queue<int, vector<int>, cmp> pq;

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		pq.push(a);

		int size = pq.size();
		tempPQ = pq;	//pq와 동기화
		if (size % 2) {// 사이즈 홀수
			for (int j = 0;j < size / 2;j++) {
				tempPQ.pop();
			}
		}
		else {	//사이즈 짝수
			for (int j = 0;j < (size / 2) - 1;j++) {
				tempPQ.pop();
			}
		}
		cout << tempPQ.top() << '\n';
	}



}