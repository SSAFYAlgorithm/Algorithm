#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, L, R;
int arr[55][55];
int group[55][55];
int used[55][55];
int flag = 1;
int res = 0;
struct Node {
	int y, x;
};

int dy[] = {0,1}; // 우,하
int dx[] = {1,0};

// UnionFind 알고리즘으로 현재 연결됐는지 확인한다.
Node parents[55][55];

Node Find(Node a) {
	// 이미 자기자신이 부모라면 return
	if ((parents[a.y][a.x].y == a.y) && (parents[a.y][a.x].x == a.x)){
		return a;
	}
	return Find(parents[a.y][a.x]);
}

// a가 b밑으로 들어간다 -> a의 부모를 b로만들어주려한다.
void Union(Node a, Node b) {
	// 먼저 a와 b의 부모찾고
	Node pa = Find(a);
	Node pb = Find(b);
	if (pa.y == pb.y && pa.x == pb.x) return; // 부모가 이미 같으면 return 
	// 부모가 다르면 부모에 속하게 만들어줌
	parents[pa.y][pa.x] = pb;
	
}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}
	while (flag) {
		flag = 0;
		// parents 초기화
		for (int y = 0; y < 55; y++) {
			for (int x = 0; x < 55; x++) {
				parents[y][x] = { y,x }; // 자기자신이 부모상태
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				for (int i = 0; i < 2; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					if (abs(arr[y][x] - arr[ny][nx]) < L || abs(arr[y][x] - arr[ny][nx]) > R) continue;
					// 이미 부모가 같으면 무시
					if ((Find({ y,x }).y == Find({ ny,nx }).y) && (Find({ y,x }).x == Find({ ny,nx }).x)) continue;
					// 위의조건에서 모두 걸러지면 y,x 와 ny,nx는 같은 부모를 가져야한다.
					Union({ ny,nx }, { y,x });
					flag = 1;// 인구이동이 한번이라도 있으면 flag 1로 변환 (반복문실행 위해서)
				}
			}
		}

		if (!flag) break; // 인구이동 없다면 탈출

		// 수 바꿔주는 작업
		// 먼저 개개인별 그룹별로 몇명씩 있는지 파악
		memset(group, 0, sizeof(group));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				Node temp = Find({ y,x });
				group[temp.y][temp.x]++;
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (group[y][x] < 2) continue; // 만약 부모가 아니거나 그룹이 안되어있으면 continue;
				// 부모를 찾았다면, 2중포문으로 누가 해당 부모를 가졌는지 파악
				vector <Node> vect;
				memset(used, 0, sizeof(used));
				for (int yy = 0; yy < N; yy++) {
					for(int xx=0; xx<N; xx++){
						if (used[yy][xx] != 0) continue;
						if ((Find({ yy,xx }).y == y) && (Find({ yy,xx }).x == x)) {
							vect.push_back({ yy,xx });
						}
					}
				}
				
				int sum = 0;
				for (int i = 0; i < vect.size(); i++) {
					sum += arr[vect[i].y][vect[i].x];
				}
				
				if (vect.size() == 0) continue;
				int val = sum / vect.size();

				for (int i = 0; i < vect.size(); i++) {
					arr[vect[i].y][vect[i].x] = val;
					used[vect[i].y][vect[i].x] = 1;
				}

				
			}
		}

		res++; // 횟수증가
	}

	cout << res;

	return 0;
}