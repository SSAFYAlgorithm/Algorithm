#include<iostream>
#include<string>
#include<stack>
//#include<fstream>
using namespace std;


/*이제까지 실행해본 반례들
	1-1  답: 0
	1+2-3+4+5 답: -9
	10-10+10-10+10  답: -30
	50-60+60+70+70-50 답: -260
	1+2+3+7+8 답: 21
	00000-1+00000-00005 답: -6
	*/
stack<int>stk;
int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	str = '+' + str;
	int i = str.length() - 1;
	int sum = 0;
	stk.push(0);
	int flag = 0;
	while (i + 1)
	{
		if (str[i] == '+' || str[i] == '-') {
			int num = stoi(str.substr(i + 1));

			if (str[i] == '+') {
				if (flag) {
					stk.push(num);
					flag = 0;
				}
				else {
					int temp = stk.top() + num;
					stk.pop();
					stk.push(temp);
				}
			}
			if (str[i] == '-') {
				stk.push(num);
				flag = 1;
			}
			str = str.substr(0, i);
		}
		i--;
	}
	sum = stk.top();
	stk.pop();
	while (!stk.empty()) {
		sum -= stk.top();
		stk.pop();
	}
	cout << sum;

}