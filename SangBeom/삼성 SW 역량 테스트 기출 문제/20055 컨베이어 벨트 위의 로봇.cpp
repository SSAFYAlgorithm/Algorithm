#include<iostream>
#include<queue>
using namespace std;
deque<pair<int, int>>deq;
int N, k;

int solve()
{
    int ans = 0;
    while (1)
    {
        ans++;
        //1
        pair<int, int> a = deq.back();
        deq.pop_back();
        deq.push_front(a);
        //erase robot
        if (deq[deq.size() - 1].second) deq[deq.size() - 1].second = 0;
        //2 move robot
        for (int i = deq.size() - 2;i >= 0;i--) {
            if (deq[i].second) {
                if (deq[i + 1].first && !deq[i + 1].second) {
                    deq[i + 1].second = 1;
                    deq[i].second = 0;
                    deq[i + 1].first--;
                }

            }
        }
        //3
        if (deq[0].first) {
            deq[0].second = 1;
            deq[0].first--;
        }
        //4
        int cnt = 0;
        for (int i = 0;i < deq.size();i++) {
            if (deq[i].first == 0) {
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
        deq.push_back(pair<int, int>(a, 0));
    }
    cout << solve();
}