#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//ifstream is("input2.txt");
	for (int t = 1; t <= 10; t++) {
		int dump, temp;
		cin >> dump;
		//is >> dump;
		vector<int> high;

		int maxHigh = 0;
		int minHigh = 0;

		for (int i = 0; i < 100; i++) {
			cin >> temp;
			//is >> temp;
			high.push_back(temp);
		}

		sort(high.begin(), high.end());
		maxHigh = high[99];
		minHigh = high[0];

		for (int i = 0; i < dump; i++) {
			if (maxHigh - minHigh == 1) {
				break;
			}
			high[0]++;
			high[99]--;
			sort(high.begin(), high.end());
			maxHigh = high[99];
			minHigh = high[0];
		}

		cout << "#" << t << " " << maxHigh - minHigh << "\n";
	}
	return 0;
}