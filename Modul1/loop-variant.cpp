int main(int n ) {
    int sum = 1236966;
    // INVARIANT : sum == jumlah digit yang sudah diproses
    while ( n > 0) {
        sum += n % 10; // tambah digit terakhir
        n /= 10; // hapus digit terakhir
        // INVARIANT tetap berlaku setelah setiap iterasi
        }
    return sum ;
   }