#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 이게 뭐야... 이해가 안됨;;
// https://www.youtube.com/watch?v=tvyDu2JBTpE&t=107s

int N;
struct Edge {
    int node, cost;
};

vector <Edge> adj[200005];
int used[200005];
long res[200005];
long subtreesize[200005];

void dfs1(int current, int parent) {
    subtreesize[current] = 1;
    for (int i = 0; i < adj[current].size(); i++) {
        int next_node = adj[current][i].node;
        int next_cost = adj[current][i].cost;
        if (next_node == parent) continue;
        dfs1(next_node, current);
        res[current] += res[next_node] + subtreesize[next_node]*next_cost;
        subtreesize[current] += subtreesize[next_node];
    }
}

// res[now_node] = res[parent] - now_cost * sub_node_cnt + now_cost * (N - sub_node_cnt);
void dfs2(int current, int parent) {
    for (int i = 0; i < adj[current].size(); i++) {
        int next_node = adj[current][i].node;
        int next_cost = adj[current][i].cost;
        if (next_node == parent) continue;
        res[next_node] = res[current] + next_cost * (N - subtreesize[next_node] * 2);
        dfs2(next_node, current);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({ to,cost });
        adj[to].push_back({ from,cost });
    }
    dfs1(1, 1); // dfs로 subtreesize 구하기
    dfs2(1, 1);

    for (int i = 1; i <= N; i++) {
        cout << res[i] << endl;
    }
    return 0;
}