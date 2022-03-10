#include <iostream>
#define MAX 1000001
using namespace std;
int DP[MAX];
int before[MAX];
int N;
int solve(int x) {
    DP[1] = 0;
    before[1] = -1;
    for(int i=2; i<=x; i++) {
        DP[i] = DP[i-1]+1;
        before[i] = i-1;
        if(i % 2 == 0 && DP[i] > DP[i/2]+1) {
            DP[i] = DP[i/2]+1;
            before[i] = i/2;
        }
        if(i % 3 == 0 && DP[i] > DP[i/3]+1) {
            DP[i] = DP[i/3]+1;
            before[i] = i/3;
        }
    }
    return DP[x];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    cout << solve(N) << '\n';
    while(N != -1) {
        cout << N << ' ';
        N = before[N];
    }
    cout << '\n';
}