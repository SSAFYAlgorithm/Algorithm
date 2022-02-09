#include<iostream>

using namespace std;
int sumZero=0;
int sumOne=0;

int arr[41];

int fibonacci(int n) {
    
    if (n == 0) {
        arr[0] = 0;
        return 0;
    }
    else if (n == 1) {
        arr[1] = 1;
        return 1;
    }
    else if (arr[n] != 0) return arr[n];
    else {
        return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int a;
    cin >> a;
    int fi;
    for (int i = 0;i < a;i++) {
        cin >> fi;
        if (fi == 0) {
            cout << 0 << " " << 1 << '\n';
        }
        else if (fi == 1) {
            cout << 1 << " " << 1 << '\n';
        }
        else {
        fibonacci(fi);
        cout << arr[fi - 1] << " " << arr[fi] << '\n';
        }
    }
    return 0;
}