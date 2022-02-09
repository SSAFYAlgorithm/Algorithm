#include<iostream>
#include <stack>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a;
	vector<int> vect;
	stack<int>stk;
	stack<char>answer;
	for (int i = 0;i < n;i++) {
		cin >> a;
		vect.push_back(a);//4 3 6 8 7 5 2 1 
	}
	int i = n - 1;
	int flag = 1;
	int max = n + 1;
	while (1) //stk.empty and i<=-1   //32145
	{
		if (stk.empty() && i == -1) break;
		if (stk.empty()) {
			answer.push('-');
			stk.push(vect[i]);
			i--;
		}
		if (i == -1) {
			answer.push('+');
			stk.pop();

		}
		else if (vect[i] > stk.top()) {
			answer.push('-');
			stk.push(vect[i]);
			i--;
		}
		else {
			if (max - 1 == stk.top()) {
				max = stk.top();
				answer.push('+');
				stk.pop();
			}
			else {
				flag = 0;
				break;
			}
		}
	}
	if (!flag) {
		cout << "NO";
	}
	else {
		while (!answer.empty()) {
			cout << answer.top() << "\n";
			answer.pop();
		}
	}

}