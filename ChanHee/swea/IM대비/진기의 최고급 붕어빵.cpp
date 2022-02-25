#include<iostream>
#include<queue>
#include<vector>
#include <string>
using namespace std;


int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++) {
		int n, m, k;
		cin >> n >> m >> k;
		int time[11111] = { 0 };
		for (int j = 0; j < n; j++) {
			int index;
			cin >> index;
			time[index] += 1;
		}
		int left = 0; // 남은 붕어빵 수
		int t = 0;
		int flag = 1;
		for (int j = 0; j < 11111; j++) {
			if (t == m) {
				left += k; // m초마다 k개의 붕어빵 생성
				t = 1;
			}
			else {
				t++;
			}
			
			if (time[j] >= 1) {
				left -= time[j];
				if (left < 0) {
					flag = 0;
					break;
				}
			}
			

		}
		if (flag) {
			cout << '#' << i << " Possible" << endl;
		}
		else {
			cout << '#' << i << " Impossible" << endl;
		}
	}
}