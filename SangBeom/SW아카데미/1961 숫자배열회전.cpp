#include<iostream>
#include<vector>
#include<string>
using namespace std;

int arr[8][8];
int temp[8][8];
int n;

void rotate(int y, int x)
{
	temp[x][n - 1 - y] = arr[y][x];
}


int main()
{
	int t;
	cin >> t;
	for (int test = 0;test < t;test++) {
		cin >> n;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cin >> arr[i][j];
			}
		}
		string str[8][3] = { "" };
		for (int r = 0;r < 3;r++) {

			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					rotate(i, j);
				}
			}
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					str[i][r] += (char)(temp[i][j] + '0');
					arr[i][j] = temp[i][j];
				}
			}
		}
		cout << "#" << test + 1 << " \n";
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < 3;j++) {
				cout << str[i][j] << " ";
			}
			cout << endl;
		}

	}
}
