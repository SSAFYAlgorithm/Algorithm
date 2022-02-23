#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool dfs_visited[9];
bool bfs_visited[9];
vector<int> graph[9];

void dfs(int x) {
    dfs_visited[x] = true;
    cout << x << ' ';

    sort(graph[x].begin(), graph[x].end());
    
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!dfs_visited[y]) dfs(y);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bfs_visited[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';

        sort(graph[x].begin(), graph[x].end());

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!bfs_visited[y]) {
                q.push(y);
                bfs_visited[y] = true;
            }
        }
    }
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    int s, e;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    dfs(V);
    cout << '\n';
    bfs(V);

    return 0;
}