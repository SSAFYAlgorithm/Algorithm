#include<iostream>
#include<algorithm>
using namespace std;

void permutation(int depth);
void print();
int num;//���� 3~100
int r = 3;//�����ϴ� ����
int arr[100];
int res[3]; //���
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

	//�迭�� �ִ°����� Ȱ���� 3�� value�� max�� ������
	//���Ȱ��
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
