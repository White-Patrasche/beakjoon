#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[4];
int main() {
	for(int i=0; i<4; i++) cin >> arr[i];
	sort(arr,arr+4);
	int sum1 = arr[0] + arr[3];
	int sum2 = arr[1] + arr[2];
	cout << abs(sum1-sum2);
}
