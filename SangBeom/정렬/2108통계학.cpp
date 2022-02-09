#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	//ÀÔ·Â
	int a;
	cin >> a;
	vector<int>vect;
	int n;
	int number[8001] = { 0 };
	for (int i = 0;i < a;i++) {
		cin >> n;
		vect.push_back(n);
		number[n + 4000]++;
	}
	sort(vect.begin(), vect.end());


	//Æò±Õ
	double avg;
	int sum = 0;
	for (int i = 0;i < a;i++) {
		sum += vect[i];
	}
	avg = round((double)sum / a);
	cout << avg << endl;

	//Áß¾Ó°ª
	int mid = a / 2;
	cout << vect[mid] << endl;

	//ÃÖºó°ª
	bool not_first = false;
	int most = -1;
	int most_val;
	for (int i = 0; i < 8001; i++)
	{
		if (number[i] == 0)
			continue;
		if (number[i] == most)
		{
			if (not_first)
			{
				most_val = i - 4000;
				not_first = false;
			}
		}
		if (number[i] > most)
		{
			most = number[i];
			most_val = i - 4000;
			not_first = true;
		}
	}
	cout << most_val << '\n';
	/*
	int max = 0;
	int cnt = 0;
	int freqMin=vect[0];
	int freqMin2 = vect[1];
	for (int i = 0;i < a;i++) {
		cnt = 0;
		for (int j = i + 1;j < a;j++) {
			if (vect[i] == vect[j]) {
				cnt++;
			}
		}
		if (max < cnt) {
			max = cnt;
			freqMin = vect[i];
			freqMin2 = vect[i];
		}
		else if (max == cnt &&max!=0) {
			if (freqMin < vect[i]) {
				freqMin2 = vect[i];
			}
			
		}
	}
	if (vect[1] == '\0') cout << freqMin << '\n';
	else cout << freqMin2 << '\n';
	*/


	//¹üÀ§
	
	cout << vect.back() - vect.front();

}