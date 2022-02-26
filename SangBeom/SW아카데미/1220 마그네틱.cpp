#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int arr[101][101];
int n;
int deadlock(int line)
{
	int sum = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i][line] == 1) {
			for (int j = i + 1;j < n;j++) {
				if (arr[j][line] == 1) {
					break;
				}
				if (arr[j][line] == 2) {
					sum += 1;
					break;
				}
			}
		}
	}
	return sum;
}

int main()
{
	for (int test = 1;test <= 10;test++) {

		cin >> n;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cin >> arr[i][j];
			}
		}
		//1 N 2 S
		int dead = 0;
		for (int i = 0;i < n;i++) {
			dead += deadlock(i);
		}

		cout << "#" << test << " " << dead << endl;

	}

}
