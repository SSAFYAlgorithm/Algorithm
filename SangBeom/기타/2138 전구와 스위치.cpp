#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;


int n;
int cnt1 = 0;
int cnt2 = 1;
string str;
string res;
string temp;
void solve1()//00
{
	int d[3] = { -1,0,1 };
	for (int i = 1;i < str.size();i++) {
		for (int j = 0;j < 3;j++) {
			int t = i + d[j];
			if (t >= n)continue;
			if (temp[t] == '0') temp[t] = '1';
			else temp[t] = '0';
		}
		if (res[i - 1] == temp[i - 1]) {
			for (int j = 0;j < 3;j++) {
				int t = i + d[j];
				if (t >= n)continue;
				str[t] = temp[t];
			}
			cnt1++;
		}
		else {
			for (int j = 0;j < 3;j++) {
				int t = i + d[j];
				if (t >= n)continue;
				temp[t] = str[t];
			}
		}
	}
	if (str[n - 1] != res[n - 1] || str[n - 2] != res[n - 2]) {
		cnt1 = -1;
	}
}
void solve2()//11
{
	int d[3] = { -1,0,1 };
	if (temp[0] == '0') temp[0] = '1';
	else temp[0] = '0';
	if (temp[1] == '0') temp[1] = '1';
	else temp[1] = '0';
	if (str[0] == '0') str[0] = '1';
	else str[0] = '0';
	if (str[1] == '0') str[1] = '1';
	else str[1] = '0';
	for (int i = 1;i < str.size();i++) {
		for (int j = 0;j < 3;j++) {
			int t = i + d[j];
			if (t >= n)continue;
			if (temp[t] == '0') temp[t] = '1';
			else temp[t] = '0';
		}
		if (res[i - 1] == temp[i - 1]) {
			for (int j = 0;j < 3;j++) {
				int t = i + d[j];
				if (t >= n)continue;
				str[t] = temp[t];
			}
			cnt2++;
		}
		else {
			for (int j = 0;j < 3;j++) {
				int t = i + d[j];
				if (t >= n)continue;
				temp[t] = str[t];
			}
		}
	}
	if (str[n - 1] != res[n - 1] || str[n - 2] != res[n - 2]) {
		cnt2 = -1;
	}
}
int main()
{
	cin >> n;
	cin >> str;
	cin >> res;
	temp = str;
	string rememberstr = str;
	solve1();
	str = rememberstr;
	temp = rememberstr;
	solve2();
	if (cnt1 == -1 || cnt2 == -1) {
		if (cnt1 == -1 && cnt2 == -1) {
			cout << -1;
		}
		else if (cnt1 == -1) {
			cout << cnt2;
		}
		else {
			cout << cnt1;
		}
	}
	else {
		if (cnt1 >= cnt2) {
			cout << cnt2;
		}
		else {
			cout << cnt1;
		}
	}
}