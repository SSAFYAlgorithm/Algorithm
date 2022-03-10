#include <iostream>

using namespace std;

int times;
int num[100];
long long dat[101] = {
	0,1,1,1,2,2
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> times;
	int i;
	int j;
	for (j = 6; j <= 100; j++) {
		dat[j] = dat[j - 1] + dat[j - 5];
	}

	for (i = 1; i <= times; i++) {
		cin >> num[i];
		cout << dat[num[i]] << "\n";
	}



	return 0;
}