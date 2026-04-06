#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;

    int total = 0;

    for (int i = 0; i < n; i++) {
        total += A[i];
    }

    cout << "Total = " << total << endl;

    return 0;
}