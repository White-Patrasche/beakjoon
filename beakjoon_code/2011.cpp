#include <iostream>
#include <cstring>
#define MAX 5001
#define MOD 1000000
using namespace std;
int DP[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int len = str.length();
    int arr[MAX];
    for(int i=1; i<=len; i++) {
        arr[i] = str[i-1]-'0';
    }
    if(len == 1 && str[0] == '0') {
        cout << 0 <<'\n';
        return 0;
    }
    DP[0] = 1;
    for(int i=1; i<=len; i++) {
        if(arr[i] >= 1 && arr[i] <= 9) {
            DP[i] = (DP[i-1] + DP[i]) % MOD;
        }
        if(i == 1) continue;
        int temp = arr[i-1] * 10 + arr[i];
        if(temp >= 10 && temp <= 26) {
            DP[i] = (DP[i-2] + DP[i]) % MOD;
        }
    }
    cout << DP[len];
}