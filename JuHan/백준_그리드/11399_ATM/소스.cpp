#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int person[1001];
	int num_people;

	cin >> num_people;
	for (int i = 0; i < num_people; i++) {
		cin >> person[i];
	}
	sort(person, person + num_people);

	int sum = 0;
	for (int i = 0; i < num_people; i++) {
		sum += person[i] * (num_people - i);
	}

	cout << sum;

	return 0;
}