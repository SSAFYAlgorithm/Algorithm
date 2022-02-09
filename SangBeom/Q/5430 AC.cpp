#include<iostream>
#include<deque>
#include<string>

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
		//배열을 숫자로
		int cnt = 0;
		int flag = 0;
		for (int i = 0; i < arr.size();i++) {
			if (arr[i] == '[' || arr[i] == ']' || arr[i] == ',') {
				continue;
			}
			else if (arr[i] >= '0' && arr[i] <= '9') {
				deq.push_back((int)(arr[i])-48);
				cnt++;
			}
		}
		if (cnt != n) {
			cout << "error\n";
			deq.clear();
		}
		else if (n == 0 || deq.empty()) {
			cout << "error\n";
			deq.clear();
		}
		else {
			
			for (int i = 0;i < p.size();i++) {
				if (p[i] == 'R') {
					flag++;
				}
				else if (p[i] == 'D') {
					if (flag % 2 == 1) {
						if (deq.empty()) {
							cout << "error\n";
							break;
						}
						deq.pop_back();
						n--;
					}
					else {
						if (deq.empty()) {
							cout << "error\n";
							break;
						}
						deq.pop_front();
						n--;
					}
				}
			}
			cout << "[";
			if (flag%2 == 1) {
				for (int j = 0; j < n-1;j++) {
					cout << deq.back() << ",";
					deq.pop_back();
				}
				cout << deq.back() << "]";
			}
			else {
				for (int j = 0; j < n - 1;j++) {
					cout << deq.front() << ",";
					deq.pop_front();
				}
				cout << deq.front() << "]";

			}
		}
	}
	
}

