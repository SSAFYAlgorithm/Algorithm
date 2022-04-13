#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int N,M;
int map[55][55];
int answer = 21e8;
vector <Node> Chicken;
vector <Node> House;
vector <Node> path;

int FindDistance() {
	int res = 0;
	for (int i = 0; i < House.size(); i++) {
		int HouseY = House[i].y;
		int HouseX = House[i].x;
		int len = 21e8;
		for (int j = 0; j < path.size(); j++) {
			int ChickenY = path[j].y;
			int ChickenX = path[j].x;
			int templen = abs(HouseY - ChickenY) + abs(HouseX - ChickenX);
			if (templen < len) {
				len = templen;
			}
		}
		res += len;
	}
	return res;
}


// 치킨집 나열할 예정
void DFS(int cnt, int lastidx) {
	if (cnt == M) {
		// 최소거리 구하기
		int minlen = FindDistance();
		if (minlen < answer) {
			answer = minlen;
		}
		return;
	}

	for (int i = lastidx+1; i < Chicken.size(); i++) {
		path.push_back({ Chicken[i] });
		DFS(cnt + 1, i);
		path.pop_back();
	}
}


int main() {
	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				House.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				Chicken.push_back({ i,j });
			}
		}
	}

	// DFS로 치킨집 3개씩 고르고, 그때의 거리를 구한다
	DFS(0, -1);

	cout << answer;
	
}