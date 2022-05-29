#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, L;
int Ant[100010];
struct Node{
	int num;
	int place;
};

Node info[100010];
int R_Ant, L_Ant, LCount;

bool comp(Node left, Node right) {
	return left.place < right.place;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> Ant[i];
	}
	
	for (int i = 1; i <= N; i++) {
		if (Ant[i] > 0) {
			R_Ant = max(R_Ant, L - Ant[i]); // R_Ant에는 오른쪽에서 가장 멀리 떨어진애
		}
		else {
			L_Ant = max(L_Ant, abs(Ant[i])); // L_Ant에는 왼쪽에서 가장 멀리 떨어진애
			LCount++;
		}
		info[i] = { i,abs(Ant[i]) };
	}
	sort(info + 1, info + N + 1, comp);

	if (L_Ant < R_Ant) { // 오른쪽에 있는 개미가 더 멀리있다면
		cout << info[LCount + 1].num << " " << R_Ant << endl;
	}
	else {
		cout << info[LCount].num << " " << L_Ant << endl;
	}


	return 0;
}