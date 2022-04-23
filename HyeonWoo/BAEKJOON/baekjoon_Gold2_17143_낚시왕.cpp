#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int dy[] = { -99,-1,1,0,0 }; //0은더미, 1:위, 2: 아래 3: 오 4: 왼
int dx[] = { -99,0,0,1,-1 };

int R, C, M;
// map에는 해당 좌표에 샤크가 몇마리 존재하는지 기입
int map_size[101][101];
int res;
struct NowCondition {
	// 위치, 속력 이동방향
	int r,c,s,d;
};

int MAX_SharkSize = 0;
int MIN_SharkSize = 21e8;
vector <vector <NowCondition>> Shark(10001); //(크기 기준)
vector <vector <NowCondition>> TempShark(10001); // 변할때마다 잠깐씩 담아줄 샤크배열


void Move() {
	TempShark = vector <vector <NowCondition>>(10001);
	int temp_map[101][101] = { 0 };
	for (int i = MIN_SharkSize; i <= MAX_SharkSize; i++) {
		if (Shark[i].size() == 0) continue;
		int r = Shark[i][0].r;
		int c = Shark[i][0].c;
		int s = Shark[i][0].s;
		int d = Shark[i][0].d;
		int nr = r;
		int nc = c;
		
		// for문으로 s만큼 돌리면, 시간초과 걸린다.
		// 다른로직
		// 일단 해당방향에서 끝까지 몇칸있는지 센다.
		int temp = 0; // 끝까지 몇칸이 있는지.
		if (d == 1) { // y축이니까 r로계산 시작이 0;
			temp = r-1;
			if (temp >= s) {
				// s만큼 움직인다
				nr = r - s;
			}
			else {
				int Subtemp = s - temp;
				int mok = Subtemp / (R - 1);
				int nam = Subtemp % (R - 1);
				if (mok == 0 || mok % 2 == 0) { // 짝수면 방향도 반전
					nr = 1 + nam;
					d++;
				}
				else {
					nr = R - nam;
				}
			}
		}
		else if (d == 2) { // y축이니까 r로계산 시작이 R;
			temp = R - r;
			if (temp >= s) {
				// s만큼 움직인다
				nr = r + s;
			}
			else {
				int Subtemp = s - temp;
				int mok = Subtemp / (R - 1);
				int nam = Subtemp % (R - 1);
				if (mok == 0 || mok % 2 == 0) {
					nr = R - nam;
					d--;
				}
				else {
					nr = 1 + nam;
				}
			}
		}
		else if (d == 4) { // x축이니까 c로계산 시작이 0; 왼쪽
			temp = c - 1;
			if (temp >= s) {
				// s만큼 움직인다
				nc = c - s;
			}
			else {
				int Subtemp = s - temp;
				int mok = Subtemp / (C - 1);
				int nam = Subtemp % (C - 1);
				if (mok == 0 || mok % 2 == 0) { // 짝수면 1+nam
					nc = 1 + nam;
					d--;
				}
				else { // 홀수면 C-nam
					nc = C - nam;
				}
			}
		}
		else if (d == 3) { // x축이니까 c로계산 시작이 C; 오른쪽
			temp = C-c;
			if (temp >= s) {
				// s만큼 움직인다
				nc = c + s;
			}
			else {
				int Subtemp = s - temp;
				int mok = Subtemp / (C - 1);
				int nam = Subtemp % (C - 1);
				if (mok == 0 || mok % 2 == 0) { // 짝수면 C-nam
					nc = C - nam;
					d++;
				}
				else { // 홀수면 C+nam
					nc = 1 + nam;
				}
			}
		}

		if (temp_map[nr][nc] != 0) {
			int winSharkSize = max(temp_map[nr][nc], i); // i가 현재샤크 사이즈
			if (winSharkSize == i) {
				// 현재 샤크가 이겼으면 원래있던 샤크 잡아먹힌다.
				TempShark[temp_map[nr][nc]].pop_back();
				temp_map[nr][nc] = i;
				TempShark[i].push_back({ nr,nc,s,d });
			}
			// 현재 샤크가 졌으면 현재 샤크 잡아먹힌다. -> 맵갱신x , 샤크추가 x
		}
		else {
			temp_map[nr][nc] = i;
			TempShark[i].push_back({ nr,nc,s,d });
		}
	}
	Shark = TempShark;
	memcpy(map_size, temp_map, sizeof(map_size));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark[z].push_back({r,c,s,d});
		map_size[r][c] += z;
		if (z > MAX_SharkSize) MAX_SharkSize = z;
		if (z < MIN_SharkSize) MIN_SharkSize = z;
	}
	for (int person = 1; person <= C; person++) {
		for (int y = 1; y <= R; y++) {
			if (map_size[y][person] != 0) {
				// 해당 샤크를 잡는다.
				Shark[map_size[y][person]].pop_back();
				res += map_size[y][person];
				map_size[y][person] = 0;
				break;
			}
		}

		// 상어 잡았으면 상어 움직인다.
		Move();
	}
	cout << res;



	return 0;
}