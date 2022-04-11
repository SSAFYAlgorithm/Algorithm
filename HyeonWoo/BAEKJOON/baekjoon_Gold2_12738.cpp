#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000000];
vector <int> v;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (v.size() == 0 || v[v.size() - 1] < arr[i]) v.push_back(arr[i]);
		else {
			// 이분탐색 후에 재배치해줄 것
			// 현재 arr[i]의 값을 무조건 v에 배치해 줄 것이다.
			// 예를들어서 10 20 60 10 20 30 40 50 이라 가정할경우 arr[i]가 30일때 
			// v의 상태는 {10, 20, 60} 의 상태
			// 이분탐색으로 30이 들어갈 수 있는 위치를 파악
			// 이분탐색 끝나면 left는 2를 가리킬것 -> 해당 인덱스의 값을 현재 arr[i]의 값으로 바꿔준다.
			// 만약 같은값이 있다면 덧씌워준다 => 현재 vector값에는 변화 없다.
			int left = 0;
			int right = v.size() - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (v[mid] >= arr[i]) right = mid;
				else left = mid + 1;
			}
			v[left] = arr[i];
		}
	}
	cout << v.size() << endl;


	return 0;
}