#include<iostream>
#include<vector>
#include<string>
using namespace std;





int main()
{
	int t;
	cin >> t;
	for (int test = 0;test < t;test++) {
		string str;
		cin >> str;
		//t=1-t
		vector<int>vect;
		for (int i = 0;i < str.size();i++) {
			vect.push_back((char)(str[i] - '0'));
		}
		int search = 0;
		int cnt = 0;
		while (search != vect.size())
		{
			if (vect[search] == 1) {
				int flag = 0;
				cnt++;
				for (int i = search;i < str.size();i++) {
					vect[i] = 1 - vect[i];
					if (vect[i] == 1) {
						flag = 1;
					}
				}
				if (!flag) {
					break;
				}
			}
			search++;
		}
		cout << "#" << test + 1 << " " << cnt << endl;
		vect.clear();
	}
}
