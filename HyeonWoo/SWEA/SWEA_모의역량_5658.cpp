#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
typedef unsigned long long ull;
using namespace std;

int N, K;
string arr;
vector <string> vect;
ull ans;
void init() {
    N = 0; K = 0; arr = "";
    vect = vector <string>();
    ans = 0;
}

void input() {
    cin >> N >> K >> arr;
}

int Check(string str) {
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] == str) {
            return 1;
        }
    }
    return 0;
}

void Right() {
    char temp = arr.back();
    for (int i = arr.size()-1; i >= 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

bool comp(string a, string b) {
    return a > b;
}

ull TEN(string str) {
    ull res = 0;
    for (int i = 0; i < str.size(); i++) {
        int num = 0;
        if (str[i] == 'A') {
            num = 10;
        }
        else if (str[i] == 'B') {
            num = 11;
        }
        else if (str[i] == 'C') {
            num = 12;
        }
        else if (str[i] == 'D') {
            num = 13;
        }
        else if (str[i] == 'E') {
            num = 14;
        }
        else if (str[i] == 'F') {
            num = 15;
        }
        else if (str[i]>='0' && str[i]<='9') {
            num = str[i] - '0';
        }

        res = res * 16 + num;
    }
    return res;
}

void solution() {
    int cut = N / 4;
    for (int i = 0; i < N; i++) {
        for (int s = 0; s < arr.size(); s += cut) {
            string temp = arr.substr(s, cut);
            if (!Check(temp)) {
                vect.push_back(temp);
            }
        }
        Right();
    }
    sort(vect.begin(), vect.end(), comp);
    
    ans = TEN(vect[K-1]);


}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        input();
        solution();
        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}