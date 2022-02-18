#include <iostream>
using namespace std;
int arr[100001];
int N;
int main() {
	cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int num = arr[N-1];
    int cnt = 1;
    for(int i=N-2; i>=0; i--) {
        if(arr[i] > num) {
            num = arr[i];
            cnt++;
        }
    }
    cout << cnt;
}