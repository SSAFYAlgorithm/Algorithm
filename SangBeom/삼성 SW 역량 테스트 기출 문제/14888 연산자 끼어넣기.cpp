#include <iostream>
#include <vector>


using namespace std;
int N;
int vect[12];
int gihoVisted[4];
int maxCalc = -1000000001;
int minCalc = 1000000001;
void dfsGiho(int level, int res)
{
	if (level == N) {
		int now = res;
		if (maxCalc < now) {
			maxCalc = now;
		}
		if (minCalc > now) {
			minCalc = now;
		}
		return;
	}
	for (int i = 0;i < 4;i++) {
		if (gihoVisted[i] == 0)continue;
		gihoVisted[i]--;
		if (i == 0) {
			dfsGiho(level + 1, res + vect[level]);
		}
		else if (i == 1) {
			dfsGiho(level + 1, res - vect[level]);
		}
		else if (i == 2) {
			dfsGiho(level + 1, res * vect[level]);
		}
		else if (i == 3) {
			dfsGiho(level + 1, res / vect[level]);
		}
		gihoVisted[i]++;
	}
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> vect[i];
	}
	for (int i = 0;i < 4;i++) {
		cin >> gihoVisted[i];
	}
	dfsGiho(1, vect[0]);
	cout << maxCalc << '\n';
	cout << minCalc;
	return 0;

}