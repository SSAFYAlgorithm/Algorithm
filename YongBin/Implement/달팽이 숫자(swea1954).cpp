#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int arr[11][11] = { 0 };
        int num = 1;
        int x = 0, y = 0;
        int dir = 1;

        for (int i = 0; i < n; i++) {
            arr[y][x] = num++;
            x += dir;
        }
        x -= 1;
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                y += dir;
                arr[y][x] = num++;
            }
            dir *= -1;
            for (int j = 0; j < i; j++) {
                x += dir;
                arr[y][x] = num++;
            }
        }
        cout << "#" << i + 1 << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }

	return 0;
}