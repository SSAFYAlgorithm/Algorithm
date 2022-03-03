#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>ATM;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		ATM.push_back(num);
	}
	sort(ATM.begin(), ATM.end());
	int sum = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			sum += ATM[j];
		}
	}
	cout << sum;


}