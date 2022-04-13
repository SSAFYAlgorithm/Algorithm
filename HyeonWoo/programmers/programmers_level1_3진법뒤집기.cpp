#include <string>
#include <vector>

using namespace std;

vector<int> turn_3(int n) {
    vector <int> ans;
    //바꾸면서 동시에 뒤집기
    while (n > 0) {
        ans.push_back(n % 3);
        n /= 3;
    }
    return ans;
}

int turn_10(vector <int> arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res = res * 3 + arr[i];
    }
    return res;
}

int solution(int n) {
    int answer = 0;
    vector <int> three = turn_3(n);
    answer = turn_10(three);
    return answer;
}

int main() {


    solution(125);
    return 0;
}