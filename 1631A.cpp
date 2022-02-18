#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
int N, T;
int arr1[MAX], arr2[MAX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	while(N--) {
		cin >> T;
		for(int i=0; i<T; i++) {
			cin >> arr1[i];
		}
		for(int i=0; i<T; i++) {
			cin >> arr2[i];
		}
		for(int i=0; i<T; i++) {
			if(arr1[i] <= arr2[i]) swap(arr1[i], arr2[i]);
		}
		sort(arr1, arr1+T); sort(arr2, arr2+T);
		cout << arr1[T-1]*arr2[T-1] << '\n';
	}
}
