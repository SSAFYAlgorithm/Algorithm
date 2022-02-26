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

	string word = "";
	//string lcs;
	int length = 1;
	int flag;
	int max = 0;
	while (1)
	{
		for (int i = 0;i < str2.size();i++) {
			if (i + length > str2.size()) break;
			word = str2.substr(i, length);
			if (str1.find(word) != -1) {
				max = word.size();
			}
		}
		if (max < length) break;
		length++;

	}
	cout << max;
	//	while (1)		//Timeout
	//	{
	//		for (int i = 0;i < str2.size();i++) {
	//			word = "";
	//			flag = 0;
	//			for (int j = i;j < i + length;j++) {
	//				if (str2[j] == '\0') {
	//					flag = 1;
	//					break;
	//				}
	//				word += str2[j];
	//			}
	//			if (flag) break;
	//			if (str1.find(word) != -1) {
	////				lcs = word;
	//				max = word.size();
	//			}
	//		}
	//		if (max < length) break;
	//		length++;
	//	}
	//	cout << max;


}