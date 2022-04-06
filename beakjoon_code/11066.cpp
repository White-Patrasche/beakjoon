#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 501
using namespace std;
int DP[MAX][MAX];
int cost[MAX];
int sum[MAX];
int T, N;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=1; i<=N; i++) {
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        for(int d=1; d<N; d++) {
            for(int tx = 1; tx+d <= N; tx++) {
                int ty = tx + d;
                DP[tx][ty] = INT_MAX;

                for(int mid = tx; mid < ty; mid++) {
                    DP[tx][ty] = min(DP[tx][ty], DP[tx][mid] + DP[mid+1][ty] + sum[ty] - sum[tx-1]);
                }
            }
        }
        cout << DP[1][N] << '\n'; 
    }
    return 0;
}