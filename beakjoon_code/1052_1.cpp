#include <iostream>
using namespace std;
int N, K;
int main() {
    cin >> N >> K;
    for(int i=1; i<=K; i++) {
        int num = 0;
        for(int j=0; j<i; j++) {
            num |= num << 1;
        }
    }
}