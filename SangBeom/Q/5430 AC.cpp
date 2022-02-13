#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
	int T;
	deque<int> deq;

	string p;
	int n;
	string arr;

	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> p;
		cin >> n;
		cin >> arr;
		string tempstr;
		int flag = 0;
		bool error = false;
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] == '[') {
				continue;
			}
			else if ('0' <= arr[j] && arr[j] <= '9') {
				tempstr = tempstr + arr[j];
			}
			else {
				if (!tempstr.empty()) {
					deq.push_back(stoi(tempstr));
					tempstr.clear();
				}
			}
		}
		for (int i = 0; i < p.size();i++) {
			if (p[i] == 'R') {
				flag++;
			}
			else {//p[i]=='D'
				if (deq.empty()) {
					error = true;
					break;
				}
				else {
					if (flag % 2) {
						deq.pop_back();
						n--;
					}
					else {
						deq.pop_front();
						n--;
					}
				}
			}

		}
		if (error) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (!deq.empty()) {

				if (flag % 2 == 1) {
					for (int j = 0; j < n - 1;j++) {
						cout << deq.back() << ",";
						deq.pop_back();
					}
					cout << deq.back();
				}
				else {
					for (int j = 0; j < n - 1;j++) {
						cout << deq.front() << ",";
						deq.pop_front();
					}
					cout << deq.front();

				}
			}
			cout << "]";
		}
		deq.clear();
	}

}

