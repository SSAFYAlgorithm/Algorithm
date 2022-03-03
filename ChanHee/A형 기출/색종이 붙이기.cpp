#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int map[10][10] = { 0 };


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	int sum = 0;
	int impos = 0;
	int n = 5;
	int cnt[6] = { 0 };
	while (n != 0) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int zeroflag = 0;
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if (i + k < 0 || i + k > 9 || j + l < 0 || j + l > 9) { 
							zeroflag = 1;
							continue; }
						if (map[i + k][j + l] == 0) {
							zeroflag = 1;
							continue;
						}
					}
				}
				if (!zeroflag) {
					cnt[n]++;
					for (int k = 0; k < n; k++) {
						for (int l = 0; l < n; l++) {
							map[i + k][j + l] = 0;
						}
					}
				}
				else {
					
				}
			}
		}
		n--;
	}
	
	for (int i = 0; i < 6; i++) {
		if (cnt[i] > 5) {
			impos = 1;
		}
		else {
			sum += cnt[i];
		}
	}

	if (impos) {
		cout << "-1";
	}
	else {
		cout << sum;
	}
}
