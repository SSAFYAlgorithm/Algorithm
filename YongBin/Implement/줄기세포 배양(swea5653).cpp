#include <iostream>
#include <algorithm>
#include <vector>
//#include <queue>
#include <cstring>
//#include <fstream>

using namespace std;
int n, m, k, ans = 0, temp;
int arr[351][351];
//priority_queue<cell, vector<cell>, cmp> q;


int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

/*
struct cmp {
	bool operator() (cell a, cell b){
		return a.life < b.life;
	}
};
*/


typedef struct {
	int x; // x 좌표
	int y; // y 좌표
	int life; // 생명력
	int activeTime; // 활성화 시간 = life + bornTime;
	int bornTime; // 태어난 시간
	int dieTime; // 죽는 시간 = life + activeTime;
	bool state; // 죽었는지 살았는지
}cell;

vector<cell> v;

bool cmp(cell a, cell b) {
	return a.life > b.life;
}

void deleteCell(int time) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].dieTime == time) {
			v[i].state = false;
		}
	}
}

void culture(int time) {
	vector<cell> tempCell;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].state == true && v[i].activeTime == time) {
			int x = v[i].x;
			int y = v[i].y;
			int life = v[i].life;

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (arr[nx][ny] == 0) {
					cell temp;
					temp.x = nx;
					temp.y = ny;
					temp.life = life;
					temp.bornTime = time + 1;
					temp.activeTime = time + 1 + life;
					temp.dieTime = time + 1 + life * 2;
					temp.state = true;
					tempCell.push_back(temp);
				}
			}
		}
	}
	//cout << tempCell.size() << "\n";
	if (tempCell.size() != 0) {
		sort(tempCell.begin(), tempCell.end(), cmp);

		for (int i = 0; i < tempCell.size(); i++) {
			if (arr[tempCell[i].x][tempCell[i].y] == 0) {
				arr[tempCell[i].x][tempCell[i].y] = tempCell[i].life;
				v.push_back(tempCell[i]);
			}
		}
	}
	return;
}

int main() {
	int t;
	//ifstream is("input.txt");
	cin >> t;
	//is >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		/////////////////////////init/////////////////////
		v.clear();
		memset(arr, 0, sizeof(arr));
		ans = 0;
		/////////////////input////////////////////////////
		//is >> n >> m >> k;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> temp;
				//is >> temp;
				arr[150 + i][150 + j] = temp;
				if (temp != 0) {
					cell a;
					a.x = i + 150;
					a.y = j + 150;
					a.life = temp;
					a.bornTime = 0;
					a.activeTime = temp;
					a.dieTime = temp + temp;
					a.state = true;
					v.push_back(a);
				}
			}
		}
		////////////////////////////////////////////////////

		//////////////////////배양 시작//////////////////////
		int now = 0;
		while(now < k){
			deleteCell(now);
			culture(now);
			now++;
		}
		
		for (int i = 0; i < v.size(); i++) {
			if (v[i].state == true && v[i].dieTime != k && v[i].bornTime != k + 1)
				ans++;
		}
		////////////////////////////////////////////////////
		cout << "#" << testcase << " " << ans << "\n";
	}
	return 0;
}