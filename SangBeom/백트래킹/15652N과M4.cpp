#include <iostream>
#include<vector>
using namespace std;

int n, m;
vector<int>res(9, 0);

void dfs(int num, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << res[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {
        
	
		res[depth] = i;
		dfs(i , depth + 1);
	
        
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);
}