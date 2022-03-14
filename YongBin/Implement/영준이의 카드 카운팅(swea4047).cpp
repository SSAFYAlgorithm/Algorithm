#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int flag = 0;
		map<char, int> m; //카드체크
		map<string, int> check; // 중복체크

		string temp; //카드 입력 받기
		cin >> temp;

		m['S'] = 13;
		m['D'] = 13;
		m['H'] = 13;
		m['C'] = 13;

		for (int j = 0; j < temp.length(); j += 3) {
			string checkString = "";
			char card = temp[j];
			//checkString = temp[j] + temp[j + 1] + temp[j + 2];
			checkString += temp[j];
			checkString += temp[j + 1];
			checkString += temp[j + 2];
			if (check.find(checkString) != check.end()) {
				flag = 1;
				break;
			}
			check[checkString] = 1;
			m[card]--;
		}

		cout << "#" << i + 1 << " ";
		if (flag == 1)
			cout << "ERROR\n";
		else
			cout << m['S'] << " " << m['D'] << " " << m['H'] << " " << m['C'] << "\n";
	}
	return 0;
}