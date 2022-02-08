#include <iostream>

using namespace std;

int N, M;

int path[8];
int used[9];

void dfs(int level)
{
	if (level == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (used[i] == 1)continue;
		
			used[i] = 1;
			path[level] = i;
			dfs(level + 1);
			used[i] = 0;
		
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
	return 0;
}
