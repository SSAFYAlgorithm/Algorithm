#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string message;
string key;
char KeyArr[5][5];
int UsedAlphabet[200];

struct INFO {
	int y, x;
};

INFO info[200];

void makeKey() {
	int x = 0;
	int y = 0;
	int idx = 0;
	int AllCoverFlag = 0;
	while (1) {
		if (idx == key.size()) break;
		if (UsedAlphabet[key[idx]] == 0) {
			UsedAlphabet[key[idx]] = 1;
			KeyArr[y][x] = key[idx];
			info[key[idx]] = { y,x };
		}
		else {
			idx++;
			continue;
		}
		idx++;
		x++;
		if (x >= 5) {
			y++;
			x = 0;
			if (y >= 5) {
				AllCoverFlag = 1;
				break;
			}		
		}
		
	}

	if (!AllCoverFlag) {
		for (int i = 'A'; i <= 'Z'; i++) {
			if (i == 'J') continue;
			if (UsedAlphabet[i] != 0) continue;
			KeyArr[y][x] = (char)i;
			info[i] = { y,x };
			x++;
			if (x >= 5) {
				y++;
				x = 0;
			}
		}
	}
}


vector <string> arr;
void devide() {
	int idx = 0;
	int s = 0;
	while (1) {
		if (s >= message.size())break;
		string temp = message.substr(s, 2);
		if (temp[0] == temp[1]) {
			string ttemp = temp.substr(0, 1);
			arr.push_back(ttemp);
			s += 1;
			continue;
		}
		arr.push_back(temp);
		s += 2;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			if (arr[i].size() == 1) {
				arr[i].append("X");
			}
			else {
				if (arr[i][0] == arr[i][1]) {
					if (arr[i][0] == 'X') {
						arr[i][1] = 'Q';
					}
					else {
						arr[i][1] = 'X';
					}
				}
			}
		}
		else {
			if (arr[i].size() == 1) {
				if (arr[i][0] == 'X') {
					arr[i].append("Q");
				}
				else {
					arr[i].append("X");
				}
			}
			else {
				if (arr[i][0] == arr[i][1]) {
					if (arr[i][0] == 'X') {
						arr[i][1] = 'Q';
					}
					else {
						arr[i][1] = 'X';
					}
				}
			}
		}
	}
}

struct RuleInfo {
	int y0, x0, y1, x1;
};

RuleInfo rule_1(char first, char second) {
	int y0 = info[first].y;
	int x0 = info[first].x + 1;

	int y1 = info[second].y;
	int x1 = info[second].x + 1;

	if (x0 == 5) {
		x0 = 0;
	}
	if (x1 == 5) {
		x1 = 0;
	}

	return { y0,x0,y1,x1 };
}

RuleInfo rule_2(char first, char second) {
	int y0 = info[first].y+1;
	int x0 = info[first].x;

	int y1 = info[second].y+1;
	int x1 = info[second].x;

	if (y0 == 5) {
		y0 = 0;
	}
	if (y1 == 5) {
		y1 = 0;
	}

	return { y0,x0,y1,x1 };
}

RuleInfo rule_3(char first, char second) {
	int y0 = info[first].y;
	int x0 = info[second].x;

	int y1 = info[second].y;
	int x1 = info[first].x;

	return { y0,x0,y1,x1 };
}

string res;

void Change() {
	for (int i = 0; i < arr.size(); i++) {
		char first = arr[i][0];
		char second = arr[i][1];
		RuleInfo Target;
		// 1. 같은 행에 존재할 때
		if (info[first].y == info[second].y) {
			Target = rule_1(first, second);
		}
		else if (info[first].x == info[second].x) {
			Target = rule_2(first, second);
		}
		else {
			Target = rule_3(first, second);
		}
		first = KeyArr[Target.y0][Target.x0];
		second = KeyArr[Target.y1][Target.x1];
		res += first;
		res += second;
	}
}

void Security() {
	devide();
	Change();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> message >> key;
	makeKey();
	Security();
	cout << res;
	return 0;

}