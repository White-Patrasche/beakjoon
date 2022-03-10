#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N;
    int x1, x2, y1, y2;
    bool able = false; //가능 여부
    cin >> x1 >> y1 >> x2 >> y2;
    int diffx, diffy;
    if(x1 == x2 && y1 == y2) {
        cout << 0;
        return 0;
    }
    else {
        diffx = abs(x1 - x2)/2;
        diffy = abs(y1 - y2)/2;
        if((diffx % 2 == 0) && (diffy % 2 == 0)) able = true;
    }
    if(able == false) {
        cout << -1;
        return 0;
    }
    int move = 0;
    move += diffx;
    move += (diffy/2)-diffx;
    cout << move;
}