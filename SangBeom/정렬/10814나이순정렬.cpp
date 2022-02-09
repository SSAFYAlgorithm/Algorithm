#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;

bool compareAge(pair<int, string> vect1, pair<int, string> vect2)
{
	return vect1.first < vect2.first;
}

int main()
{
	int a;
	cin >> a;
	int age;
	string name;
	vector < pair<int, string>> vect;
	
	for (int i = 0;i < a;i++) {
		cin >> age >> name;
		vect.push_back(pair<int, string>(age, name));
	
	}
	stable_sort(vect.begin(), vect.end(), compareAge);
	for (int i = 0;i < a;i++) {
		cout << vect[i].first << " " << vect[i].second << '\n';
	}
	
}




/*
static bool ageName(tuple<int, int, string>& vect1, tuple<int, int, string>& vect2)
{
	return get<0>(vect1) < get<0>(vect2);
}




int main()
{
	int a;
	cin >> a;
	int age;
	string name;
	vector < tuple<int, int, string>> vect;
	vector<pair<int, int>>ageIndex;
	for (int i = 0;i < a;i++) {
		cin >> age >> name;
		vect.push_back(tuple<int, int, string>(age, i, name));
		ageIndex.push_back(pair<int, int>(age, i));
	}

	//처리
	sort(ageIndex.begin(), ageIndex.end());
	//cout << get<0>(vect[0]);
	vector<string>nameS;
	string nn;
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < a;j++) {
			if (ageIndex[i].first == get<0>(vect[j]) && ageIndex[i].second == get<1>(vect[j])) {
				nn = get<2>(vect[j]);
				nameS.push_back(nn);

			}
		}
	}

	//출력

	for (int i = 0;i < a;i++) {
		cout << get<0>(ageIndex[i]) << " " << nameS[i] << endl;
	}


}
*/