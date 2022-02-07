#include <iostream>
using namespace std;

int main() {
	int num, card, ans; 
	int sum = 0;
	int min = 300001;
	int arr[100] = {0};

	cin >> num >> card;
	
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < num - 2; i++)
		for (int j = i + 1; j < num - 1; j++)
			for (int k = j + 1; k < num; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (card - sum >= 0 && card - sum < min) {
					min = card - sum;
					ans = sum;
				}
			}
	cout << ans;
}
