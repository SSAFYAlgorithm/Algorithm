#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int reserv[55][11]; // 0번 전 주소가 9시 / 10번 전 주소가 18시

struct ROOM {
	string Name;
	int idx;
};

struct ResInfo {
	int s;
	int e;
};

vector <ROOM> room;

bool comp(ROOM left, ROOM right) {
	return left.Name < right.Name;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string RoomName;
		cin >> RoomName;
		room.push_back({ RoomName, i });
		reserv[i][9] = 1; // 끝지점 알려주기 위해서 1 기입	
	}

	for (int i = 0; i < M; i++) {
		int idx = 0;
		int s, e;
		string TempName;
		cin >> TempName >> s >> e;

		for (idx = 0; idx < room.size(); idx++) {
			if (room[idx].Name == TempName) break;
		}

		for (int usedTime = s-9; usedTime < e-9; usedTime++) {
			reserv[idx][usedTime] = 1;
		}
	}

	sort(room.begin(), room.end(), comp);

	for (int i = 0; i < room.size(); i++) {
		int flag = 0;
		int idx = room[i].idx;
		cout << "Room " << room[i].Name << ":" << endl;
		vector <ResInfo> info;
		int s = 0;
		int e = -1;
		while (1) {
			// 먼저 첫지점이 0인지점부터 찾자
			for (int j = s; j <= 9; j++) {
				s = j;
				if (reserv[idx][j] == 0) {
					flag = 1;
					break;
				}
			}
			if (s == 9 || s== -1) break;
			// 첫지점을 찾으면 end는 1이 나올때까지 탐색
			for (int j = s+1; j <= 9; j++) {
				if (reserv[idx][j] == 1) {
					e = j;
					break;
				}
			}
			if (e == -1) break;
			info.push_back({ s + 9,e + 9 });
			if (e == 9) break;
			s = e + 1;
		}
		if (!flag) {
			cout << "Not available\n";
		}
		else {
			cout << info.size() << " available:\n";
			for (int j = 0; j < info.size(); j++) {
				if (info[j].s < 10) {
					cout << "0" << info[j].s;
				}
				else {
					cout << info[j].s;
				}
				cout << "-" << info[j].e << endl;
			}
		}

		if (i < room.size() - 1) {
			cout << "-----\n";
		}
	}

	

	return 0;
}