#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
int N, ans;
int arr[MAX];
int DP[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        int here = 0;
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j])
                here = max(here, DP[j]);
        }
        DP[i] = here+1;
        ans = max(DP[i], ans);
    }
    cout << ans;
}