#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int T;
long long N;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> N;
		if(N%3 == 0) {
			cout << "TAK\n";
			continue;
		}
		vector <long long> solution;
		long long MAX = sqrt(N);
		for(long long i=1; i<=MAX; i++) {
			if(N%i == 0) {
				solution.push_back(i);
				//if(i != N/i) solution.push_back(N/i);
			}
		}
		bool check = false;
		for(auto i=solution.begin(); i!= solution.end(); i++) {
			long long M = *i;
			long long J = N/M;
			if((M+J)%3 == 0) {
				check = true;
				break;
			}
		}
		if(check == true) cout << "TAK\n";
		else cout << "NIE\n";
	}
}
