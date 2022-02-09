#include<iostream>
#include<stack>
using namespace std;

int n;
int arr[1000001];
int ans[1000001];
stack<int> s;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ans[n] = -1;
	s.push(arr[n]);
	for (int i = n-1; i >= 1; i--) {
		if (s.empty()) {
			ans[n] = -1;
			s.push(arr[i]);
		}
		else if (arr[i] < s.top()) {
			ans[i] = s.top();
			s.push(arr[i]);
		}
		else {
			while (1) {
				if (s.empty()) {
					ans[i] = -1;
					s.push(arr[i]);
					break;
				}
				else if (arr[i] < s.top()) {
					ans[i] = s.top();
					s.push(arr[i]);
					break;
				}
				else s.pop();
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}