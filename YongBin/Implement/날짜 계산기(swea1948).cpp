#include <iostream>

using namespace std;

int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int diffMonth = c - a;
		int result = 1;

		if (diffMonth == 0) {
			result += d - b;
		}
		else if(diffMonth == 1) {
			result += (day[a - 1] - b) + d;
		}
		else {
			for (int j = a + 1; j <= c - 1; j++) {
				result += day[j];
			}
			result += (day[a] - b) + d;
		}
		cout << "#" << i + 1 << " "<< result << "\n";
	}
	return 0;
}