#include <iostream>
#include <stack>
//#include <fstream>

using namespace std;

int main() {
	//ifstream is("input.txt");
	for (int t = 1; t <= 10; t++) {
		int n;
		int ans = 0;
		cin >> n;
		//is >> n;
		int arr[100][100] = { 0 };

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				//is >> arr[i][j];
			}
		}

		for (int i = 0; i < 100; i++) {
			stack<int> s;
			for (int j = 0; j < 100; j++) {
				if (arr[j][i] == 1)
					s.push(1);
				else if (!s.empty() && arr[j][i] == 2 && s.top() == 1) {
					ans++;
					s.push(2);
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}