#include <iostream>
#include <queue>
#define MAX 201
using namespace std;
int N, K, S, X, Y;
int mat[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool notBound(int x, int y) {
    if(x >= 1 && x <= N && y >= 1 && y <= N) return true;
    else return false;
}

void BFS(queue<pair<int, int>> *Q) {
    for(int i=1; i<=K; i++) {
        int size = Q[i].size();
        for(int j=0; j<size; j++) {
            bool isInside = false;
            int x = Q[i].front().first;
            int y = Q[i].front().second;
            Q[i].pop();
            for(int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(notBound(nx, ny) && mat[nx][ny] == 0) {
                    isInside = true;
                    Q[i].push({nx, ny});
                    mat[nx][ny] = mat[x][y];
                }
            }
            if(isInside) Q[i].push({x, y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    queue<pair<int, int>> Q[K+1];
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> mat[i][j];
            if(mat[i][j] != 0) Q[mat[i][j]].push({i, j});
        }
    }
    
    cin >> S >> X >> Y;
    while(S--) {
        BFS(Q);
    }
    cout << mat[X][Y];
}