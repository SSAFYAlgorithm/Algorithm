#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
/*
826
27 12 72 12 48 54 21 91 25 89 64 41 52 63 30 1 14 59 79 66 8 78 1 59 40 4 61 58 25 78 9 14 88 2 51 61 29 94 85 6 41 12 5 36 57 73 51 24 86 57 17 27 58 27 58 38 72 70 62 97 23 18 13 18 97 86 42 24 30 30 66 60 33 97 56 54 63 85 35 55 73 58 70 33 64 8 84 12 36 68 49 76 39 24 43 55 12 42 76 60
ans :14
*/
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int test = 1;test <= 10;test++) {

		int n;
		cin >> n;
		int dat[101] = { 0 };
		for (int i = 1;i <= 100;i++) {
			int block;
			cin >> block;
			dat[i] = block;
		}
		int min;
		int minblock;
		int max;
		int maxblock;
		for (int i = 0;i < n - 1;i++) {
			max = -1;
			min = 101;
			for (int j = 1;j <= 100;j++) {
				if (dat[j] > max) {
					max = dat[j];
					maxblock = j;
				}
				if (dat[j] < min) {
					min = dat[j];
					minblock = j;
				}
			}
			dat[maxblock]--;
			dat[minblock]++;

		}
		max = -1;
		min = 101;
		for (int i = 1;i <= 100;i++) {
			if (dat[i] > max) {
				max = dat[i];
			}
			if (dat[i] < min) {
				min = dat[i];
			}
		}

		cout << "#" << test << " ";
		cout << max - min << endl;
	}

}
