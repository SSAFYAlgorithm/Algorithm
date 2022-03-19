#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

vector<int> num;

void makeNum(deque<char> dq) {
	int temp = 0;
	int base = 1;
	for (int i = dq.size() - 1; i >= 0; i--) {
		if (dq[i] >= '0' && dq[i] <= '9')
			temp += (dq[i] - 48) * base;
		else if (dq[i] >= 'A' && dq[i] <= 'F')
			temp += (dq[i] - 55) * base;
		base *= 16;
	}
	num.push_back(temp);
	return;
}


int main() {
	int t;
	int cnt = 1;
	//ifstream is("sample_input.txt");
	//is >> t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		deque<char> dq[4];
		num.clear();
		//is >> n >> k >> s;
		cin >> n >> k >> s;
		
		int cy = n / 4;

		for (int i = 0; i < cy; i++) {
			dq[0].push_back(s[i]);
			dq[1].push_back(s[i+cy]);
			dq[2].push_back(s[i+cy*2]);
			dq[3].push_back(s[i+cy*3]);
		}

		for (int i = 0; i < cy; i++) {
			for (int j = 0; j < 4; j++) {
				makeNum(dq[j]);
			}
			if (i == cy-1)
				break;
			int a = dq[0].back(); dq[0].pop_back();
			int b = dq[1].back(); dq[1].pop_back();
			int c = dq[2].back(); dq[2].pop_back();
			int d = dq[3].back(); dq[3].pop_back();

			dq[0].push_front(d);
			dq[1].push_front(a);
			dq[2].push_front(b);
			dq[3].push_front(c);
		}
		sort(num.begin(), num.end(), greater<int>());
		num.erase(unique(num.begin(), num.end()), num.end());

		cout << "#" <<cnt++ <<" "<< num[k - 1] << "\n";
	}
	return 0;
}