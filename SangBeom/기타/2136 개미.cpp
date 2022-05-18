#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, L;
struct Ant {
	int pos, num, dir;
};
vector<Ant>ant;
bool cmp(Ant left, Ant right) {
	return left.pos < right.pos;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;
	if (N == 1) {
		int a; cin >> a;
		if (a < 0)cout << 1 << " " << -1 * a;
		else cout << 1 << " " << L - a;
		return 0;
	}
	int left = 0;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (a < 0)
		{
			ant.push_back({ abs(a),i + 1,0 });//left
			left++;
		}
		else {
			ant.push_back({ a,i + 1,1 });//right
		}
	}
	sort(ant.begin(), ant.end(), cmp);
	int fr = 0;
	int fl = 0;
	for (int i = 0;i < N;i++) {
		if (ant[i].dir) {
			fr = L - ant[i].pos;
			break;
		}
	}
	for (int i = N - 1;i >= 0;i--) {
		if (!ant[i].dir) {
			fl = ant[i].pos;
			break;
		}
	}
	if (fl > fr) {
		cout << ant[left - 1].num << " " << fl;
	}
	else {
		cout << ant[left].num << " " << fr;
	}
	return 0;
}