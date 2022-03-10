#include <iostream>
#include <cstring>
using namespace std;
int N, W, L;
int time = 1;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> W >> L; //트럭 개수, 다리 길이, 최대 다리 하중
    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int sum=0, cur = 0;
    int bridge[W];
    memset(bridge, 0, sizeof(bridge));
    while(1) {
        bool nextCar = false;
        if(cur == N-1 && sum == 0) break;
        if(bridge[N-1] != 0) sum -= bridge[N-1];
        if(cur != N-1 && sum + arr[cur+1] <= L) { //다리 위에 다음 차를 올려도 되는지
            nextCar = true;
        }
        for(int i=N-2; i>=0; i--) bridge[i+1] = bridge[i];
        if(nextCar == true) sum += arr[cur++];
        time++;
    }
    cout << time;
}