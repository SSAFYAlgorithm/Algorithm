#include<iostream>
#include<queue>
#include<vector>
#include <string>
using namespace std;


int main()
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int smon, sday, emon, eday;
		int ans = 0;
		cin >> smon >> sday >> emon >> eday;
		for (smon; smon <= emon; smon++) {
			if (smon == emon) {
				ans += eday - sday + 1;
			}
			else {
				if (smon == 1 || smon == 3 || smon == 5 || smon == 7 || smon == 8 || smon == 10 || smon == 12) {
					ans += 31 - sday + 1;
					sday = 1;
				}
				else if (smon == 4 || smon == 6 || smon == 9 || smon == 11) {
					ans += 30 - sday + 1;
					sday = 1;
				}
				else {
					ans += 28 - sday + 1;
					sday = 1;
				}
			}
		}
		cout << '#' << i + 1 << ' ' << ans << endl;
	}
}