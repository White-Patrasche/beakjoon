#include <iostream>
#include <algorithm>
using namespace std;
int K, N, M;
int main() {
	cin >> K >> N >> M;
	int sum = K*N;
	cout << max(sum-M, 0);
}
