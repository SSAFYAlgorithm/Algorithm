#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int num = 1; // 섬번호
int arr[20][20];
int used[20][20];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int res = 0;
struct Node {
    int y;
    int x;
};

struct info {
    int from;
    int to;
    int len;
};

bool comp(info left, info right) {
    return left.len < right.len;
}

vector <vector <Node>> IslandPlace(7);
vector <info> dist;
// 최단거리 구하는 2차원배열
int Distance[10][10];
void dfs(int y, int x, int start, int end, int cnt, int dir) {
    if (arr[y][x] == end) {
        cnt--;
        if (cnt < 2) {
            cnt = 0;
            return;
        }
        if (Distance[start][end] == 0) {
            Distance[start][end] = cnt;
        }
        else {
            Distance[start][end] = min(Distance[start][end],cnt);
        }
        return;
    }
    if (arr[y][x] != 0 && arr[y][x] != end && arr[y][x] != start) {
        return;
    }
    if (y < 0 || x < 0 || y >= N || x >= M) {
        return;
    }
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (arr[ny][nx] == 0 || arr[ny][nx] == end) {
        dfs(ny, nx, start, end, cnt + 1, dir);
    }
    return;
    
}

// UnionFInd로 구해야하는데 어렵;
 
int parents[7] = {0,1,2,3,4,5,6};
int Result[7];
int Find(int now) {
    if (parents[now] == now) return now;
    return Find(parents[now]);
}

void Union(int group1, int group2) {
    int pG1 = Find(group1);
    int pG2 = Find(group2);
    if (pG1 < pG2) parents[pG1] = pG2;
    else parents[pG2] = pG1;
}


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // BFS로 섬마다 번호 매겨주자
    queue <Node> q;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if(arr[y][x] == 1 && used[y][x] == 0) {
                q.push({ y,x });
                used[y][x] = 1;
                while (!q.empty()) {
                    int nowY = q.front().y;
                    int nowX = q.front().x;
                    
                    arr[nowY][nowX] = num;
                    IslandPlace[num].push_back({ nowY,nowX });
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int ny = nowY + dy[i];
                        int nx = nowX + dx[i];
                        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                        if (used[ny][nx] != 0) continue;
                        if (arr[ny][nx] == 0) continue;
                        used[ny][nx] = 1;
                        q.push({ ny,nx });
                    }
                }
                num++;
            }
        }
    }
    
    // 섬간 최단거리 찾기 (i는 start섬, j는 end섬)
    for (int i = 1; i < num-1; i++) {
        for (int j = i+1; j < num; j++) {
            for (int k = 0; k < IslandPlace[i].size(); k++) {
                int y = IslandPlace[i][k].y;
                int x = IslandPlace[i][k].x;
                for (int dir = 0; dir < 4; dir++) {
                    dfs(y, x, i, j, 0, dir);
                }
            }
        }
    }

    // Distance 배열에 모든 최단거리 기록완료
    // 경우의수로 정답을 추려야한다
    
    // UNION FIND로 최종값 찾아보자
    // 크루스칼 알고리즘 활용
    dist = vector <info>();
    for (int i = 1; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (Distance[i][j] > 0) {
                dist.push_back({ i,j,Distance[i][j] });
            }
        }
    }

    // 오름차순으로 정렬
    sort(dist.begin(), dist.end(), comp);

    // 이후 최소간선길이 찾아준다
    for (int i = 0; i < dist.size(); i++) {
        info now = dist[i];
        // cycle 판정 부모가 같다면 무시
        if (Find(now.from) == Find(now.to)) continue;
        // 부모가 다르면
        Union(now.from, now.to);
        res += now.len;
    }
    
    // 모든섬이 연결되었는지 확인
    int flag = 0;
    for (int i = 2; i < num; i++) {
        if (Find(1) != Find(i)) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << -1;
    }
    else {
        cout << res;
    }
    return 0;
}