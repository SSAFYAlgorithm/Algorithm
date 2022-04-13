#include <string>
#include <vector>
#include <cmath>
using namespace std;

int Count(int n) {
    int cnt = 0;
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0) cnt++;
    }
    cnt *= 2;
    if ((int)sqrt(n) * (int)sqrt(n) == n) {
        cnt++;
    }
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        int cnt = Count(i);
        if (cnt % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}

int main() {
    Count(17);
    solution(13, 17);
    return 0;
}