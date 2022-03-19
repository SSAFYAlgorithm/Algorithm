#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;
int M, S;
int sx, sy;
int sPath[3]; //상어경로
int goPath[3];//이번턴에 갈 경로
int bloodFish[5][5] = { 0 };//피냄새 위치
struct Fish {
	int x;
	int y;
	int d;
	int cnt;
};
vector<Fish>vect;
void killFish()
{
	int nowSharkX = sx;
	int nowSharkY = sy;
	int check[5][5] = { 0 };
	vector<int>kill;
	//현재위치에 물고기가있을때
	for (int j = 0; j < vect.size();j++) {
		if (vect[j].y == sy && vect[j].x == sx) {
			bloodFish[sy][sx] = 3;
			kill.push_back(j);
		}
	}
	//goPath로 진짜 물고기죽이기

	for (int i = 0; i < 3;i++) {
		if (goPath[i] == 0) {
			nowSharkX = nowSharkX - 1;
		}
		else if (goPath[i] == 1) {
			nowSharkY = nowSharkY - 1;
		}
		else if (goPath[i] == 2) {
			nowSharkX = nowSharkX + 1;
		}
		else if (goPath[i] == 3) {
			nowSharkY = nowSharkY + 1;
		}
		if (check[nowSharkX][nowSharkY])continue;
		for (int j = 0; j < M;j++) {
			if (vect[j].y == nowSharkY && vect[j].x == nowSharkX) {
				bloodFish[nowSharkY][nowSharkX] = 3;	//체크
				kill.push_back(j);
			}
		}
	}
	vector<Fish>now;
	for (int i = 0;i < M;i++) {
		int flag = 0;
		for (int j = 0;j < kill.size();j++) {
			if (kill[j] == i) {
				flag = 1;break;
			}
		}
		if (!flag)now.push_back(vect[i]);
	}
	vect.clear();
	vect = now;
	kill.clear();
	now.clear();
	sy = nowSharkY;
	sx = nowSharkX;
}

int findFish()
{
	int nowSharkX = sx;
	int nowSharkY = sy;
	int sum = 0;
	int check[5][5] = { 0 };
	//현재위치에 물고기가있을때
	for (int j = 0; j < vect.size();j++) {
		if (vect[j].x == nowSharkX && vect[j].y == nowSharkY) sum++;
	}
	check[nowSharkX][nowSharkY] = 1;
	//sPath로 물고기잡기 시뮬레이션
	for (int i = 0; i < 3;i++) {
		if (sPath[i] == 0) {
			nowSharkX = nowSharkX - 1;
		}
		else if (sPath[i] == 1) {
			nowSharkY = nowSharkY - 1;
		}
		else if (sPath[i] == 2) {
			nowSharkX = nowSharkX + 1;
		}
		else if (sPath[i] == 3) {
			nowSharkY = nowSharkY + 1;
		}
		if (check[nowSharkX][nowSharkY])continue;
		if (nowSharkY < 1 || nowSharkX < 1 || nowSharkX >= 5 || nowSharkY >= 5)return 0;
		for (int j = 0; j < vect.size();j++) {
			if (vect[j].y == nowSharkY && vect[j].x == nowSharkX) {
				sum += vect[j].cnt;
			}
		}
		check[nowSharkX][nowSharkY] = 1;
		M = vect.size();
	}

	return sum;

}
int maxFish = -1;
void sharkPath(int level)//2번 상어
{
	if (level == 3) {
		int now = findFish();
		if (now > maxFish) {
			maxFish = now;
			memcpy(goPath, sPath, sizeof(goPath));
		}
		return;
	}
	for (int i = 0;i < 4;i++) {
		sPath[level] = i;
		sharkPath(level + 1);
	}
}

void fishPath() {// 물고기 경로
	int fishX[8] = { 0,-1,-1,-1,0,1,1,1 };
	int fishY[8] = { -1,-1,0,1,1,1,0,-1 };
	for (int i = 0; i < vect.size();i++) {

		for (int j = 0;j < 8;j++) {
			int td = (vect[i].d - 1 - j);
			if (td < 0)td = 7 + vect[i].d - j; ///체크
			if (td == 8)td = 0;
			int tx = fishX[td] + vect[i].x;
			int ty = fishY[td] + vect[i].y;
			if (tx < 1 || ty < 1 || tx >= 5 || ty >= 5)continue;
			if (ty == sy && tx == sx)continue;
			if (bloodFish[ty][tx])continue;
			vect[i].x = tx;
			vect[i].y = ty;
			vect[i].d = td + 1;
			break;
		}
		//아무 처리도 없을시 위치변동 없음
	}
}
vector<Fish>magicFish;
void magic()
{
	for (int i = 0;i < magicFish.size();i++) {
		int flag = 0;
		for (int j = 0;j < vect.size();j++) {
			if (
				magicFish[i].x == vect[j].x
				&& magicFish[i].y == vect[j].y
				&& magicFish[i].d == vect[j].d
				) {
				flag = 1;
				vect[j].cnt += magicFish[i].cnt;
			}
		}
		if (!flag) {
			vect.push_back(magicFish[i]);
		}
	}

}
void solve()
{
	for (int i = 0; i < S;i++) {
		magicFish = vect; //복제마법

		fishPath();
		sharkPath(0);
		killFish();
		//냄새지우기
		for (int i = 1;i <= 4;i++) {
			for (int j = 0;j < 4;j++) {
				if (bloodFish[i][j])bloodFish[i][j]--;
			}
		}
		magic();
		magicFish.clear();
		maxFish = -1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> M >> S;
	for (int i = 0;i < M;i++) {
		int fx, fy, d;
		cin >> fx >> fy >> d;
		vect.push_back({ fx,fy,d,1 });
	}
	cin >> sx >> sy;
	solve();
	int ans = 0;
	for (int i = 0;i < vect.size();i++) {
		ans += vect[i].cnt;
	}
	cout << ans;
}