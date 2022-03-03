#include<iostream>
#include<vector>
#include<string>
using namespace std;

int S[14] = { 0 };
int D[14] = { 0 };
int H[14] = { 0 };
int C[14] = { 0 };

void findS(char ten, char one)
{
	if (ten == '0') {
		S[(int)(one - '0')]++;
	}
	if (ten == '1') {
		S[(int)(one - '0') + 10]++;
	}
}
void findD(char ten, char one)
{
	if (ten == '0') {
		D[(int)(one - '0')]++;
	}
	if (ten == '1') {
		D[(int)(one - '0') + 10]++;
	}
}
void findH(char ten, char one)
{
	if (ten == '0') {
		H[(int)(one - '0')]++;
	}
	if (ten == '1') {
		H[(int)(one - '0') + 10]++;
	}
}
void findC(char ten, char one)
{
	if (ten == '0') {
		C[(int)(one - '0')]++;
	}
	if (ten == '1') {
		C[(int)(one - '0') + 10]++;
	}
}
int main()
{
	int t;
	cin >> t;
	for (int test = 0;test < t;test++) {
		string str;
		cin >> str;
		vector<string>vect;
		while (!str.empty())
		{

			vect.push_back(str.substr(0, 3));
			str = str.substr(3);
		}

		for (int i = 0;i < vect.size();i++) {
			if (vect[i][0] == 'S') {
				findS(vect[i][1], vect[i][2]);
			}
			if (vect[i][0] == 'D') {
				findD(vect[i][1], vect[i][2]);
			}
			if (vect[i][0] == 'H') {
				findH(vect[i][1], vect[i][2]);
			}
			if (vect[i][0] == 'C') {
				findC(vect[i][1], vect[i][2]);
			}
		}
		int cntS = 0;
		int cntD = 0;
		int cntH = 0;
		int cntC = 0;
		int flag = 0;
		for (int i = 1;i <= 13;i++) {
			if (S[i] >= 2 || D[i] >= 2 || H[i] >= 2 || C[i] >= 2) {
				flag = 1;
				break;
			}
			if (S[i] == 0) {
				cntS++;
			}
			if (D[i] == 0) {
				cntD++;
			}
			if (H[i] == 0) {
				cntH++;
			}
			if (C[i] == 0) {
				cntC++;
			}
		}
		if (flag) cout << "#" << test + 1 << " " << "ERROR\n";
		else cout << "#" << test + 1 << " " << cntS << " " << cntD << " " << cntH << " " << cntC << "\n";
		for (int i = 1;i <= 13;i++) {
			S[i] = 0;C[i] = 0;H[i] = 0;D[i] = 0;
		}
	}
}
