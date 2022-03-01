#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 101

int N, M, cnt=0;
int mat[MAX][MAX];
bool went[MAX][MAX];
int cal[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

/*
void Print(int MAT[MAX][MAX]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << MAT[i][j] << ' ';
        }
        cout << '\n';
    }
}
*/

bool notBound(int x, int y) {
    if(x >= 0 && x < N && y >= 0 && y < M) return true;
    else return false;
}

void BFS() {
    int x, y;
    queue <pair<int, int>> Q;
    Q.push({0, 0});
    while(!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        if(went[x][y]) continue;
        went[x][y] = true;
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(notBound(nx, ny)) {
                if(mat[nx][ny] == 1) cal[nx][ny]++;
                else if(!went[nx][ny]) Q.push({nx, ny});
            }
        }
    }
}

bool melting() {
    bool ismelt = false;
    for(int i=1; i<N-1; i++) {
        for(int j=1; j<M-1; j++) {
            if(cal[i][j] >= 2) {
                mat[i][j] = 0;
                ismelt = true;
            }
        }
    }
    return ismelt;
}

int main() {
    ios::sync_with_stdio(false); //cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> mat[i][j];
        }
    }
    while(1) {
        memset(cal, 0, sizeof(cal));
        memset(went, 0, sizeof(went));
        BFS(); //외부 공기들로 cal에 외부와 맞닿는 치즈들 체크
        bool melt = melting();
        if(melt) cnt++;
        else break;
    }
    cout << cnt;
}