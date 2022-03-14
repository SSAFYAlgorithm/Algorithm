#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check1(vector<vector<int>> arr) {
	for (int i = 0; i < 9; i++) {
		vector<int> temp = arr[i];
		int s = temp.size();
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		if (s != temp.size())
			return false;
	}

	for (int i = 0; i < 9; i++) {
		vector<int> temp;
		for (int j = 0; j < 9; j++) {
			temp.push_back(arr[j][i]);
		}
		int s = temp.size();
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		if (s != temp.size())
			return false;
	}

	for (int i = 0; i < 9; i++) {
		vector<int> temp;
		for (int k = (i % 3) * 3; k < (i % 3) * 3 + 3; k++) {
			for (int j = (i % 3) * 3; j < (i % 3) * 3 + 3; j++) {
				temp.push_back(arr[k][j]);
			}
		}
		int s = temp.size();
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		if (s != temp.size())
			return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<vector<int>> arr;
		for (int j = 0; j < 9; j++) {
			vector<int> temp;
			for (int k = 0; k < 9; k++) {
				int temp1;
				cin >> temp1;
				temp.push_back(temp1);
			}
			arr.push_back(temp);
		}
		if (check1(arr) == false)
			cout << "#" << i+1 << " 0\n";
		else
			cout << "#" << i+1 << " 1\n";

	}
	return 0;
}