#include <iostream>

using namespace std;

int ans = 987654321;
int tempAns = 0;
int n;
string start, result, temp;

void change(int idx) {
	if (idx == 0) {
		for (int i = 0; i < 2; i++) {
			if (start[i] == '0')
				start[i] = '1';
			else
				start[i] = '0';
		}
		return;
	}
	else if (idx == n - 1) {
		for (int i = n - 2; i < n; i++) {
			if (start[i] == '0')
				start[i] = '1';
			else
				start[i] = '0';
		}
		return;
	}
	for (int i = idx - 1; i <= idx + 1; i++) {
		if (start[i] == '0')
			start[i] = '1';
		else
			start[i] = '0';
	}

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> start >> result;
	temp = start;

	change(0);
	tempAns++;
	for (int i = 1; i < n; i++) {
		if (start[i-1] != result[i-1]) {
			change(i);
			tempAns++;
		}
	}

	if (start == result)
		ans = tempAns;

	start = temp;
	tempAns = 0;
	for (int i = 1; i < n; i++) {
		if (start[i-1] != result[i-1]) {
			change(i);
			tempAns++;
		}
	}

	if (start == result)
		ans = min(tempAns, ans);

	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;


	return 0;
}