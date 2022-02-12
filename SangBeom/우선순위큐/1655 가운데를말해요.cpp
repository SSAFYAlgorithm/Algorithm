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
	priority_queue< int, vector<int>, greater<int> > tempPQ;	//temp���� ���
	//priority_queue<int, vector<int>, cmp> pq;

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		pq.push(a);

		int size = pq.size();
		tempPQ = pq;	//pq�� ����ȭ
		if (size % 2) {// ������ Ȧ��
			for (int j = 0;j < size / 2;j++) {
				tempPQ.pop();
			}
		}
		else {	//������ ¦��
			for (int j = 0;j < (size / 2) - 1;j++) {
				tempPQ.pop();
			}
		}
		cout << tempPQ.top() << '\n';
	}



}