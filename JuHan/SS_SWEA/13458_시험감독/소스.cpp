#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long exam_room_arr[1000001];
//vector <long long> exam_room_arr;

int main(void) {

	int exam_room;
	cin >> exam_room;

	// �� ������ �ο�
	/*int q = 3;
	int w = 4;
	int e = 5;*/
	
	for (int i = 0; i < exam_room; i++) {
		cin >> exam_room_arr[i];
	}

	// ������
	int b; // �Ѱ����� ���ð��� �ο�
	int c; // �ΰ����� ���ð��� �ο�

	int cnt = 0;
	//int c_cnt = 0;

	cin >> b >> c;
	
	for (int i = 0; i < exam_room; i++) {

		if (exam_room_arr[i] > 0) {
			// ������ �ο��� 1���̻� ������
			exam_room_arr[i] -= b;
			cnt++;

			if (exam_room_arr[i] > 0) {
				// �ʿ��� ���� ������
				if (exam_room_arr[i] % c == 0) {
					// ���������� ���� �����ο� == ���� �ο�
					cnt += (exam_room_arr[i] / c);
				}
				else {
					// �����ο� / ���������� ���� �����ο� = ������ ������
					cnt += (exam_room_arr[i] / c) + 1;
				}
			}
		}
		else if (exam_room_arr[i] == 0) {
			// ������ �ο��� 0���� ��

		}

	}

	cout << cnt;

	return 0;
}