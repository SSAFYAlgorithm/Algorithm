#include<iostream>
#include<algorithm>
using namespace std;

void permutation(int depth);
void print();
int num;//개수 3~100
int r = 3;//선택하는 개수
int arr[100];
int res[3]; //결과
int check[100] = { 0, }; //flag
int MAX;	//10~300000
int aa;
int MIN = 100000;
int val = 0;
int main()
{
	cin >> num >> MAX;


	for (int i = 0;i < num;i++) {
		cin >> arr[i];
	}

	//배열에 있는값들을 활용해 3개 value로 max에 가깝게
	//재귀활용
	permutation(0);

	if (val != 0) cout << val;
	else cout << MAX - MIN;

}
void permutation(int depth)
{
	if (depth == r) {
		print();
		return;
	}

	for (int i = 0;i < num;i++) {
		if (!check[i]) {
			check[i] = true;
			res[depth] = arr[i];
			permutation(depth + 1);
			check[i] = false;
		}
	}

}
void print()
{
	int sum = 0;
	int max = 0;

	for (int i = 0;i < r;i++) {
		sum += res[i];

		if (max <= sum) max = sum;
	}


	if (MAX - sum == 0) {
		val = sum;
	}
	else {

		aa = MAX - sum;
		if (aa > 0) {
			if (MIN > aa)
			{
				MIN = aa;

			}
		}
	}


}
