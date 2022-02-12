#include<iostream>
#include<queue>

using namespace std;
int arr[1001][1001] = { 0 };
int node;//정점
int edge;//간선
int start;//시작점

bool checkDFS[1001] = { 0 }; //DFS 체크
bool checkBFS[1001] = { 0 }; //BFS 체크

void dfs(int level) {
	checkDFS[level] = 1;
	cout << level << " ";
	//dfs(level + 1);
	for (int i = 1;i <= node;i++) {
		if (arr[level][i] == 1) {
			if (!checkDFS[i]) {
				arr[level][i] = 0;

				dfs(i);
				arr[level][i] = 1;
			}
		}
	}
	return;
}
void bfs(int level)
{
	queue<int> que;
	que.push(level);
	checkBFS[level] = 1;
	while (1) {
		cout << que.front() << " ";
		que.pop();
		for (int i = 1;i <= node;i++) {
			if (arr[level][i] == 1) {
				if (!checkBFS[i]) {
					que.push(i);
					checkBFS[i] = 1;
				}
			}
		}
		if (que.empty()) {
			break;
		}
		level = que.front();
	}
}

int main(void)
{

	cin >> node >> edge >> start;
	for (int i = 0;i < edge;i++) {
		int s, f;
		cin >> s >> f;
		arr[s][f] = 1;
		arr[f][s] = 1;
	}

	dfs(start);
	cout << '\n';

	bfs(start);

}