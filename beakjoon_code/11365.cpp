#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	while(1) {
		string str;
		getline(cin, str);
		if(str == "END") break;
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}
