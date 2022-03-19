#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		stack<int> s;
		int n;
		int temp;
		long long ans = 0;
		int now = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			s.push(temp);
		}
		while (!s.empty()) {
			if (s.top() >= now) {
				now = s.top();
				s.pop();
				if (s.empty())
					break;
			}
			else {
				ans += now - s.top();
				s.pop();
			}
		}
		cout << "#" << i + 1 << " " << ans << "\n";
	}
	return 0;
}