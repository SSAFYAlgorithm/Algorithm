#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	char ans[200001];
	int idx = 0;
	int n;
	cin >> n;
	int push_min = 1;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (s.empty() || s.top() < k) {
			for (int i = push_min; i <= k; i++) {
				s.push(i);
				ans[idx++]='+';
			}
			if(k>=push_min) push_min = k + 1;
		}
		if (s.top() == k) {
			s.pop();
			ans[idx++] = '-';
		}
		else {
			flag = 1;
			break;
		}
	}
	if (flag) cout << "NO\n";
	else {
		for (int i = 0; i < idx;i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}