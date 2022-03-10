#include <iostream>
#include <cmath>
using namespace std;
int N, K, MINMAX, diff;

int FINDMIN() {
    for(int i=1; i<24; i++) {
        if(pow(2, i) >= N) return i;
    }
    return 24;
}

int main() {
    cin >> N >> K;
    if(N <= K) {
        cout << K-N;
        return 0;
    }
    else {
        MINMAX = FINDMIN();
        diff = pow(2,MINMAX) - N;
        for(int i=2; i<=K; i++) {
            int sum = 0;
            if(i > MINMAX-1) break;
            for(int j=1; j<=i; j++) {
                sum += pow(2,MINMAX-j);
            }
            if(N <= sum) {
                diff = sum-N;
                MINMAX--;
            }
        }
    }
    cout << diff;
}