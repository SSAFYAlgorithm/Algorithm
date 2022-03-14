#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int m, a, ans;
int userA[101];
int userB[101];

int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };


struct BC {
    int x;
    int y;
    int c;
    int p;
    BC(int x, int y, int c, int p) : x(x), y(y), c(c), p(p) {}
};

vector<BC> bclist;


int calc(int ax, int ay, int bx, int by) {

    //사용자 A의 BC별 충전량
    int sumA[8];
    //사용자 B의 BC별 충전량
    int sumB[8];

    memset(sumA, 0, sizeof(sumA));
    memset(sumB, 0, sizeof(sumB));

    int d;
    //사용자 A로부터 각 BC의 위치를 계산하여 i번 BC에 접속할 수 있다면 sumA[i]에 충전량을 저장한다.
    for (int i = 0; i < a; i++) {
        int bcx = bclist[i].x;
        int bcy = bclist[i].y;
        int c = bclist[i].c;
        int p = bclist[i].p;

        d = abs(ax - bcx) + abs(ay - bcy);
        if (d <= c) {
            sumA[i] = p;
        }
    }

    //사용자 B로부터 각 BC의 위치를 계산하여 i번 BC에 접속할 수 있다면 sumB[i]에 충전량을 저장한다.
    for (int i = 0; i < a; i++) {
        int bcx = bclist[i].x;
        int bcy = bclist[i].y;
        int c = bclist[i].c;
        int p = bclist[i].p;

        d = abs(bx - bcx) + abs(by - bcy);
        if (d <= c) {
            sumB[i] = p;
        }
    }


    //사용자 A와 사용자 B의 가능한 충전량의 합 중 최댓값을 sum에 저장
    int sum = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            int tmp = sumA[i] + sumB[j];

            //둘다 같은 BC에 접속할 수 있는 상태에서, 같은 BC에 접속한 경우 충전 양은 반으로 나눠진다.
            //(i == j) 이지만 한 명이 접속할 수 없는 상태(sum배열의 값이 0)인 경우 반으로 나누면 안된다.
            if (i == j && sumA[i] != 0 && sumB[i] != 0) tmp /= 2;

            if (sum < tmp) sum = tmp;
        }
    }


    return sum;
}


void solve() {

    //사용자 A의 초기 위치
    int ax = 0, ay = 0;
    //사용자 B의 초기 위치
    int bx = 9, by = 9;


    //m시간만큼 이동
    for (int t = 0; t < m; t++) {

        //현재시간에서 이용할수 있는 최대 충전 양을 구해서 ans에 더허ㅐ준다.
        ans += calc(ax, ay, bx, by);

        //이동
        ax += dx[userA[t]];
        ay += dy[userA[t]];
        bx += dx[userB[t]];
        by += dy[userB[t]];

    }

    //m시간에 이동한 위치에서 다시 한번 계산해준다.
    ans += calc(ax, ay, bx, by);



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        ans = 0;
        bclist.clear();

        cin >> m >> a;

        //사용자 이동 정보
        for (int i = 0; i < m; i++) {
            cin >> userA[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> userB[i];
        }


        //BC정보
        int x, y, c, p;
        for (int i = 0; i < a; i++) {
            cin >> x >> y >> c >> p;
            x--;
            y--;
            bclist.push_back(BC(y, x, c, p)); //행과 열 반대로 넣어줌!
        }


        solve();


        cout << '#' << tc << ' ' << ans << "\n";

    }

    return 0;
}
