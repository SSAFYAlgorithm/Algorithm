#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{


	int a;
	cin >> a;
	int x, y;
	vector<pair<int, int>> vect;
	for (int i = 0;i < a;i++) {
		cin >> x >> y;
		vect.push_back(pair<int, int>(x, y));
	}
	sort(vect.begin(), vect.end());



	//출력
	for (int i = 0;i < a;i++) {
		//cout << vect[i].first << " " << vect[i].second << endl;
		printf("%d %d\n", vect[i].first, vect[i].second);
	}
	/*
	int a;
	cin >> a;
	int x, y;
	vector<vector<int>> vect(2, vector<int>(a,0));
	for (int i = 0;i < a;i++) {
		cin >> x >> y;
		vect[0][i] = x;
		vect[1][i] = y;
	}
	
	int max = -100000;
	int min = 100000;
	int tempX,tempY;

	for (int i = 0;i < a;i++) {
		for (int j = i + 1; j < a;j++) {
			if (vect[0][i] > vect[0][j]) {
				tempX = vect[0][i];
				tempY = vect[1][i];
				vect[0][i] = vect[0][j];
				vect[1][i] = vect[1][j];
				vect[0][j] = tempX;
				vect[1][j] = tempY;
			}
		}
	}
	for (int i = 0;i < a;i++) {
		for (int j = i+1;j < a;j++) {
			if (vect[0][i] == vect[0][j]) {
				if (vect[1][i] > vect[1][j]) {
					tempY = vect[1][i];
					vect[1][i] = vect[1][j];
					vect[1][j] = tempY;
				}
			}
		}
	}
	*/
	
	/*
	int temp;
	vector<int> t;
	int tt;
	int tMax = -1;
	for (int i = 0; i < a - 1;) {
		if (vect[0][i] == vect[0][i + 1]) {
			temp = vect[0][i];
			for (int j = 0;j < a;j++) {
				if (temp == vect[0][j]) {
					t.push_back(j);
				}
			}
			for (int j = 0; j < t.size();j++) {
				if (t[j] > tMax) tMax = t[j];
			}
			//sort(vect[1][t[0]], vect[1][tMax]);
			for (int j = t[0];j < tMax;j++) {
				for (int k = j + 1; k < tMax;k++) {
					if (vect[1][j] > vect[1][k]) {
						tt = vect[1][j];
						vect[1][j] = vect[1][k];
						vect[1][k] == tt;
					}
				}
			}
			i = tMax;
			t.clear();
			vector<int>().swap(t);//메모리제거
		}
		i++;

	}
	*/
	//출력
	for (int i = 0;i < a;i++) {
		cout << vect[0][i] << " " << vect[1][i] << endl;
	}
}