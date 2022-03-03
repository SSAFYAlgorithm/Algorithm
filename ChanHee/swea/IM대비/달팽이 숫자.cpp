#include<iostream>
#include<queue>
#include<vector>
#include <string>
using namespace std;

int dir[4][2] = {
	0,1,
	1,0,
	0,-1,
	-1,0
};

int main()
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int arr[10][10] = { 0 };
		int N;
		cin >> N;
		int r, c;
		r = 0;
		c = 0;
		int index = 0;
		int num = 1;
		for (int j = 0; j < 200; j++) {
			if (r + dir[index % 4][0] < 0 || r + dir[index % 4][0] >= N || c + dir[index % 4][1] < 0 || c + dir[index % 4][1] >= N) {
				index++;
			}
			if (num == N * N) {
				arr[r][c] = num;
				break;
			}
			if (arr[r + dir[index % 4][0]][c + dir[index % 4][1]] != 0) { 
				index++;
				continue; }
			//if (arr[r][c] != 0) { 
			//	index++;
			//	continue; }

			arr[r][c] = num;
			num++;
			r += dir[index % 4][0];
			c += dir[index % 4][1];
		}
		cout << '#' << i + 1 << endl;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cout << arr[j][k] << ' ';
			}
			cout << endl;
		}
	}
}