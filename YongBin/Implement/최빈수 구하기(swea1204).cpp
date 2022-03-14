#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int t;
	//ifstream is("input.txt");
	cin >> t;
	//is >> t;
	for (int i = 0; i < t; i++) {
		int score;
		int n;
		cin >> n;
		//is >> n;
		map<int, int> m;
		for (int j = 0; j < 1000; j++) {
			cin >> score;
			//is >> score;
			if (m.find(score) != m.end()) {
				m[score]++;
			}
			else {
				m[score] = 1;
			}
		}
		vector<pair<int, int>> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(), cmp);
		cout << "#" << i + 1 << " " << vec[vec.size() - 1].first << "\n";
	}
	return 0;
}