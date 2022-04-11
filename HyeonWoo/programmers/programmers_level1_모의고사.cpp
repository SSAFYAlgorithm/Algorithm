#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string arr[3];
int cnt[3];
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for (int i = 0; i < 2000; i++) {
        arr[0] += "12345";
    }
    for (int i = 0; i < 1250; i++) {
        arr[1] += "21232425";
    }
    for (int i = 0; i < 1000; i++) {
        arr[2] += "3311224455";
    }

    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if ((int)(arr[j][i] - '0') == answers[i]) {
                cnt[j]++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (cnt[i] > max) {
            max = cnt[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (cnt[i] == max) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
    vector<int> answers = {1,3,2,4,2};
    vector<int>ans = solution(answers);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}