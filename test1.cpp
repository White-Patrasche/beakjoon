#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int sum=0, MAX = 0;
    for(int i=0; i<4; i++) {
        int x, y;
        cin >> x >> y;
        sum = sum - x;
        sum = sum + y;
        MAX = max(MAX, sum);
    }
    cout << MAX;
}
