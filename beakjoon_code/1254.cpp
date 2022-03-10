#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

string str;

int pal(int start, int len) {
    for(int i=0; i<(len/2)-start; i++) {
        if(str[start+i] != str[len-1-i]) return 0;
    }
    return len;
}

int main() {
    int ans = 102;
    cin >> str;
    int len = str.length();
    if(pal(0, len)) {
        cout << len;
        return 0;
    }
    for(int i=1; i<len; i++) {
        int palen = pal(i, len);
        if(palen) {
            cout << len*2-palen;
            return 0;
        }
    }
    cout << len*2-1;
}