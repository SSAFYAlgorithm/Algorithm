#include<iostream>
#include<queue>
using namespace std;
struct container {
    int a;
    int r;

};
deque<container>deq;
int N, k;
int solve()
{
    int ans = 0;
    while (1)
    {
        ans++;
        //1
        container now = deq.back();
        deq.pop_back();
        deq.push_front(now);
        //erase robot
        if (deq[N - 1].r) deq[N - 1].r = false;
        //2 move robot
        for (int i = N - 1;i >= 0;i--) {
            if (deq[N - 1].r) deq[N - 1].r = false;

            if (deq[i].r) {
                if (deq[i + 1].r || !deq[i + 1].a)continue;
                deq[i].r = 0;
                deq[i + 1].r = 1;
                deq[i + 1].a--;
            }
        }
        if (deq[N - 1].r) deq[N - 1].r = false;

        //3
        if (deq[0].a && !deq[0].r) {
            deq[0].r = true;
            deq[0].a--;
        }
        //4
        int cnt = 0;
        for (int i = 0;i < deq.size();i++) {
            if (deq[i].a == 0) {
                cnt++;
            }

        }
        if (cnt >= k)break;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N >> k;
    for (int i = 0; i < 2 * N;i++) {
        int a;
        cin >> a;
        deq.push_back({ a,0 });

    }
    cout << solve();
}