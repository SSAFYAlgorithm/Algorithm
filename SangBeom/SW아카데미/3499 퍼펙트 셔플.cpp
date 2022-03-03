#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int test = 0;test < t;test++) {
		int n;
		cin >> n;
		vector<string>vect;
		for (int i = 0;i < n;i++) {
			string str;
			cin >> str;
			vect.push_back(str);
		}
		int len;
		int flag = 0;
		if (n % 2) {//Ȧ
			len = n / 2 + 1;
			flag = 1;
		}
		else len = n / 2;
		int i = 0;
		cout << "#" << test + 1 << " ";
		while (1)
		{
			cout << vect[i] << " ";
			if (flag) {
				if (i >= len - 1) {
					break;
				}
			}
			cout << vect[i + len] << " ";
			i++;
			if (!flag) {
				if (i == len) {
					break;
				}
			}
		}
		cout << endl;
	}
}
