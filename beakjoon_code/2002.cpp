#include <iostream>
#include <string>
#include <map>
using namespace std;
int N, cnt = 0;
int arr[1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map <string, int> M;
    string str;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> str;
        M[str] = i;
    }
    for(int i=0; i<N; i++) {
        cin >> str;
        arr[i] = M[str];
    }
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(arr[i] > arr[j]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}