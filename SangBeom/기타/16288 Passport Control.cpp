#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int visited[101];
int N, k;
vector<int>vect;
int solve()
{

	for (int t = 0;t < k;t++) {
		queue<int>que;
		for (int i = 0;i < vect.size();i++) {
			if (visited[vect[i]])continue;
			if (que.empty()) {
				que.push(vect[i]);
				visited[vect[i]] = 1;
			}
			else {
				if (que.back() < vect[i]) {
					que.push(vect[i]);
					visited[vect[i]] = 1;
				}
			}
		}
	}
	for (int i = 1;i <= N;i++) {
		if (!visited[i])return 0;
	}
	return 1;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> k;
	for (int i = 0;i < N;i++) {
		int a; cin >> a;
		vect.push_back(a);
	}
	if (solve())cout << "YES";
	else cout << "NO";
}