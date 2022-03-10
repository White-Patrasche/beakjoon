#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int level, size;

int SORT(int* sorted_input, int i) {
    if(i >= )
}

int main() {
    cin >> level;
    size = pow(2, level);
    int input[size];
    int sorted_input[size];
    int tree[size][size];
    memset(tree, 0, sizeof(tree));
    memset(sorted_input, 0, sizeof(sorted_input));
    for(int i=1; i<size; i++) {
        cin >> input[i];
    }
    for(int i=1; i<size; i++) {
        int cur = SORT(sorted_input, i);
        sorted_input[cur] = input[i];
    }
}