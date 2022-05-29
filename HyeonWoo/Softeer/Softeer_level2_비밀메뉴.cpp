#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int M, N, K;
string Secret;
string command;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> M >> N >> K;

	for (int i = 0; i < M; i++) {
		int SecNum;
		cin >> SecNum;
		Secret.append(to_string(SecNum));
	}

	for (int i = 0; i < N; i++) {
		int Num;
		cin >> Num;
		command.append(to_string(Num));
	}

	if (command.find(Secret) == -1) {
		cout << "normal\n";
	}
	else {
		cout << "secret\n";
	}

	int de = -1;

	return 0;

}