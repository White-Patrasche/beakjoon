#include <iostream>
#include <cmath>
using namespace std;
int N, K, Q;

long long dist(long long x, long long y) {
    long long cnt = 0;
    if(K == 1) return abs(x - y);
    while (y != x) {
        if(x > y) {
            x = (x-2)/K+1;
        }
        else {
            y = (y-2)/K+1;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K >> Q;
    for(int i=0; i<Q; i++) {
        long long x, y;
        cin >> x >> y;
        cout << dist(x-1, y-1) << '\n';
    }
}