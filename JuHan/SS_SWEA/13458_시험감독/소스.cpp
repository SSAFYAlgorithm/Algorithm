#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long exam_room_arr[1000001];
//vector <long long> exam_room_arr;

int main(void) {

	int exam_room;
	cin >> exam_room;

	// 각 시험장 인원
	/*int q = 3;
	int w = 4;
	int e = 5;*/
	
	for (int i = 0; i < exam_room; i++) {
		cin >> exam_room_arr[i];
	}

	// 감독관
	int b; // 총감독관 감시가능 인원
	int c; // 부감독관 감시가능 인원

	int cnt = 0;
	//int c_cnt = 0;

	cin >> b >> c;
	
	for (int i = 0; i < exam_room; i++) {

		if (exam_room_arr[i] > 0) {
			// 시험장 인원이 1명이상 있을때
			exam_room_arr[i] -= b;
			cnt++;

			if (exam_room_arr[i] > 0) {
				// 필요한 보조 감독수
				if (exam_room_arr[i] % c == 0) {
					// 보조감독관 감시 가능인원 == 남은 인원
					cnt += (exam_room_arr[i] / c);
				}
				else {
					// 남은인원 / 보조감독관 감시 가능인원 = 나머지 있을때
					cnt += (exam_room_arr[i] / c) + 1;
				}
			}
		}
		else if (exam_room_arr[i] == 0) {
			// 시험장 인원이 0명일 때

		}

	}

	cout << cnt;

	return 0;
}