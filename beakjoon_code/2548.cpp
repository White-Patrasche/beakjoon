#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N;
int main() {
    cin >> N;
    vector<int> vec(N), represent(N);
    for(int i=0; i<N; i++) cin >> vec[i];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            represent[i] += abs(vec[i] - vec[j]);
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> PQ;
    for(int i=0; i<N; i++) PQ.push({represent[i],vec[i]});
    cout << PQ.top().second;

}