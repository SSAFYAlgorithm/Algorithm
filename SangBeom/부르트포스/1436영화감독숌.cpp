#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int a;
	cin >> a;
	
	int cnt = 0;
	int sixsixsix = 0;
	while (1)
	{
		sixsixsix++;
		if (to_string(sixsixsix).find("666") != string::npos) {
			if (++cnt == a) {
				cout << sixsixsix;
				break;
			}
		}
	}


}