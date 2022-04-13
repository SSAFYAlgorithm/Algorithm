#include <string>
#include <vector>

using namespace std;

int AllSuccess(vector<int> progresses) {
    for (int i = 0; i < progresses.size(); i++) {
        if (progresses[i] < 100) {
            return 0;
        }
    }
    return 1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    while (1) {
        
        if (progresses[idx] >= 100) {
            int cnt = 0;
            while (1) {
                if (idx >= progresses.size()) {
                    answer.push_back(cnt);
                    break;
                }
                if (progresses[idx] >= 100) {
                    cnt++;
                    idx++;
                }
                else {
                    answer.push_back(cnt);
                    break;
                }
            }
        }

        if (AllSuccess(progresses)) {
            break;
        }

        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
    }

    return answer;
}

int main() {

    vector<int> answer = solution({ 93,30,55 }, { 1,30,5 });
    int de = -1;
    return 0;
}