# include <iostream>
using namespace std ;

int sumDigits (int n ) {
    if ( n == 0) // basis : tidak ada digit tersisa
        return 0;

    int lastDigit = n % 10;
    int remaining = n / 10;

    // kasus rekursif : digit terakhir + jumlah digit sisanya
    return lastDigit + sumDigits ( remaining ) ;
}

int main () {
    int num = 1234;
    cout << " Jumlah digit dari " << num << " adalah " <<
    sumDigits ( num ) << endl ;
    return 0;
    }
// Jejak Eksekusi untuk 1234:
// 4 + sumDigits (123)
// 4 + (3 + sumDigits (12) )
// 4 + (3 + (2 + sumDigits (1)))
// 4 + (3 + (2 + (1 + sumDigits (0))))
// 4 + 3 + 2 + 1 + 0 = 10