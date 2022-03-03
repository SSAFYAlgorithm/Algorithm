#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
	vector<int> vec1; // 양수
	vector<int> vec2; // 음수
	int flag = 0; //0 개수
	int flag2 = 0; //1 개수
	int sum = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 1)
			vec1.push_back(a);
		else if (a < 0)
			vec2.push_back(a);
		else if (a == 0)
			flag++;
		else if (a == 1)
			flag2++;
	}

	sort(vec1.begin(), vec1.end(), greater<int>());
	sort(vec2.begin(), vec2.end());

	if (vec1.size() % 2 == 0) {
		for (int i = 0; i < vec1.size(); i += 2) {
			sum += vec1[i] * vec1[i + 1];
		}
	}
	else {
		for (int i = 0; i < vec1.size() - 1; i += 2) {
			sum += vec1[i] * vec1[i + 1];
		}
		sum += vec1[vec1.size() - 1];
	}

	if (vec2.size() % 2 == 0) {
		for (int i = 0; i < vec2.size(); i += 2) {
			sum += vec2[i] * vec2[i + 1];
		}
	}
	else {
		for (int i = 0; i < vec2.size() - 1; i += 2) {
			sum += vec2[i] * vec2[i + 1];
		}
		if (flag == 0) {
			sum += vec2[vec2.size() - 1];
		}
	}

	cout << sum + flag2;
	return 0;
}