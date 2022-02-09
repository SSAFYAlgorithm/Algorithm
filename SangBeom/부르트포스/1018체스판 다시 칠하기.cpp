#include<iostream>
#include<vector>
#include<string>
using namespace std;


string chess[50];
char chess1[8][8] =
{
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
char chess2[8][8] =
{
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
};

int main()
{
	
	pair<int, int> p1;
	cin >> p1.first >> p1.second;  //y,x
	for (int i = 0;i < p1.first;i++) {
		cin >> chess[i];
	}
	//처리
	//chess과 chess1비교
	int cnt = 0;
	int min1 = 65;
	int min2 = 65;
	
	for (int y = 0;y <= p1.first - 8;y++) {
		for (int x = 0;x <= p1.second - 8;x++) {
			cnt = 0;
			for (int i = 0; i < 8;i++) {
				for (int j = 0; j < 8;j++) {
					if (chess[i + y][j + x] != chess1[i][j]) {
						cnt++;
					}
				}
			}
			if (min1 > cnt) {
				min1 = cnt;
			}

		}

	}
	for (int y = 0;y <= p1.first - 8;y++) {
		for (int x = 0;x <= p1.second - 8;x++) {
			cnt = 0;
			for (int i = 0; i < 8;i++) {
				for (int j = 0; j < 8;j++) {
					if (chess[i + y][j + x] != chess2[i][j]) {
						cnt++;
					}
				}
			}
			if (min2 > cnt) {
				min2 = cnt;
			}

		}

	}
	//출력
	if (min1 > min2) cout << min2;
	else cout << min1;
}