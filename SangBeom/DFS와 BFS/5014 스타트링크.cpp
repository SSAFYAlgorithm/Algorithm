#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d;
int Floor[1000001];
int flag;
void bfs()
{
	queue<int>que;
	Floor[s] = 1;
	que.push(s);
	d = d * -1;
	int dir[2] = { u,d };
	while (!que.empty())
	{
		int now = que.front();que.pop();
		if (now == g) {
			flag = 1;
			break;
		}
		for (int i = 0;i < 2;i++) {
			int t = dir[i] + now;
			if (t <= 0 || t > f)continue;
			if (Floor[t])continue;
			Floor[t] = Floor[now] + 1;

			que.push(t);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> f >> s >> g >> u >> d;
	bfs();
	if (flag)cout << --Floor[g];
	else cout << "use the stairs";
}