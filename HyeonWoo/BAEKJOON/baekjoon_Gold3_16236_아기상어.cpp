#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 이문제 BFS탐색시에 아기상어 자기자신 탐색하는 경우 없어야하고, BFS가지치기가 중요한문제 -> 시간초과남

int N;
int arr[25][25];
int res = 0;
int dy[] = { -1,0,0,1 }; // 상 좌 우 하
int dx[] = { 0,-1,1,0 };
int flag = 0;
struct Node {
	int y, x;
};

struct CanEat {
	int y, x, dis; // 물고기의 위치, 현재 물고기부터 타겟물고기까지의 거리
};

// (거리가 가까운 물고기 우선 거리가 가까운물고기가 여러마리면 위쪽우선, 위쪽도 같으면 왼쪽우선)
bool comp(CanEat a, CanEat b) {
	if (a.dis == b.dis) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.dis < b.dis;
}

vector <vector <Node>> Fish(7); // 사이즈별 물고기가 있는 장소
int BabySize = 2;
int NowEat = 0; // 현재 몇마리 먹었는지
Node Baby;
vector <CanEat> CanTarget; // 먹을수 있는 물고기를 전부 대입

int isExist() {
	int end = 0;
	if (BabySize > 7) {
		end = 7;
	}
	else {
		end = BabySize;
	}
	for (int i = 1; i < end; i++) {
		if (Fish[i].size() > 0) {
			return 0;
		}
	}
	return 1; // 존재하지 않는경우
}

// 먼저 bfs로 각 위치별 거리 계산후, 갈 수 있는 경우를 vector에 담고, 조건대로 정렬
// Baby의 좌표가 Target까지 이동해야한다(만약에 가능하다면)
void Move() {
	int y = Baby.y;
	int x = Baby.x;
	if (Baby.y == 4 && Baby.x == 0) {
		int de = -1;
	}
	// bfs로 타겟좌표에 갈 수 있는지
	int cnt[25][25] = {0};
	queue <Node> q;
	q.push({ y,x });
	int Limit = 0;
	CanTarget = vector <CanEat>();
	while (!q.empty()) {
		int nowy = q.front().y;
		int nowx = q.front().x;
		q.pop();
		if(arr[nowy][nowx]<BabySize && cnt[nowy][nowx] != 0 && arr[nowy][nowx] != 0 && arr[nowy][nowx] != 9) break;
		if (cnt[nowy][nowx] > Limit && Limit!=0) continue;
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (arr[ny][nx] > BabySize) continue; // 같은크기라면 지나갈 수는 있다.
			if (cnt[ny][nx] != 0) continue;
			cnt[ny][nx] = cnt[nowy][nowx] + 1;
			if (cnt[ny][nx] > Limit && Limit != 0) continue;
			if (arr[ny][nx] != 0 && arr[ny][nx] < BabySize && arr[ny][nx] != 9) {
				CanTarget.push_back({ ny,nx,cnt[ny][nx] });
				Limit = cnt[ny][nx];
				continue;
			}
			q.push({ ny,nx });
		}
	}
	if (CanTarget.size() == 0) {
		flag = 1;
		return;
	}
	if (CanTarget.size() > 1) {
		sort(CanTarget.begin(), CanTarget.end(), comp);
	}
	Node Target = { CanTarget[0].y,CanTarget[0].x };

	int end = 0;
	if (BabySize > 7) {
		end = 7;
	}
	else {
		end = BabySize;
	}
	
	res += cnt[Target.y][Target.x];
	arr[Baby.y][Baby.x] = 0;
	int TargetAge = arr[Target.y][Target.x];
	Baby = Target;
	NowEat++;
	if (NowEat == BabySize) {
		BabySize++;
		NowEat = 0;
	}
	// 해당좌표를 Fish에서 지워야한다.
	vector <Node> temp;
	for (int i = 0; i < Fish[TargetAge].size(); i++) {
		if (Fish[TargetAge][i].y == Target.y && Fish[TargetAge][i].x == Target.x) continue;
		temp.push_back(Fish[TargetAge][i]);
	}
	Fish[TargetAge] = vector<Node>();
	for (int i = 0; i < temp.size(); i++) {
		Fish[TargetAge].push_back(temp[i]);
	}
	arr[Target.y][Target.x] = 9;
	return;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) Baby = { i,j };
			else if (arr[i][j] > 0) Fish[arr[i][j]].push_back({ i,j });
		}
	}

	while (1) {
		// 맵에 먹을수 있는 물고기가 있는지 확인
		if(isExist()) break;

		// 먹을 수 있는 물고기가 한마리라면 그 물고기 냠냠
		// 1마리보다 많으면 거기가 가장 가까운 물고기부터 (거리가 가까운물고기가 여러마리면 위쪽우선, 위쪽도 같으면 왼쪽우선)
		//Node Target = WhoTarget();
		Move();
		if (flag) break;
	}
	cout << res;
	

	return 0;
}