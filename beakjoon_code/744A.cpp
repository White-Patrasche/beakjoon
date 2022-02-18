#include <iostream>
#define MAX 100001
using namespace std;
int N;
int arr[MAX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i=2; i<MAX; i++) arr[i] = i;
	for(int i=2; i<MAX; i++) {
		if(arr[i] == 0) continue;
		for(int j=i+i; j<MAX; j+=i) {
			arr[j] = 0;
		}
	}
	
	int before = 2, next = 3;
	while(1) {
		if(before*next >= N+1) {
			cout << before*next;
			break;
		}
		before = next;
		for(int i=next+1;;i++) {
			if(arr[i] != 0) {
				next = i;
				break;
			}
		}
	}
}
