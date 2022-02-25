#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int arr[9];
    int a, b, sum;
    for(int i=0; i<9; i++) cin >> arr[i];
    sort(arr, arr+9);
    for(int i=0; i<8; i++) {
        for(int j=i+1; j<9; j++) {
            a = i, b = j;
            sum = 0;
            for(int k=0; k<9; k++) {
                if(k != a && k != b) sum += arr[k];
            }
            if(sum == 100) break;
        }
        if(sum == 100) break;
    }
    for(int i=0; i<9; i++) 
        if(i != a && i != b)
                cout << arr[i] << '\n';
    return 0;
}