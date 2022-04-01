#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#define INF 987654321
#define MAX 21
#define PAIR pair<int,pair<int, int>>
using namespace std;

int N, M, K;
int nowX, nowY;
int MAP[MAX][MAX];
map<pair<int,int>, pair<int,int>> client;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool notBound(int x, int y) {
    if(x >= 0 && x < N && y >= 0 && y < N) return true;
    else return false;
}

PAIR dijk() {
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> PQ;
    PQ.push({0, {nowX, nowY}});
    bool went[MAX][MAX];
    memset(went, 0, sizeof(went));
    went[nowX][nowY] = true;
    PAIR dest = {0, {0, 0}};
    while(!PQ.empty()) {
        int cnt = PQ.top().first;
        int x = PQ.top().second.first;
        int y = PQ.top().second.second;
        PQ.pop();
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(notBound(nx, ny) && !went[nx][ny]) {
                if(MAP[nx][ny] == 1) continue;
                else if(MAP[nx][ny] == 2) {
                    MAP[nx][ny] = 0;
                    if();
                }
                else if(MAP[nx][ny] == 0) {
                    PQ.push({cnt+1, {nx, ny}});
                    went[nx][ny] = true;
                }
            }
        }
    }
    return {INF, {INF, INF}};
}

int go(PAIR ride) {
    int destX = client[{ride.second.first, ride.second.second}].first;
    int destY = client[{ride.second.first, ride.second.second}].second;
    nowX = destX;
    nowY = destY;
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> PQ;
    PQ.push({0, {ride.second.first, ride.second.second}});
    bool went[MAX][MAX];
    memset(went, 0, sizeof(went));
    went[ride.second.first][ride.second.second] = true;
    while(!PQ.empty()) {
        int cnt = PQ.top().first;
        int x = PQ.top().second.first;
        int y = PQ.top().second.second;
        PQ.pop();
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(notBound(nx, ny) && !went[nx][ny]) {
                if(nx == destX && ny == destY) {
                    while(!PQ.empty()) PQ.pop();
                    return cnt+1;
                }
                if(MAP[nx][ny] == 1) continue;
                else if(MAP[nx][ny] == 0 || MAP[nx][ny] == 2) {
                    PQ.push({cnt+1, {nx, ny}});
                    went[nx][ny] = true;
                }
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> MAP[i][j];
        }
    }
    cin >> nowX >> nowY;
    for(int i=0; i<M; i++) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        w--;
        x--;
        y--;
        z--;
        client[{w, x}] = {y, z};
        MAP[w][x] = 2;
    }
    bool flag = true;
    for(int i=0; i<M; i++) {
        PAIR ride = dijk();
        if(ride.first > K) {
            flag = false;
            break;
        }
        K -= ride.first;
        int fuel = 0;
        if((fuel = go(ride)) > K) {
            flag = false;
            break;
        }
        K += fuel;
    }
    if(!flag) cout << -1;
    else cout << K;
    return 0;
}