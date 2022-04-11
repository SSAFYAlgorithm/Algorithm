#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> stair = { 10,20,15,25,10,20 };
vector<int> path;

int main() {
	cin >> n;
	int s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		stair.push_back(s);
	}

	path.push_back(stair[0]);
	path.push_back(stair[0] + stair[1]);
	path.push_back(max(stair[0] + stair[2], stair[1] + stair[2]));

	for (int i = 3; i < 6; i++) {
		path.push_back(max(stair[i] + path[i - 2], stair[i] + stair[i - 1] + path[i - 3]));
	}

	cout << path[n-1];
	return 0;
}