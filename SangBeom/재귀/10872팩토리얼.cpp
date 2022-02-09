#include<iostream>

using namespace std;

int factorial(int n)
{
	if (n > 1) {
		return n * factorial(n - 1);
	}
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 1;
	}

}


int main()
{
	int a;
	cin >> a;

	int num;
	num=factorial(a);
	cout << num;
}
