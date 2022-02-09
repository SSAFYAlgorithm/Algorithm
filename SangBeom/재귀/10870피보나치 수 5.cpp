#include<iostream>

using namespace std;

int fibo(int n)
{
	if (n > 2) {

		return fibo(n - 1) + fibo(n - 2);
	}
	if (n == 2) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}

}


int main()
{
	int a;
	cin >> a;

	int num;
	num = fibo(a);
	cout << num;
}
