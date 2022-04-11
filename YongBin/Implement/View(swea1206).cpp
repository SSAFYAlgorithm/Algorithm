#include <iostream>
//#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	//ifstream is("input.txt");
	for (int t = 1; t <= 10; t++) {
		int n;
		int arr[1010] = { 0 };
		int ans = 0;
		cin >> n;
		//is >> n;
		for (int i = 2; i < n + 2; i++) {
			cin >> arr[i];
			//is >> arr[i];
		}

		for (int i = 2; i < n + 2; i++) {
			if (arr[i - 2] < arr[i] && arr[i - 1] < arr[i] && arr[i + 1] < arr[i] && arr[i + 2] < arr[i]) {
				int high = max(max(arr[i - 2], arr[i - 1]), max(arr[i + 1], arr[i + 2]));
				ans += arr[i] - high;
			}
		}
		
		cout << "#" << t << " " << ans << "\n";

	}
	return 0;
}