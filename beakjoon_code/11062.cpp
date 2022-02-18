#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int dp[1000][1000][2];
int card[1000];
int T, N;

int choice(int start, int end, bool knwoo) {
    int &ret = dp[start][end][knwoo];
    if(ret != -1) return ret;
    if(start == end) { //마지막턴
        if(knwoo) return ret = card[start];
        else return ret = 0;
    }

    if(knwoo) 
        return ret = max(choice(start+1, end, false)+card[start], choice(start, end-1, false)+card[end]);
    else 
        return ret = min(choice(start+1, end, true), choice(start, end-1, true));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        cin >> N;
        if(N == 1) {
            int a;
            cin >> a;
            cout << a << '\n';
        }
        else {
            for(int i=0; i<N; i++) {
                cin >> card[i];
            }
            cout << choice(0, N-1, true) << '\n';
        }
    }
}