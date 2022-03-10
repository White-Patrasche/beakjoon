#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int N, M, K, ans;
int matrix[MAX][MAX];
bool went[MAX][MAX];

bool notBound(int x, int y) {
    if(x >= 0 && x < N && y >= 0 && y < M) return true;
    else return false;
}

void BFS(int x, int y) {
    int cnt=1;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    went[x][y] = true;
    while(!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(notBound(nx,ny) && !went[nx][ny] && matrix[nx][ny] == 1) {
                cnt++;
                Q.push({nx, ny});
                went[nx][ny] = true;
            }
        }
    }
    if(cnt > ans) ans = cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<K; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x-1][y-1] = 1;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(matrix[i][j] == 1 && !went[i][j]) {
                BFS(i, j);
            }
        }
    }
    cout << ans;
}