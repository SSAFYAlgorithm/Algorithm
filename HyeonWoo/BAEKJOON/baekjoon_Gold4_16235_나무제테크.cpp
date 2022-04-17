#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

// 시간초과 지옥이네;; 이딴문제가 다있냐;

int N, M, K;
int Map[15][15]; // 현재 땅에 양분이 어떻게 저장되어있는지
int Robot[15][15]; // 양분주는 ROBOT
int Tree[15][15]; // 해당위치에 나무가 몇개나 있는지 (디버깅용)
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
int res;
struct INFO {
	int y, x, age;
};

//bool comp(INFO a, INFO b) {
//	return a.age < b.age;
//}

//priority_queue<INFO, vector <INFO>, comp> pq;
vector <INFO> dead;
deque <INFO> TreeInfo;
deque <INFO> Temp;
vector <INFO> parentsTree;
// 봄 : 양분먹고, 나이증가(한칸에 나무가 여러개면 어린순서부터), 양분못먹으면 죽음
void spring() {
	// 양분부터 먹자 자신의 나이만큼 양분 못먹으면 죽음
	dead = vector <INFO>();
	Temp = deque <INFO>();
	parentsTree = vector <INFO>();
	for (int i = 0; i < TreeInfo.size(); i++) {
		int y = TreeInfo[i].y;
		int x = TreeInfo[i].x;
		int age = TreeInfo[i].age;
		Map[y][x] -= age;
		if (Map[y][x] < 0) {
			Map[y][x] += age;
			dead.push_back({ y,x,age });
			Tree[y][x]--;
		}
		else {
			// 나이 증가
			Temp.push_back({ y,x,age + 1 });
			if ((age + 1) % 5 == 0) {
				// 가을에서 불필요한 반복 없애기위해서 봄에서 애초에 vector를 만들어준다.
				parentsTree.push_back({ y,x,age+1 });
			}
		}		
	}
	TreeInfo = Temp;
}

// 여름 : 봄에 죽은 나무 양분 추가
void summer() {
	for (int i = 0; i < dead.size(); i++) {
		int y = dead[i].y;
		int x = dead[i].x;
		int plus = dead[i].age / 2;
		Map[y][x] += plus;
	}
}

// 가을 : 나무 번식
void fall() {
	for (int i = 0; i < parentsTree.size(); i++) {
		int y = parentsTree[i].y;
		int x = parentsTree[i].x;
		int age = parentsTree[i].age;
		for (int dir = 0; dir < 8; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			Tree[ny][nx]++;
			TreeInfo.push_front({ny,nx,1});
		}
	}
}

// 겨울 : 로봇이 양분 추가
void winter() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x ++ ) {
			Map[y][x] += Robot[y][x];
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> Robot[y][x];
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> y >> x >> z;
		TreeInfo.push_back({ y,x,z });
		Tree[y][x]++;
	}
	//sort(TreeInfo.begin(), TreeInfo.end(), comp);

	// 맵 초기화 맨처음은 모든칸에 양분이 5만큼 저장
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			Map[y][x] = 5;
		}
	}

	for (int day = 1; day <= K; day++) {
		spring();
		summer();
		fall();
		winter();
	}

	// K일 지난후 tree가 몇개나 있는지 샌다
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res += Tree[i][j];
		}
	}

	cout << res;
	

	return 0;
}