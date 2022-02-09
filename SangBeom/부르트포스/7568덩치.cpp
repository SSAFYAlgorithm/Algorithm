#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<pair<int, int>>person;
	int key, weight;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> key >> weight;
		person.push_back(pair<int, int>(key, weight));
	}
	//Ã³¸®
	vector<int>score;
	int cnt = 1;
	for (int i = 0;i < n;i++) {
		cnt = 1;
		for (int j = 0;j < n;j++) {
			if (person[i].first < person[j].first && person[i].second < person[j].second) {
				cnt++;
			}
		}
		score.push_back(cnt);
	}
	for (int i = 0;i < n;i++) {
		cout << score[i] << " ";
	}

}