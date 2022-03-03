#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int line, goal;
	cin >> line >> goal;
	vector<int> price;
	for (int i = 0; i < line; i++) {
		int a;
		cin >> a;
		price.push_back(a);
	}
	int sum = 0;
	int num = 0;
	int index = price.size() - 1;
	while (sum != goal) {
		if (sum + price[index] > goal) {
			index--;
		}
		else {
			sum += price[index];
			num++;
		}
	}
	cout << num;
}
