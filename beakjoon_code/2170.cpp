#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    int x, y;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        PQ.push({x,y});
    }
    int size = 0;
    x = PQ.top().first;
    y = PQ.top().second;
    int newsize = y-x;
    PQ.pop();

    for(int i=1; i<N; i++) {
        int nx = PQ.top().first;
        int ny = PQ.top().second;
        if(nx > y) { //겹치지 않음
            size += newsize;
            x = nx;
            y = ny;
            newsize = ny-nx;
        }
        else { //겹침
            y = max(y, ny);
            newsize = y-x;
        }
        PQ.pop();
    }
    size += newsize;
    cout << size;
}