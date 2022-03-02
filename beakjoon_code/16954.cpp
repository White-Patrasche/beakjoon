#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 8
char mat[MAX][MAX]; //크기는 8x8
//대각선으로도 움직일수 있음
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1, 0};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1, 0};
bool went[MAX][MAX];
bool theend = false;
queue< pair<int, int> > Q;

bool notBound(int x, int y) { //입력이 넘어가는 경우
    if(x >= 0 && x < MAX && y >= 0 && y < MAX) return true;
    else return false;
}

void move() {
    for(int i=MAX-2; i>=0; i--) { 
        for(int j=0; j<MAX; j++) {
            mat[i+1][j] = mat[i][j];
        }
    }
    for(int i=0; i<MAX; i++) mat[0][i] = '.';
}

void BFS() {
    int x, y;
    int size = Q.size();
    memset(went, 0, sizeof(went));
    while(size--) { //이 큐에 들어있는 수만큼 움직임
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        if(mat[x][y] == '#') continue;
        for(int i=0; i<9; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(notBound(nx, ny) && !went[nx][ny]) {
                if(mat[nx][ny] != '#') {
                    Q.push({nx, ny});
                    went[nx][ny] = true;
                }
            }
        }
    }
    if(Q.empty()) theend = true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(); cout.tie(0);
    for(int i=0; i<MAX; i++) {
        string temp;
        cin >> temp; //string형으로 받아서 mat 2차원 char 배열에 넣어줌
        for(int j=0; j<temp.length(); j++) {
            mat[i][j] = temp[j];
        }
    }
    Q.push({7, 0}); //맨 처음 위치 왼쪽 밑
    int cnt = 0;
    while(1) {
        if(cnt >= 8 || theend == true) break;
        BFS(); //BFS는 내가 움직일수 있는것들 큐로 돌림
        move(); //move는 한칸씩 내려오는거 
        cnt++;
    }
    if(theend == false) cout << 1; //그래서 이게 8번 이상만 살아남을수 있으면 모든 벽이 내려온거니까 갈수 있다고 생각
    else cout << 0; //이외에는 먼저 터진거니까 못감
}
