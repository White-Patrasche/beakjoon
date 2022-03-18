#include <iostream>
using namespace std;
#define MAX 1000001
#define MOD 15746
int N;
int DP[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    DP[0] = 1;
    DP[1] = 1;
    for(int i=2; i<=N; i++) {
        DP[i] = (DP[i-1]%MOD + DP[i-2]%MOD)%MOD;
    }
    cout << DP[N];
}