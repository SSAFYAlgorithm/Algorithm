#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int N;
string str;
vector<int>num;
vector<char>giho;
int res[10];
int calc()
{
	deque<int>deq;
	vector<char>giho2;
	deq.push_back(num[0]);
	for (int i = 0;i < giho.size();i++) {
		if (res[i]) {
			if (giho[i] == '+') {
				int tmp = deq.back() + num[i + 1];
				deq.pop_back();deq.push_back(tmp);
			}
			else if (giho[i] == '-') {
				int tmp = deq.back() - num[i + 1];
				deq.pop_back();deq.push_back(tmp);
			}
			else if (giho[i] == '*') {
				int tmp = deq.back() * num[i + 1];
				deq.pop_back();deq.push_back(tmp);
			}
		}
		else {
			deq.push_back(num[i + 1]);
			giho2.push_back(giho[i]);
		}
	}
	int now = deq.front();deq.pop_front();
	for (int i = 0;i < giho2.size();i++) {
		if (giho2[i] == '+') {
			now += deq.front();
		}
		else if (giho2[i] == '-') {
			now -= deq.front();
		}
		else if (giho2[i] == '*') {
			now *= deq.front();
		}
		deq.pop_front();
	}

	return now;
}
int maxValue = -21e9;
void dfs(int level)
{
	if (level == giho.size()) {
		int now = calc();
		if (maxValue < now)maxValue = now;
		return;
	}
	for (int i = 0;i < 2;i++) {
		if (level > 0) {
			if (res[level - 1] && i)continue;
		}
		res[level] = i;
		dfs(level + 1);

	}
}
void solve()
{
	dfs(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	cin >> str;
	for (int i = 0;i < str.length();i++) {
		if (str[i] <= '9' && str[i] >= '0') {
			num.push_back((int)(str[i] - '0'));
		}
		else
		{
			giho.push_back(str[i]);
		}
	}
	solve();
	cout << maxValue;
}