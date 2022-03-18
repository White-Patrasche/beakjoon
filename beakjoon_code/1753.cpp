#include <iostream>
#include <queue>
#include <vector>
#define INF 0xffff
using namespace std;
int V, E, S;
vector<int> dist;
void dijk(vector< pair<int, int> > *graph) {
	priority_queue<pair<int, int>, vector <pair<int,int> >, greater< pair<int,int> > > PQ;
	dist[S] = 0;
	PQ.push({0, S});
	while(!PQ.empty()) {
		 int cur = PQ.top().second;
		 int dis = PQ.top().first;
		 PQ.pop();
		 if(dist[cur] < dis) continue;
		 for(int i=0; i<graph[cur].size(); i++) {
		 	int next = graph[cur][i].first;
		 	int nextDist = dis + graph[cur][i].second;
		 	if(nextDist < dist[next]) {
		 		dist[cur] = nextDist;
		 		PQ.push({nextDist, next});
			 }
		 }
	}
}

int main() {
	cin >> V >> E;
	cin >> S;
	int x, y, z;
	dist = vector<int> (V+1, INF);
	vector < pair<int, int> > graph[V+1];
	for(int i=0; i<E; i++) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
	}
	dijk(graph);
	for(int i=1; i<=V; i++) cout << dist[i] << '\n';
}
