#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector <int> arr;

void findMiddle() {
	priority_queue <int > max_pq; // 중앙값보다 작을때
	priority_queue <int, vector <int>, greater <int>> min_pq; // 중앙값보다 클때
	int mid = arr[0];
	cout << mid << "\n";

	for (int i = 1; i < n; i++) {
		// 짝수일때
		if (i % 2 == 1) { // 0부터 시작하기 때문
			if (arr[i] < mid) {
				min_pq.push(mid);
				max_pq.push(arr[i]);
			}
			else {
				min_pq.push(arr[i]);
				max_pq.push(mid);
			}
			mid = max_pq.top();
			max_pq.pop();
		}
		// 홀수일때
		else {
			int Temp; // min 힙 혹은 max힙중 개수가 더 많은 곳에서 중앙에 제일 가까운 수
			if (min_pq.size() > max_pq.size()) {
				Temp = min_pq.top();
				min_pq.pop();
			}
			else {
				Temp = max_pq.top();
				max_pq.pop();
			}
			int Numarr[] = { mid, Temp, arr[i] };
			sort(Numarr+0, Numarr+3);
			max_pq.push(Numarr[0]);
			mid = Numarr[1];
			min_pq.push(Numarr[2]);
			
		}
		cout << mid << "\n";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	findMiddle();
	
	
	return 0;
}