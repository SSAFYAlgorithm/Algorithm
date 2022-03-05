#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;
//192MB -> 2억바이트
int N, M;
int arr[1002][1002] = { 0 }; // 800만
int cnt[1002][1002][2] = { 0 }; //800만

/*
7 10
0000000000
1010101010
1111111111
1111111110
0000000000
0111111111
0000000000

13 13
0100011011000
0001001010000
0000100001000
1100010101011
1111101111000
1011010001001
0100001001001
0100111010001
0101010000100
0001110100000
0000001000100
1010001000111
1001000100000

정답 : 27

8 8
01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100

답 29

5 5
01100
01000
01110
01000
00010

답 9
*/
struct Node {
	int y;
	int x;
	bool flag;
};
int bfs(int y, int x) {
	queue<Node>que;
	que.push({ y,x,0 });
	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,-1,0,1 };
	cnt[y][x][0] = 1;
	while (!que.empty())
	{
		int nowY = que.front().y;
		int nowX = que.front().x;
		bool nowFlag = que.front().flag;
		if (nowY == N && nowX == M) {
			return cnt[nowY][nowX][nowFlag];
		}
		for (int i = 0;i < 4;i++) {
			int tx = nowX + dx[i];
			int ty = nowY + dy[i];
			if (tx<1 || ty<1 || tx>M || ty>N)continue;

			if (arr[ty][tx] == 1) {
				if (nowFlag == false) {
					que.push({ ty,tx,1 });
					cnt[ty][tx][nowFlag + 1] = cnt[nowY][nowX][nowFlag] + 1;
				}
				else {
					continue;
				}
			}
			else {
				if (!cnt[ty][tx][nowFlag]) {
					cnt[ty][tx][nowFlag] = cnt[nowY][nowX][nowFlag] + 1;
					que.push({ ty,tx,nowFlag });
				}
			}
		}
		que.pop();
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < M;j++) {
			arr[i][j + 1] = (int)(str[j] - '0');
		}
	}
	cout << bfs(1, 1);

}