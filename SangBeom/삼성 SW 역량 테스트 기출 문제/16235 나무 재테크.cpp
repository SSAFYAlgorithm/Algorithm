#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
struct Tree
{
    int x, y, z;
};
vector<Tree>tree;
int N, M, K;
int MAP[11][11];
int A[11][11];
vector<Tree>live;
vector<Tree>dead;
/*
10 1 1000

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

100 100 100 100 100 100 100 100 100 100

1 1 1
ans : 5443
timeout
*/
bool cmp(Tree left, Tree right)
{
    if (left.x < right.x)return true;
    if (left.x > right.x)return false;
    if (left.y < right.y)return true;
    if (left.y > right.y)return false;
    return left.z < right.z;

}
void spring()
{
    sort(tree.begin(), tree.end(), cmp);
    for (int i = 0; i < tree.size();i++) {
        if (MAP[tree[i].x][tree[i].y] >= tree[i].z) {
            MAP[tree[i].x][tree[i].y] -= tree[i].z;
            live.push_back({ tree[i].x,tree[i].y,tree[i].z + 1 });
        }
        else {
            dead.push_back({ tree[i].x,tree[i].y,tree[i].z });
        }
    }
    tree.clear();
}
void summer()
{
    for (int i = 0;i < dead.size();i++) {
        MAP[dead[i].x][dead[i].y] += (dead[i].z / 2);
    }
    dead.clear();
}
void fall() {
    int dx[8] = { -1,0,1,-1,1,-1,0,1 };
    int dy[8] = { -1,-1,-1,0,0,1,1,1 };
    for (int i = 0;i < live.size();i++) {
        tree.push_back({ live[i].x,live[i].y,live[i].z });
        if (live[i].z % 5 == 0) {
            for (int j = 0;j < 8;j++) {
                int tx = dx[j] + live[i].x;
                int ty = dy[j] + live[i].y;
                if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
                tree.push_back({ tx,ty,1 });
            }
        }
    }
    live.clear();
}
void winter()
{
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            MAP[i][j] += A[i][j];
        }
    }
}
int solve()
{
    for (int i = 0;i < K;i++) {
        spring();
        summer();
        fall();
        winter();
    }
    return tree.size();
}
int main()
{
    freopen("input.txt", "r", stdin);
    vector<Tree>vect;
    vect.push_back({ 1,1,1 });
    vect.push_back({ 1,1,1 });
    sort(vect.begin(), vect.end(), cmp);
    cin >> N >> M >> K;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> A[i][j];
            MAP[i][j] = 5;
        }
    }
    for (int i = 0;i < M;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree.push_back({ x - 1,y - 1,z });
    }
    cout << solve();
}