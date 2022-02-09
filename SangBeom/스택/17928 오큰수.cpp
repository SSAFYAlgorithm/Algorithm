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
	int a;
	for (int i = 0;i < n;i++) {
		cin >> a;
		vect.push_back(a);  
	}
	int flag=0;
	//1¹øÂ° -1
	stk.push(-1);
	for (int i = n - 2;i >= 0;i--) {
		for (int j = i +1; j <= n-1; j++) {
			if (vect[i] < vect[j]) {
				stk.push(vect[j]);
				flag = 1;
				break;
			}
		}
		if (!flag) {
			stk.push(-1);
		}
		flag = 0;
	}
	for (int i = 0; i < n;i++) {
		cout << stk.top() << " ";
		stk.pop();
	}
}

