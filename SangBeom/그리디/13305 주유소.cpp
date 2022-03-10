#include <iostream>
#include <vector>

using namespace std;
/*
7

3 4 2 2 4 5

8 9 5 4 2 7 1

answer = 92

18+8+10+56
*/

int main()
{
	int n;
	cin >> n;
	vector<long long>line;
	vector<long long>node;
	for (int i = 0;i < n - 1;i++) {
		long long k;
		cin >> k;
		line.push_back(k);
	}
	for (int i = 0;i < n;i++) {
		long long k;
		cin >> k;
		node.push_back(k);
	}
	long long sumPrice = 0;
	long long prevNode = 21e9;
	for (int i = 0;i < n - 1;i++) {
		if (prevNode > node[i]) {
			prevNode = node[i];
			sumPrice = sumPrice + (node[i] * line[i]);
		}
		else {
			node[i] = prevNode;
			sumPrice = sumPrice + (line[i] * prevNode);
		}
	}
	cout << sumPrice;
}


