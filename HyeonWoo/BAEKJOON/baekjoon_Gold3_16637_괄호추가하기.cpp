#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
string Y; // Y는 괄호가 어디 들어갈지 선택
int MaxCover;
int res;
struct WhereOper {
	int startNumIdx; //start 앞에 괄호
	int endNumIdx;   //end 뒤에 괄호
};

vector <WhereOper> CoverPlace; // 괄호위치 들어갈것



// 계산
// 음수인경우도 판별해야한다;;
int Calc(string form) {
	int Val = 0;
	string TempNum = "";
	int idx = 0;
	char LastOper;
	int totFlag = 0; // form이 전체가 숫자인경우가 존재
	int minusFlag = 0; // 마이너스 판별
	// 첫번째 숫자 찾기
	for (int i = 0; i < form.size(); i++) {
		if (i == 0 && form[i] == '-') {
			minusFlag = 1;
			continue;
		}
		if (form[i] < '0' || form[i]>'9') { // 숫자아닌거찾으면 break;
			LastOper = form[i];
			idx = i+1;
			totFlag = 1;
			break;
		}
		TempNum+=form[i];
	}
	if (minusFlag) {
		Val = stoi(TempNum) * -1;
	}
	else {
		Val = stoi(TempNum);
	}
	if (totFlag) {
		while (1) {
			TempNum = "";
			int Flag = 0; // Flag가 1이면 문자찾아서 안끝남 for문을 다돌아도 Flag가 0이면 while문 종료
			int TempMinusFlag = 0;
			for (int i = idx; i < form.size(); i++) {
				if (i == idx && form[i] == '-') {
					TempMinusFlag = 1;
					continue;
				}
				if (form[i] < '0' || form[i]>'9') { // 숫자아닌거찾으면 break;
					Flag = 1;
					// 계산
					int NextVal; 
					if (TempMinusFlag) {
						NextVal = stoi(TempNum) * -1;
					}
					else {
						NextVal = stoi(TempNum);
					}
					if (LastOper == '+') {
						Val += NextVal;
					}
					else if (LastOper == '-') {
						Val -= NextVal;
					}
					else if (LastOper == '*') {
						Val *= NextVal;
					}
					LastOper = form[i];
					idx = i + 1;
					break;
				}
				TempNum += form[i];
			}
			if (!Flag) {	
				int NextVal;
				if (TempMinusFlag) {
					NextVal = stoi(TempNum) * -1;
				}
				else {
					NextVal = stoi(TempNum);
				}
				if (LastOper == '+') {
					Val += NextVal;
				}
				else if (LastOper == '-') {
					Val -= NextVal;
				}
				else if (LastOper == '*') {
					Val *= NextVal;
				}
				break;
			}
		}
	}

	return Val;
}

// 괄호미리 계산해서 string 재배열
string Arrange() {
	string tempY = "";
	int lastENI = -1;
	for (int i = 0; i < CoverPlace.size(); i++) {
		int SNI = CoverPlace[i].startNumIdx;
		int ENI = CoverPlace[i].endNumIdx;
		// 괄호안에 string 만들어서 Calc로 보내서 계산
		string YInCover = Y.substr(SNI, ENI - SNI + 1);
		int CoverNum = Calc(YInCover);
		string CoverNumStr = to_string(CoverNum);
		// lastENI+1 ~ SNI-1까지 tempY에 담고 현재 값 담고
		string LastStr = Y.substr(lastENI + 1, (SNI - 1 - lastENI));
		tempY.append(LastStr);
		tempY.append(CoverNumStr);
		lastENI = ENI;
	}
	// 마지막부터 끝까지 붙히기
	string FinalStr = Y.substr(lastENI + 1, (Y.size() - 1 - lastENI));
	tempY.append(FinalStr);
	return tempY;
}


// 이전 괄호의 끝보다는 현재 괄호의 시작이 뒤에있어야한다.
void dfs(int level, int MaximumCover, int lastEndNumIdx) {
	if (level == MaximumCover) {
		// 괄호위치먼저 계산해서 string 다시 만들자
		string tempY = Arrange();
		int TempVAL = Calc(tempY);
		if (TempVAL > res) {
			res = TempVAL;
		}
		return;
	}

	for (int SNI = lastEndNumIdx + 2; SNI < Y.size()-1; SNI+=2) {
		int ENI = SNI + 2;
		CoverPlace.push_back({ SNI,ENI });
		dfs(level + 1, MaximumCover, ENI);
		CoverPlace.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	cin >> Y;


	MaxCover = (N + 1) / 4;
	res = Calc(Y);

	// MAXCover : 괄호가 최대 몇개 있을 수 있는지
	// 괄호가 1일때 괄호 최대길이 = N
	for (int CoverCnt = 1; CoverCnt <= MaxCover; CoverCnt++) {
		dfs(0, CoverCnt, -2);
	}

	cout << res;

	return 0;
}