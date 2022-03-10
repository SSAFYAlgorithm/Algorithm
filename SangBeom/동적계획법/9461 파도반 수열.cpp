#include<iostream>

using namespace std;
long long arr[101] = { 1,1,1,2,2, };

void solve(int a)
{
	long long temp = 0;
	for (int i = 4;i < a;i++)
	{
		temp = 0;
		temp = arr[i] + arr[i - 4];
		arr[i + 1] = temp;
	}

}

int main()
{
	int test;
	cin >> test;
	for (int t = 0;t < test;t++)
	{
		int a;
		cin >> a;
		solve(a);
		cout << arr[a - 1] << "\n";

	}
}