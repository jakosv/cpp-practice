#include <iostream>

#include "SparseArray.h"

using namespace std;

void print_const(const SparseArray &arr) {
    cout << "print_const:\n";
    cout << arr[1] << " " << arr[3] << " " << arr[5] << endl;
    arr[30];
}

int main() {
    SparseArray arr;

    cout << arr[1] << " " << arr[3] << " " << arr[5] << endl;

    arr[5] = 27;
    arr[1] = 28;
    arr[3] = 123;

    cout << arr[1] << " " << arr[3] << " " << arr[5] << endl;

    arr[5]++;

    print_const(arr);

    return 0;
}
