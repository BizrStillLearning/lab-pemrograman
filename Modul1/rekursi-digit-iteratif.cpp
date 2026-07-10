#include <stdio.h>
#include <stdlib.h>

int main(int n) {
    n = abs(n);

    int sum = 0;
    while ( n > 0) {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}