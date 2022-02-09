#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//입력
	int a;
	cin >> a;
	
	vector<pair<int, int>> vect;
	int n;

	for (int i = 0;i < a;i++) {
		cin >> n;
		vect.push_back(pair<int,int>(n, i));
	}
	
	//처리
	
	sort(vect.begin(), vect.end());
	
	int cnt=0;
	vector<pair<int,int>>vectSort;
	vectSort.push_back(pair<int, int>(vect[0].second, cnt));
	for (int i = 1;i < vect.size();i++) {
		
		if (vect[i].first == vect[i - 1].first) {
			vectSort.push_back(pair<int,int>(vect[i].second, cnt));
		}
		else {
			vectSort.push_back(pair<int, int>(vect[i].second, ++cnt));
		}
	}
	sort(vectSort.begin(), vectSort.end());
	for (int i = 0;i < a;i++) {
		cout << vectSort[i].second << " ";
	}

}