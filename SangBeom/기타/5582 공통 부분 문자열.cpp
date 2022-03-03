#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;
	string str1, str2;//long short
	if (a.length() >= b.length()) {
		str1 = a;
		str2 = b;
	}
	else {
		str1 = b;
		str2 = a;
	}


	//string lcs;
	int length = 1;
	int flag = 0;
	int max = 0;
	vector<string>dp;
	for (int i = 0;i < str2.size();i++) {
		if (str1.find(str2[i]) != -1) {
			string word = "";
			word += str2[i];
			dp.push_back(word);
			word.clear();
			flag = 1;
		}
	}

	if (!flag) {
		cout << -1;
	}
	else {
		while (flag != 2) {  //dp에 가능한 문자들만 넣고 dp내의 문자들을 더해 문자열을 탐색, 찾지 못하면 해당 인덱스 삭제
			length++;
			int oversizeFlag = 0;
			for (int i = 0; i < dp.size();) {
				string word = dp[i];
				for (int j = i + 1;j < i + length;j++) {
					if (i + length > dp.size()) {
						oversizeFlag = 1;
						dp.erase(dp.end() - 1);
						break;
					}
					word += dp[j];
				}
				if (oversizeFlag) break;

				if (str1.find(word) != -1) {
					dp[i] = word;
					i++;
				}
				else {
					dp.erase(dp.begin() + i);
					if (dp.empty()) {
						flag = 2;
						break;
					}
				}
			}

		}
		cout << length;

	}
	int de = -1;





}