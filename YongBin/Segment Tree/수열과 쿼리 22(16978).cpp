#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[100001];
vector<long long> tree(400004);
long long ans[100001];
int n, m, a, b, c, d;

typedef struct sum {
	int a, b, c, d;
}sum;

typedef struct up {
	int a, b;
}up;

vector<sum> sumVec;
vector<up> upVec;

long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long query(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int node, int index, long long num) {
	if (index > end || index < start)
		return;
	tree[node] += num;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, num);
	update(mid + 1, end, node * 2 + 1, index, num);
}

bool cmp(sum a, sum b) {
	return a.b < b.b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sumNum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			upVec.push_back({ b - 1, c });
		}
		else {
			cin >> b >> c >> d;
			sumVec.push_back({ (int)sumVec.size(), b, c - 1,d - 1 });
			sumNum++;
		}
	}
	sort(sumVec.begin(), sumVec.end(), cmp);

	for (int i = 0, j = 0; i < sumVec.size(); i++) {
		while (j < sumVec[i].b) {
			update(0, n - 1, 1, upVec[j].a, upVec[j].b - arr[upVec[j].a]);
			arr[upVec[j].a] = upVec[j].b;
			j++;
		}
		ans[sumVec[i].a] = query(0, n - 1, sumVec[i].c, sumVec[i].d, 1);
	}

	for (int i = 0; i < sumNum; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}