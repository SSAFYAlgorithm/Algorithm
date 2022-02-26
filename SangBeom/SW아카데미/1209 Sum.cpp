#include<iostream>
#include<vector>
#include<string>
using namespace std;
int arr[101][101];

int garo(int y)
{
	int sum = 0;
	for (int i = 0;i <= 100;i++) {
		sum += arr[y][i];
	}
	return sum;
}
int sero(int x)
{
	int sum = 0;
	for (int i = 0;i <= 100;i++) {
		sum += arr[i][x];
	}
	return sum;
}

int main()
{
	for (int test = 1;test <= 10;test++) {
		int dummy;
		cin >> dummy;
		for (int i = 0;i < 100;i++) {
			for (int j = 0;j < 100;j++) {
				cin >> arr[i][j];
			}
		}
		int max = -1;
		for (int i = 0;i < 100;i++) {
			int g = garo(i);
			if (g > max) {
				max = g;
			}
			int s = sero(i);
			if (s > max) {
				max = s;
			}
		}
		int degak1 = 0;
		for (int i = 0;i < 100;i++) {
			degak1 += arr[i][i];
		}
		if (max < degak1) {
			max = degak1;
		}
		int degak2 = 0;
		for (int i = 0;i < 100;i++) {
			degak2 += arr[i][99 - i];
		}
		if (degak2 > max) {
			max = degak2;
		}
		cout << "#" << test << " " << max << endl;

	}

}
