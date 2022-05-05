#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int check(string str) {
	
	char lastch = '#';
	while (1) {
		if (str.size() == 0) return 1;
		if (str.size() == 1) {
			if (str[0] == '1' && lastch == '1') return 1;
			else return 0;
		}
		char ch = str[0];
		if (ch == '0') { // 01만 가능
			if (str[1] == '0') return 0; // 00은 안됨
			else { // 되면 앞에 두개 잘라냄
				str = str.substr(2);
				lastch = '#';
			}
		}
		else { // 처음이 1인경우
			int ni = str.find("1", 1);
			// 다음 1이 없는경우 위에서 1만있는경우는 가지치기를 해줬기 때문에
			// 사이즈는 2개 이상일경우이고, 이경우 ni가 -1이 되는 경우는 무조건 0이다.
			if (ni == string :: npos) return 0; 
			// 11 101인경우 앞에가 1이라면 이전것을 자르면 된다.
			if (ni == 1 || ni == 2) {
				if (lastch == '1') {
					str = str.substr(1);
				}
				else {
					return 0;
				}
			}
			else {
				if (ni == str.size() - 1) return 1;
				else {
					str = str.substr(ni + 1);
					lastch = '1';
				}
			}

		}
	}


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		if (check(str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
	}


	return 0;
}