#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a;
	stack<int> stack;
	for (int i = 0;i < n;i++) {
		cin >> a;
		if (a == 0) {
			stack.pop();

		}
		else {
			stack.push(a);
		}

	}

	int sum = 0;
	while (!stack.empty())
	{
		sum += stack.top();
		stack.pop();
	}
	cout << sum;
}