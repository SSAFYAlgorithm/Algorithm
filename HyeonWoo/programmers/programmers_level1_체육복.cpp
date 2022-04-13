#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector <int> arr(n + 1, 1);
    vector <int> arr2(n + 1, 1);
    arr[0] = 0;
    arr2[0] = 0;
    for (int i = 0; i < lost.size(); i++) {
        arr[lost[i]]--;
        arr2[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        arr[reserve[i]]++;
        arr2[reserve[i]]++;
    }

    // 먼저 위로 탐색 후 아래로 탐색하는 경우
    int ans1=0;
    for (int i = 1; i <= n-1; i++) {
        if (arr[i] > 1 && arr[i + 1] == 0) {
            arr[i]--;
            arr[i + 1]++;
        }
    }

    for (int i = n; i >= 2; i--) {
        if (arr[i] > 1 && arr[i - 1] == 0) {
            arr[i]--;
            arr[i - 1]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] > 0) {
            ans1++;
        }
    }

    // 먼저 아래로 탐색 후 위로 탐색하는 경우
    int ans2 = 0;
    for (int i = n; i >= 2; i--) {
        if (arr2[i] > 1 && arr2[i - 1] == 0) {
            arr2[i]--;
            arr2[i - 1]++;
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        if (arr2[i] > 1 && arr2[i + 1] == 0) {
            arr2[i]--;
            arr2[i + 1]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr2[i] > 0) {
            ans2++;
        }
    }

    if (ans1 >= ans2) {
        answer = ans1;
    }
    else {
        answer = ans2;
    }

    return answer;
}

int main() {

    solution(5, { 3 }, { 2,3 });
    return 0;
}