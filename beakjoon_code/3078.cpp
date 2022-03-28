#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, K;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    string str;
    queue<int> Q[21];
    long long cnt = 0;
    for(int i=0; i<N; i++) {
        cin >> str;
        int len = str.length();
        while(!Q[len].empty() && i-Q[len].front() > K) {
            Q[len].pop();
        }
        cnt += Q[len].size();
        Q[len].push(i);
    }
    cout << cnt;
}