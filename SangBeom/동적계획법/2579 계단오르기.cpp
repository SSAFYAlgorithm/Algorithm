#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[301] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>vect;
	for (int i = 0;i < n;i++)
	{
		int stair;
		cin >> stair;
		vect.push_back(stair);

	}
	arr[0] = vect[0];
	arr[1] = max(vect[0] + vect[1], vect[1]);
	arr[2] = max((vect[0] + vect[2]), (vect[1] + vect[2]));
	for (int i = 3;i < n;i++) {
		arr[i] = max((arr[i - 2] + vect[i]), (arr[i - 3] + vect[i - 1] + vect[i]));
	}
	cout << arr[n - 1];

	return 0;
}