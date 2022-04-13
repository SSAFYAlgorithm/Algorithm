#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    int y;
    int x;
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int idx = 0;
    Node left = { 0,0 };
    Node right = { 0,2 };
    while (idx < numbers.size()) {
        int num = numbers[idx];
        if (num == 1 || num == 4 || num == 7) {
            if (num == 1) {
                left = { 3,0 };
            }
            else if (num == 4) {
                left = { 2,0 };
            }
            else {
                left = { 1,0 };
            }
            answer += "L";
        }
        else if (num == 3 || num == 6 || num == 9) {
            if (num == 3) {
                right = { 3,2 };
            }
            else if (num == 6) {
                right = { 2,2 };
            }
            else {
                right = { 1,2 };
            }
            answer += "R";
        }
        else {
            float leftlen = 0;
            float rightlen = 0;
            if (num == 2) {
                leftlen = abs(left.y - 3) + abs(left.x - 1);
                rightlen = abs(right.y - 3) + abs(right.x - 1);
                if (leftlen > rightlen) {
                    right = { 3,1 };
                    answer += "R";
                }
                else if (leftlen < rightlen) {
                    left = { 3,1 };
                    answer += "L";
                }
                else {
                    if (hand == "right") {
                        right = { 3,1 };
                        answer += "R";
                    }
                    else {
                        left = { 3,1 };
                        answer += "L";
                    }
                }
            }
            else if (num == 5) {
                leftlen = abs(left.y - 2) + abs(left.x - 1);
                rightlen = abs(right.y - 2) + abs(right.x - 1);
                if (leftlen > rightlen) {
                    right = { 2,1 };
                    answer += "R";
                }
                else if (leftlen < rightlen) {
                    left = { 2,1 };
                    answer += "L";
                }
                else {
                    if (hand == "right") {
                        right = { 2,1 };
                        answer += "R";
                    }
                    else {
                        left = { 2,1 };
                        answer += "L";
                    }
                }
            }
            if (num == 8) {
                leftlen = abs(left.y - 1) + abs(left.x - 1);
                rightlen = abs(right.y - 1) + abs(right.x - 1);
                if (leftlen > rightlen) {
                    right = { 1,1 };
                    answer += "R";
                }
                else if (leftlen < rightlen) {
                    left = { 1,1 };
                    answer += "L";
                }
                else {
                    if (hand == "right") {
                        right = { 1,1 };
                        answer += "R";
                    }
                    else {
                        left = { 1,1 };
                        answer += "L";
                    }
                }
            }
            if (num == 0) {
                leftlen = abs(left.y - 0) + abs(left.x - 1);
                rightlen = abs(right.y - 0) + abs(right.x - 1);
                if (leftlen > rightlen) {
                    right = { 0,1 };
                    answer += "R";
                }
                else if (leftlen < rightlen) {
                    left = { 0,1 };
                    answer += "L";
                }
                else {
                    if (hand == "right") {
                        right = { 0,1 };
                        answer += "R";
                    }
                    else {
                        left = { 0,1 };
                        answer += "L";
                    }
                }
            }
        }
        idx++;
    }
    return answer;
}