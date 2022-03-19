#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//ifstream ls("input.txt");
	for (int t = 1; t <= 10; t++) {
		int n;
		int arr[100][100] = { 0 };
		vector<int> result;
		//ls >> n;
		cin >> n;
		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				//ls >> arr[i][j];
				cin >> arr[i][j];
				sum += arr[i][j];
			}
			result.push_back(sum);
		}

		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[j][i];
			}
			result.push_back(sum);
		}

		int sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += arr[i][i];
		}
		result.push_back(sum);

		sort(result.begin(), result.end());
		cout << "#" << t << " " << result[result.size()-1] << "\n";
	}
	return 0;
}
