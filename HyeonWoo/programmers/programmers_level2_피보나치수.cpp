#include<iostream>
#include<string>
#include<vector>
typedef unsigned long long ull;
using namespace std;

// 피보나치 수

ull arr[100000];

int main() {
	int n;
	cin >> n;
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%1234567;
	}

	cout << arr[n];
	return 0;
}