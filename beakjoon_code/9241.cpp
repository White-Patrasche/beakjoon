#include <iostream>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int start=0, end=s1.length()-1;
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] == s2[i]) start = i;
        else break;
    }
    for(int i=s1.length()-1; i>=0; i--) {
        if(s1[i] == s2[(s2.length()-s2.length())+i]) end = i;
        else break;
    }
    if(start == s1.length() || end == 0) cout << 0 << '\n';
    else cout << end-start-1-(s1.length() - s2.length()) << '\n';
    //cout << end << ' ' << start << ' ' << s1.length() << ' ' << s2.length();
    return 0;
}