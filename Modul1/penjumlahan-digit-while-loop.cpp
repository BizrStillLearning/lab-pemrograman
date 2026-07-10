#include <stdio.h>
#include <stdlib.h>

int main (int n ) {
    n = abs ( n ) ;
    int sum = 0;
    for (; n > 0; n /= 10) {
        sum += n % 10;
    }
    return sum ;
}
