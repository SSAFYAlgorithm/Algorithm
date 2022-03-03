#include <iostream>

using namespace std;

int times;
int n;
int cnt;
int coinTypes[10];

int main() {
    cin >> times >> n;

    for (int i = 0; i < times; i++) {
        cin>>coinTypes[i];
    }
    for (int i = times-1; i >= 0; i--) {
        if (n == 0) break;
        cnt = cnt + n / coinTypes[i];
        n = n % coinTypes[i];
    }
    cout << cnt << '\n';

    return 0;
}