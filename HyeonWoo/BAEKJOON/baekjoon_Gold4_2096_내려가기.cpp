#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	// 메모리제한으로 배열 두개를 가지고 입력받을때마다 갱신할 예정임
	int Maxdp[3] = { 0 };
	int Mindp[3] = { 0 };
	int LastMaxdp[3] = { 0 };
	int LastMindp[3] = { 0 };
	for (int i = 1; i <= n; i++) {
		int arr[3];
		// 입력
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}

		// max값 찾기
		Maxdp[0] = max(LastMaxdp[0], LastMaxdp[1])+arr[0];
		Maxdp[1] = max({ LastMaxdp[0], LastMaxdp[1], LastMaxdp[2] }) + arr[1];
		Maxdp[2] = max(LastMaxdp[1], LastMaxdp[2]) + arr[2];

		// min값 찾기
		Mindp[0] = min(LastMindp[0], LastMindp[1]) + arr[0];
		Mindp[1] = min({ LastMindp[0], LastMindp[1], LastMindp[2] }) + arr[1];
		Mindp[2] = min(LastMindp[1], LastMindp[2]) + arr[2];

		// Last값을 현재값으로 갱신
		for (int j = 0; j < 3; j++) {
			LastMaxdp[j] = Maxdp[j];
			LastMindp[j] = Mindp[j];
		}
	}

	cout << max({ Maxdp[0],Maxdp[1],Maxdp[2] }) << " " << min({ Mindp[0],Mindp[1],Mindp[2] });


	

	return 0;
}