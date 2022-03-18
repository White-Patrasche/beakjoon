#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2001
using namespace std;

vector<int> vec[MAX];
vector<bool> went;
int N, M;
bool ans = false;

void DFS(int cnt, int cur) {
    if(cnt == 4) {
        ans = true;
        return;
    }
    went[cur] = true;
    for(int next : vec[cur]) {
        if(!went[next]) 
            DFS(cnt+1, next);
        if(ans) return;
    }
    went[cur] = false;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);    
    cin >> N >> M;
    went.resize(N);

    int x, y;
    for(int i=0; i<M; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=0; i<N; i++) {
        fill(went.begin(), went.end(), false);
        DFS(0, i);
        if(ans) {
            cout << 1;
            return 0;
        }
    }
    cout << 1;
    return 0;
}