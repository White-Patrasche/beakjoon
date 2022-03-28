#include <iostream>
using namespace std;
#define MAX 100001
#define MOD 9901
int DP[MAX][3];
int N;
int main() {
    cin >> N;
    //0 : XX, 1 : OX, 2 : XO
    DP[1][0] = DP[1][1] = DP[1][2] = 1;
    for(int i=2; i<=N; i++) {
        DP[i][0] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2]) % MOD;
        DP[i][1] = (DP[i-1][0] + DP[i-1][2]) % MOD;
        DP[i][2] = (DP[i-1][0] + DP[i-1][1]) % MOD;
    }
    cout << (DP[N][0]+DP[N][1]+DP[N][2]) % MOD;
}