#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000001
int N, ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> V;
    int temp;
    for(int i=1; i<=N; i++) {
        cin >> temp;
        auto it = lower_bound(V.begin(),V.end(),temp);
        if(it == V.end()) V.push_back(temp);
        else {
            V.insert(it, temp);
            V.erase(V.end());
        }
    }
    cout << V.size() <<'\n';
    for(int i=0; i<V.size(); i++) cout << V[i] << ' ';
}