#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

char wow[] = { ']',')','}','>' };
char wow2[] = { '[','(','{','<' };

int main() {
	//ifstream is("input.txt");
	for (int t = 1; t < 11; t++) {
		int n;
		string temp;
		vector<char> aa, bb;
		//is >> n;
		//is >> temp;
		cin >> n >> temp;
		
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '[' || temp[i] == '(' || temp[i] == '{' || temp[i] == '<')
				aa.push_back(temp[i]);
			else {
				for (int k = 0; k < 4; k++) {
					if (wow[k] == temp[i]) {
						bb.push_back(wow2[k]);
						break;
					}
				}
			}
		}

		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());


		cout << "#" << t << " ";
		if (aa == bb)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
		
	}
	return 0;
}