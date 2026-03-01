#include <iostream>

#include "SparseArrayOptimized.h"

using namespace std;

void print_const(const SparseArrayOptimized &arr) {
    cout << "print_const:\n";
    cout << arr[1] << " " << arr[3] << " " << arr[5] << endl;
    arr[30];
}

int main() {
    SparseArrayOptimized arr;

    cout << arr[1] << " " << arr[3] << " " << arr[5] << endl;

    arr[5] = 27;
    arr[1] = 28;
    arr[3] = 123;

    cout << arr[1] << " " << arr[3] << " " << arr[5] << endl;

    arr[5]++;

    print_const(arr);

    return 0;
}
