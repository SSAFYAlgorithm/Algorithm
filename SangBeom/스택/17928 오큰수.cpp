#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> vect;	//9 6 3 5 2 7 
	stack<int> stk;		//-1 7 5 7 7 -1
	vector<int> ans;
	int a;
	for (int i = 0;i < n;i++) {
		cin >> a;
		vect.push_back(a);
	}

	for (int i = n - 1;i >= 0;i--) {
		if (stk.empty()) {
			stk.push(vect[i]);
			ans.push_back(-1);
		}
		else {
			if (stk.top() > vect[i]) {
				ans.push_back(stk.top());
				stk.push(vect[i]);
			}
			else {
				while (1) {
					if (stk.empty()) {
						ans.push_back(-1);
						break;
					}
					if (stk.top() > vect[i]) {
						ans.push_back(stk.top());
						stk.push(vect[i]);
						break;
					}
					stk.pop();
				}
			}
		}
	}
	for (int i = ans.size() - 1;i >= 0;i--) {
		cout << ans[i] << " ";
	}
}

