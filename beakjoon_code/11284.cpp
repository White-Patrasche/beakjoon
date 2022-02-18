#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	int N;
	string S;
	cin >> N;
	getline(cin, S);
	while(N--) {
		getline(cin, S);
		auto it = find(S.begin(), S.end(), ' ');
		string ans = "god";
		for(auto i = it; i != S.end(); i++) {
			if(*i != ' ') {
				ans += *i;
			}
		}
		cout << ans << '\n';
	}
}
