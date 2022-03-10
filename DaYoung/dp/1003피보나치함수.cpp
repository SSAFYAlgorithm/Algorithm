#include<iostream>
using namespace std;

int t, c;
int tc[42]={1,0};

int main() {
    cin >> t;
    for (int i = 2; i <= 41; i++) {
        tc[i] = tc[i - 1] + tc[i - 2];
    }
    for (int i = 0; i < t; i++) {
        cin >> c;
        cout << tc[c] << " " << tc[c + 1] << endl;
    }
    return 0;
}