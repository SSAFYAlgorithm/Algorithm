#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int R, C, M;
struct Fish {
    int r, c, s, d, z, flag;
};
vector<Fish>fish;
pair<int, int>MAP[101][101];
int ans = 0;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
void position()
{
    memset(MAP, 0, sizeof(MAP));
    for (int i = 0;i < fish.size();i++) {
        if (!fish[i].flag)continue;
        Fish now = fish[i];
        MAP[now.r][now.c].first = now.z;
        MAP[now.r][now.c].second = i;
    }
}
void killfish(int c) {
    for (int i = 0;i < R;i++) {
        if (MAP[i][c].first) {
            ans += MAP[i][c].first;
            MAP[i][c].first = 0;
            fish[MAP[i][c].second].flag = 0;
            break;
        }
    }
}
void movefish() {
    memset(MAP, 0, sizeof(MAP));
    for (int i = 0;i < fish.size();i++) {
        if (!fish[i].flag)continue;
        int tr = fish[i].r + dx[fish[i].d] * fish[i].s;
        int tc = fish[i].c + dy[fish[i].d] * fish[i].s;
        if (tr < 0) {  // 1 À§ 2 ¾Æ·¡
            if (!(((tr + 1) / (R - 1)) % 2)) {
                fish[i].d = 2;
                if (!(tr % (R - 1))) tr = R - 1;
                else tr = (tr % (R - 1)) * -1;
            }
            else {
                fish[i].d = 1;
                if (!(tr % (R - 1))) tr = 0;
                else tr = R - 1 + (tr % (R - 1));
            }

        }
        else if (tr >= R) {
            if (((tr - 1) / (R - 1)) % 2) {
                fish[i].d = 1;
                if (!(tr % (R - 1))) tr = 0;
                else tr = R - 1 - (tr % (R - 1));
            }
            else {
                fish[i].d = 2;
                if (!(tr % (R - 1))) tr = R - 1;
                else tr = (tr % (R - 1));
            }
        }
        if (tc < 0) {  // 3 ¿À 4 ¿Þ
            if (!(((tc + 1) / (C - 1)) % 2)) {
                fish[i].d = 3;
                if (!(tc % (C - 1))) tc = C - 1;
                else tc = (tc % (C - 1)) * -1;
            }
            else {
                fish[i].d = 4;
                if (!(tc % (C - 1))) tc = 0;
                else tc = C - 1 + (tc % (C - 1));
            }

        }
        else if (tc >= C) {
            if (((tc - 1) / (C - 1)) % 2) {
                fish[i].d = 4;
                if (!(tc % (C - 1))) tc = 0;
                else tc = C - 1 - (tc % (C - 1));
            }
            else {
                fish[i].d = 3;
                if (!(tc % (C - 1))) tc = C - 1;
                else tc = (tc % (C - 1));
            }
        }
        if (MAP[tr][tc].first) {
            if (fish[MAP[tr][tc].second].z > fish[i].z) {
                fish[i].flag = 0;
            }
            else {
                fish[MAP[tr][tc].second].flag = 0;
                fish[i].r = tr;
                fish[i].c = tc;
                MAP[tr][tc].first = fish[i].z;
                MAP[tr][tc].second = i;
            }
        }
        else {
            MAP[tr][tc].first = fish[i].z;
            MAP[tr][tc].second = i;
            fish[i].r = tr;
            fish[i].c = tc;
        }
    }
}
void solve()
{
    for (int i = 0;i < C;i++) {
        position();
        killfish(i);
        movefish();
    }
    cout << ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> R >> C >> M;
    for (int i = 0;i < M;i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        fish.push_back({ r - 1,c - 1,s,d,z ,1 });
    }
    solve();
}