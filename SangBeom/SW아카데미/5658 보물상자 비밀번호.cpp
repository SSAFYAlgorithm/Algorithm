#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include<string>
#include<algorithm>
using namespace std;

int solve()
{
    int N, K;
    cin >> N >> K;
    string str;
    cin >> str;
    int len = str.length() / 4;

    vector<string>vect;
    string password = str;
    for (int i = 0;i < len;i++) {
        while (!str.empty())
        {
            vect.push_back(str.substr(0, len));
            str = str.substr(len);
        }
        char c = password[password.length() - 1];
        password = password.substr(0, password.length() - 1);
        password = c + password;
        str = password;
    }

    //중복제거

    //16->10진수
    vector<int>pass;
    for (int i = 0;i < vect.size();i++) {
        char ch[10] = "";
        for (int j = 0;j < vect[i].length();j++) {
            ch[j] = vect[i][j];
        }
        int ten = (int)strtol(ch, NULL, 16);
        pass.push_back(ten);
    }
    sort(pass.begin(), pass.end(), greater<int>());
    unique(pass.begin(), pass.end());
    return pass[K - 1];

}

int main()
{
    int test;
    cin >> test;
    for (int t = 1;t < test + 1;t++) {
        cout << "#" << t << " " << solve() << endl;

    }
    return 0;

}
