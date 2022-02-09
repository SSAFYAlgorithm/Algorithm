#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int a;
	cin >> a;
	vector<pair<int,string>>word;
	string w;
	for (int i = 0;i < a;i++) {
		cin >> w;
		word.push_back(pair<int,string>(w.length(),w));
	}
	sort(word.begin(), word.end());
	
	cout << word[0].second << endl;
	
	for (int i = 1;i < a;i++) {
		if (word[i].second == word[i - 1].second)
		{
			continue;
		}
		cout << word[i].second << endl;
		
		//cout << word[i].first << " " << word[i].second << endl;
		
	}
}