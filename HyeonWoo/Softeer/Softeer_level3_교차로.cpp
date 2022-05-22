#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N;

int CountArr[4]; // 방향별로 차가 몇대나 있는지
queue <int> info[4]; // 방향별로 몇번의 차가 있는지
int res[200010];
int nowTime = 0; // 초당으로 돌릴꺼
int CarNum = 0;
int flag = 0;
struct INFO {
	int time, dir; // 0:A 1:B 2:C 3:D
};

queue <INFO> input;
queue <int> TimeArr;
int isAllFlagOne(int* flagarr) {
	for (int i = 0; i < 4; i++) {
		if (flagarr[i] != 1) {
			return 0;
		}
	}
	return 1;
}

int isEmpty() {
	for (int i = 0; i < 4; i++) {
		if (CountArr[i] != 0) {
			return 0;
		}
	}
	return 1;
}

void GoCar() {
	// 모두 들어왔으면, 자기차량 오른쪽 교차로에 차량이 있는지 파악
	int flagarr[4] = { 0,0,0,0 }; // 자기 오른쪽에 차량이 있으면 1로 바뀔꺼임
	for (int i = 0; i < 4; i++) {
		if (CountArr[i] == 0) {
			flagarr[i] = 1;
			continue;
		}
		int CompareCarDir = 0;
		if (i == 0) CompareCarDir = 3;
		else CompareCarDir = i - 1;

		// 비교차량선에 차량이 있으면 continue;
		if (CountArr[CompareCarDir] > 0) {
			flagarr[i] = 1;
			continue;
		}
	}

	// 모두 flagarr이 1인지 판별 (초기화해서 전부 -1로 해줘서 따로 처리 안해도 됨)
	if (isAllFlagOne(flagarr)) {
		flag = 1;
		return;
	}
	// 차량 빠지는 처리
	for (int i = 0; i < 4; i++) {
		// 만약 차량이 없으면 해당 차량이 빠지고 break;
		if (flagarr[i] == 1) continue; // 빠질수없는 차량이라면 continue
		int ResCarNum = 0;
		CountArr[i]--; // 해당방향 차량 빠지고
		ResCarNum = info[i].front();
		info[i].pop(); // 해당차량 번호 정보 입력받고
		res[ResCarNum] = nowTime; // 결과에 차량 빠진시간 입력하고
	}
}

void solution() {
	// while문으로 시간을 1초씩 증가시키면서 수행할 예정
	while (1) {
		if (flag) break;
		// 만약 input.size == 0 이고 교차로도 비어있으면 반복문 끝
		if (isEmpty()) {
			if (input.size() == 0) {
				break;
			}
			else {
				// 교차로에 차량도 없고, 다음시간까지 많이 남았으면 nowTime 바로 갱신
				if (TimeArr.size() > 0) {
					int timeflag = 0;
					while (nowTime > TimeArr.front()) {
						if (TimeArr.size() == 0) {
							timeflag = 1;
							break;
						}
						TimeArr.pop();
					}
					if (!timeflag) {
						nowTime = TimeArr.front();
					}
				}
			}
		}

		

		if (input.size()>0 && input.front().time > nowTime) {
			// 차량이 빠질수는 있다. (교차로에 차가 있을때)
			if (!isEmpty()) {
				GoCar();
			}
			nowTime++;
			continue;
		}
		

		// 먼저 교차로에 해당 시간인 차량 모두 들어온다.
		while (1) {
			if (input.empty()) {
				break;
			}
			if (input.front().time > nowTime) {
				break;
			}
			int TempnowTime = input.front().time;
			int Tempnowdir = input.front().dir;
			input.pop();
			CountArr[Tempnowdir]++;
			info[Tempnowdir].push(CarNum);
			CarNum++;
		}

		GoCar();

		nowTime++;
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		if(dir == 'A') input.push({ time, 0 });
		else if (dir == 'B') input.push({ time, 1 });
		else if(dir == 'C') input.push({ time, 2 });
		else if(dir == 'D') input.push({ time, 3 });
		if (TimeArr.size() == 0) {
			TimeArr.push(time);
		}
		else if (TimeArr.back() < time) {
			TimeArr.push(time);
		}
	}

	memset(res, -1, sizeof(res));
	solution();
	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
	return 0;

}