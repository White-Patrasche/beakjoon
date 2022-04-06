#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100001
int V;
vector <pair<int,int>> edge[MAX];
bool went[MAX];
int dist;
int maxDist;
int maxNode;

void DFS(int node, int dist) {
    if(went[node]) return;
    if(dist > maxDist) {
        maxDist = dist;
        maxNode = node;
    }
    went[node] = true;
    for(int i=0; i<edge[node].size(); i++) {
        int nextNode = edge[node][i].first;
        int nextDist = edge[node][i].second;
        DFS(nextNode, dist+nextDist);
    }
}

int main() {
    cin >> V;
    int x, y, z;
    for(int i=1; i<=V; i++) {
        cin >> x;
        while(1) {
            cin >> y;
            if(y == -1) break;
            else cin >> z;
            edge[x].push_back({y, z});
            edge[y].push_back({x, z});
        }
    }
    memset(went, false, sizeof(went));
    DFS(1, 0);
    memset(went, false, sizeof(went));
    maxDist = 0;
    DFS(maxNode, 0);
    
    cout << maxDist;
}