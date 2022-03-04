#include <iostream>
#include <queue>

using namespace std;

int sum[100001];

int main() {
	priority_queue<int, vector<int>, greater<int>> card;
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		card.push(temp);
	}

	if (card.size() == 1) {
		cout << 0;
		return 0;
	}

	while (1) {
		int x = card.top();
		card.pop();
		int y = card.top();
		card.pop();

		ans += x + y;
		card.push(x + y);

		if (card.size() == 1)
			break;
	}

	cout << ans;
	

	return 0;
}