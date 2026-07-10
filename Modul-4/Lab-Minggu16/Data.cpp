#include <iostream>

using namespace std;

class DataSurabaya {
private:
    int nik;
    int pengeluaran;
    int pemasukan;
    int saldo;


public:
    DataSurabaya(int nk, int pg, int pm, int sd) {
        nik = nk;
        pengeluaran = pg;
        pemasukan = pm;
        saldo = sd;
    }

    void tampilkan() {
        cout << "nik: " << nik << endl;
        cout << "pengeluaran: " << pengeluaran << endl;
        cout << "pemasukan: " << pemasukan << endl;
        cout << "saldo : " << saldo << endl;
    }

    void layakBantuan() {
        if (pemasukan <= 2000000 && pengeluaran > 1000000 &&  saldo <= 1000000) {
            cout << "Layak menerima bantuan" << endl;
        }
        else {
            cout << "Tidak layak menerima bantuan" << endl;
        }
    }
};

int main() {
    DataSurabaya w1(01, 300000, 4000000, 500);
    DataSurabaya w2(02, 30000000, 50000000, 6000000);

    w1.tampilkan();
    w1.layakBantuan();
    w2.tampilkan();
    w2.layakBantuan();

    return 0;
}