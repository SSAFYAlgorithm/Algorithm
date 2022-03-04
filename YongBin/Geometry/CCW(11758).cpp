#include <iostream>

using namespace std;

/*
* 
x1 x2 x3 x1

y1 y2 y3 y1

*/

void ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
	if (temp > 0)
		cout << 1;
	else if (temp < 0)
		cout << -1;
	else
		cout << 0;
	return;
}

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	ccw(x1, y1, x2, y2, x3, y3);
	return 0;
}