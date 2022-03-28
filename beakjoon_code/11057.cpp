#include <iostream>
using namespace std;
int N;
int DP[1001][10];
int main() {
    cin >> N;
    for(int i=0; i<10; i++) DP[1][i] = 1;
    for(int i = 2; i<=N; i++) {
        for(int j=0; j<10; j++) {
            for(int k=9; k>=j; k--) {
                DP[i][j] += DP[i-1][k];
            }
        }
        for(int j=0; j<10; j++) DP[i][j] %= 10007;
    }
    int sum = 0;
    for(int i=0; i<10; i++) sum += DP[N][i];
    sum %= 10007;
    cout << sum;
}