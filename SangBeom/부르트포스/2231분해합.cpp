#include<iostream>

using namespace std;

int main() {
	int arr[7] = { 0 };
	int num;
	cin >> num;
	int num2 = num;
	int cnt = 1;	//ÀÚ¸®¼ö
	while (1)
	{
		num = num / 10;
		if (num == 0) {
			break;
		}

		cnt++;
	}
	int temp;
	int sum = 0;
	int find=0;
	num = num2;
	for (int i = cnt*9;i >= 1;i--)
	{
		sum = 0;
		temp = num - i;
		for (int j = 0;j < cnt;j++) {
			arr[j] = temp % 10;
			temp /=  10;
		}
		for (int j = 0;j < cnt;j++) {
			sum += arr[j];
		}
		temp = num - i;
		if (num == (sum + temp)) {
			find = temp;
			break;
		}
	}
	cout << find;
}