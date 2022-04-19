#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N;
int People[15];
vector <vector <int>> near(11);
vector <int> group1;
vector <int> group2;
int group[15];
int initparents[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int parents[15];
int res = 21e8;
int flag = 0; // 정답이 될수 있는 경우가 있는지 없는지
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> People[i];
	}

	for (int i = 1; i <= N; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			near[i].push_back(temp);
		}
	}
}


int Find(int now) {
	if (parents[now] == now) {
		return parents[now];
	}

	return Find(parents[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;
	if (pa > pb) parents[pa] = pb;
	else parents[pb] = pa;
}

int isSameGroup(int groupnum) {
	if (groupnum == 1) {
		if (group1.size() == 1) return 1;
		int standard = Find(group1[0]);
		for (int i = 1; i < group1.size(); i++) {
			if (Find(group1[i]) != standard) return 0;
		}
	}
	else {
		if (group2.size() == 1) return 1;
		int standard = Find(group2[0]);
		for (int i = 1; i < group2.size(); i++) {
			if (Find(group2[i]) != standard) return 0;
		}
	}
	return 1;
}

int UFGroup1() {
	memcpy(parents, initparents, sizeof(parents));
	for (int i = 0; i < group1.size(); i++) {
		int now = group1[i];
		for (int j = 0; j < near[now].size(); j++) {
			if (group[near[now][j]] != 1) continue;
			Union(now, near[now][j]);
		}
	}

	// 이제 그룹1이 같은그룹인지 확인
	if (isSameGroup(1)) {
		return 1;
	}
	else {
		return 0;
	}
}

int UFGroup2() {
	memcpy(parents, initparents, sizeof(parents));
	for (int i = 0; i < group2.size(); i++) {
		int now = group2[i];
		for (int j = 0; j < near[now].size(); j++) {
			if (group[near[now][j]] != 2) continue;
			Union(now, near[now][j]);
		}
	}

	// 이제 그룹1이 같은그룹인지 확인
	if (isSameGroup(2)) {
		return 1;
	}
	else {
		return 0;
	}
}

void SubTwoGroup() {
	int tot1 = 0;
	int tot2 = 0;
	for (int i = 1; i <= N; i++) {
		if (group[i] == 1) {
			tot1 += People[i];
		}
		else if (group[i] == 2) {
			tot2 += People[i];
		}
	}

	if (abs(tot1 - tot2) < res) {
		res = abs(tot1 - tot2);
	}
}

void dfs(int level, int now) {
	if (level == N) {
		// 최소 한개는 그룹2에 있어야한다.
		if (group2.size() == 0) {
			return;
		}
		int de = -1;
		// 이제 각각 유니온파인드 진행해서 그룹1에있는 것들이 같은 부모를 갖는지, 그룹2에있는것들이 같은 부모를 같는지 확인
		// 둘다 같은 그룹이라면 인구수 차이
		if (UFGroup1() && UFGroup2()) {
			SubTwoGroup();
			flag = 1;
		}

		return;
	}

	for (int i = now+1; i <= N; i++) {
		if (group[i] != 0) continue;
		group[i] = 1;
		group1.push_back(i);
		dfs(level + 1, i);
		group1.pop_back();
		group[i] = 2;
		group2.push_back(i);
		dfs(level + 1, i);
		group2.pop_back();
		group[i] = 0;

	}
}

void solution() {
	// 어차피 두그룹으로 나누기만 하면되니까 1은 무조건 1그룹이라 생각한다.
	group[1] = 1;
	group1.push_back(1);
	dfs(1, 1);

	if (flag) {
		cout << res;
	}
	else {
		cout << -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	input();
	solution();

	return 0;
}