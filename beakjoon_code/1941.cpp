#include <iostream>
#include <queue>
#include <vector>
#define MAX 5
using namespace std;
char arr[MAX][MAX];
bool went[MAX][MAX];
pair<int, int> start;
int cnt = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

typedef struct
{
    int x;
    int y;
    int cnt;
    int S;
}PAIR;

bool notBound(int x, int y) {
    if(x >= 0 && x < MAX && y >= 0 && y < MAX) return true;
    else return false;
}

void BFS() {
    queue<PAIR> Q;
    PAIR p;
    p.x = start.first;
    p.y = start.second;
    went[p.x][p.y] = true;
    p.cnt = 1;
    if(arr[p.x][p.y] == 'S') p.S = 1;
    else p.S = 0;
    Q.push(p);
    while(!Q.empty) {
        p.x = Q.front().x;
        p.y = Q.front().y;
        p.cnt = Q.front().cnt;
        p.S = Q.front().S;
        Q.pop();
        if(cnt == 7) {
            if(S >= 4) cnt++;
            continue;
        }
        for(int i=0; i<4; i++) {
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];
            int ncnt = p.cnt+1;
            int nS = p.S;
            if(notBound(nx, ny) && !went[nx][ny]) {
                PAIR PAIRNEW;
                PAIRNEW.x = nx;
                PAIRNEW.y = ny;
                PAIRNEW.cnt = ncnt;
                if(arr[nx][ny] == 'S') PAIRNEW.S = nS+1;
                else PAIRNEW.S = nS;
                Q.push(PAIRNEW);
                went[nx][ny] = true;
            }
        }
    }
}

int main() {
    string str;
    for(int i=0; i<MAX; i++) {
        cin >> str;
        for(int j=0; j<MAX; j++) {
            arr[i][j] = str[j];
            if(arr[i][j] == 'S') {
                start = {i, j};
            }
        }
    }
    BFS();
    cout << cnt;
}