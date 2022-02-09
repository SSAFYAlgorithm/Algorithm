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
		vect.push_back(pair<int, int>(y, x));
	}
	sort(vect.begin(), vect.end());



	//Ãâ·Â
	for (int i = 0;i < a;i++) {
		//cout << vect[i].first << " " << vect[i].second << endl;
		printf("%d %d\n", vect[i].second, vect[i].first);
	}
}