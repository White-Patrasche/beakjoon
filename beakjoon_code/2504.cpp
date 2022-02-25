#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    stack <char> S;
    cin >> str;

    long long result = 0;
    int temp = 1;
    bool impossible = false;

    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') {
            temp *= 2;
            S.push('(');
        }
        else if(str[i] == '[') {
            temp *= 3;
            S.push('[');
        }

        else if(str[i] == ')' && (S.empty() || S.top() != '(')) {
            impossible = true;
            break;
        }
        else if(str[i] == ']' && (S.empty() || S.top() != '[')) {
            impossible = true;
            break;
        }

        else if(str[i] == ')') {
            if(str[i-1] == '(') 
                result += temp;
            S.pop();
            temp /= 2;
        }
        else if(str[i] == ']') {
            if(str[i-1] == '[')
                result += temp;
            S.pop();
            temp /= 3;
        }
    } 
    if(impossible || !S.empty()) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}