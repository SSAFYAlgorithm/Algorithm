#include<iostream>

#define MAXSIZE 15
using namespace std;

int N;
int MAP[MAXSIZE];//0,1,2,3,4,5,6,7,..
int cnt = 0;

void dfs(int level)
{


	if (level == N)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < N;i++)
	{
		int flag = 0;
		MAP[level] = i;
		for (int j = 0;j < level;j++) {
			if (MAP[j] == MAP[level] || abs(MAP[level] - MAP[j]) == abs(level - j))
			{
				flag = 1; break;
			}
		}
		if (flag)continue;
		dfs(level + 1);

	}
}

int main()
{
	cin >> N;
	dfs(0);
	cout << cnt;
}