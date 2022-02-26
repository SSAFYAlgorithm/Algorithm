#include<iostream>
#include<vector>
#include<string>
using namespace std;

int arr[16][16];
int n, m;

int kill(int y, int x)
{
	int sum = 0;
	for (int i = y;i < y + m;i++) {
		for (int j = x;j < x + m;j++) {
			sum += arr[i][j];
		}
	}

	return sum;
}

int main()
{
	int t;
	cin >> t;
	for (int test = 0;test < t;test++) {
		cin >> n >> m;
		int max = -1;
		int now;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				now = kill(i, j);
				if (now > max) {
					max = now;
				}
				int de = -1;
			}
		}
		cout << "#" << test + 1 << " " << max << "\n";


	}
}
