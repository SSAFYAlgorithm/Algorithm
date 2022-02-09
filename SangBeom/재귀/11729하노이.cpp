#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
void hanoi(int num, int start, int mid, int to);
vector<pair<int, int>> vect;
int main()
{
	//ют╥б
	int a;
	cin >> a;
	hanoi(a, 1, 2, 3);
	cout << cnt<<endl;
	for (int i = 0;i < cnt;i++) {
		printf("%d %d\n", vect[i].first, vect[i].second);
	}
	
	
	return 0;
}
void hanoi(int num, int start, int mid, int to)
{
	pair<int, int> temp;
	cnt++;
	if (num == 1)
	{
		temp.first = start;
		temp.second =to;
		vect.push_back(temp);
		
		return;
	}

	hanoi(num - 1, start, to, mid);
	temp.first = start;
	temp.second = to;
	vect.push_back(temp);
	//cout << start << " " << to << endl;
	hanoi(num - 1, mid, start, to);
	return;
}