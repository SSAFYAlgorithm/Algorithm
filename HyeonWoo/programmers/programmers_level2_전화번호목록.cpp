#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

     for (int i = 1; i < phone_book.size(); i++) {
         
        if (phone_book[i].find(phone_book[i - 1]) == 0) {
            answer = false;
            break;
        }
         

     }

    return answer;
}
int main() {

    solution({ "12345"});

    return 0;
}