#include<iostream>

using namespace std;
long long arr[1000001] = { 0, 1,2, };

void fibo(int a)
{
	long long temp;
	for (int i = 3;i < a + 1;i++)
	{
		temp = 0;
		temp = arr[i - 1] + arr[i - 2];
		arr[i] = temp % 15746;
	}

}

int main()
{
	int a;
	cin >> a;
	fibo(a);
	cout << arr[a];
}