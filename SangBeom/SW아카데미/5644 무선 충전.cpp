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

    //����� A�� BC�� ������
    int sumA[8];
    //����� B�� BC�� ������
    int sumB[8];

    memset(sumA, 0, sizeof(sumA));
    memset(sumB, 0, sizeof(sumB));

    int d;
    //����� A�κ��� �� BC�� ��ġ�� ����Ͽ� i�� BC�� ������ �� �ִٸ� sumA[i]�� �������� �����Ѵ�.
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

    //����� B�κ��� �� BC�� ��ġ�� ����Ͽ� i�� BC�� ������ �� �ִٸ� sumB[i]�� �������� �����Ѵ�.
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


    //����� A�� ����� B�� ������ �������� �� �� �ִ��� sum�� ����
    int sum = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            int tmp = sumA[i] + sumB[j];

            //�Ѵ� ���� BC�� ������ �� �ִ� ���¿���, ���� BC�� ������ ��� ���� ���� ������ ��������.
            //(i == j) ������ �� ���� ������ �� ���� ����(sum�迭�� ���� 0)�� ��� ������ ������ �ȵȴ�.
            if (i == j && sumA[i] != 0 && sumB[i] != 0) tmp /= 2;

            if (sum < tmp) sum = tmp;
        }
    }


    return sum;
}


void solve() {

    //����� A�� �ʱ� ��ġ
    int ax = 0, ay = 0;
    //����� B�� �ʱ� ��ġ
    int bx = 9, by = 9;


    //m�ð���ŭ �̵�
    for (int t = 0; t < m; t++) {

        //����ð����� �̿��Ҽ� �ִ� �ִ� ���� ���� ���ؼ� ans�� ������ش�.
        ans += calc(ax, ay, bx, by);

        //�̵�
        ax += dx[userA[t]];
        ay += dy[userA[t]];
        bx += dx[userB[t]];
        by += dy[userB[t]];

    }

    //m�ð��� �̵��� ��ġ���� �ٽ� �ѹ� ������ش�.
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

        //����� �̵� ����
        for (int i = 0; i < m; i++) {
            cin >> userA[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> userB[i];
        }


        //BC����
        int x, y, c, p;
        for (int i = 0; i < a; i++) {
            cin >> x >> y >> c >> p;
            x--;
            y--;
            bclist.push_back(BC(y, x, c, p)); //��� �� �ݴ�� �־���!
        }


        solve();


        cout << '#' << tc << ' ' << ans << "\n";

    }

    return 0;
}
