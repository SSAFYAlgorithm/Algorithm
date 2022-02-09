#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int a;
	cin >> a;
	vector<int> vect;
	while (1)
	{
		vect.push_back(a % 10);
		a /= 10;
		if (a == 0) {
			break;
		}
	}
	sort(vect.begin(), vect.end());
	for (int i = vect.size()-1;i >= 0;i--) {
		cout << vect[i];
	}
}