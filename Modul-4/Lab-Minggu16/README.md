# Regional Statistics Explorer

## Deskripsi
Aplikasi *command-line* (CLI) berbasis C++ yang dibangun menggunakan arsitektur *N-Tier*. Aplikasi ini dirancang untuk mengeksplorasi, memfilter, dan menganalisis data statistik regional (Kabupaten/Kota) di Indonesia, dengan penanganan memori dinamis dan *error handling* yang kokoh.

## Fitur Tier 1 (Core)
- **Tampilkan & Filter Data:** Menampilkan seluruh region, mencari berdasarkan potongan nama (*substring search*), dan menyaring data berdasarkan provinsi menggunakan RTTI (`dynamic_cast`).
- **Pengurutan Dasar:** Mengurutkan wilayah berdasarkan alfabet (A-Z).

## Fitur Tier 2 (Advanced & Efisiensi)
1. **Pencarian Biner (Binary Search) via Kode BPS:** Memanfaatkan `std::sort` dan `std::lower_bound` untuk eksekusi pencarian data wilayah yang optimal dengan kompleksitas waktu $O(\log N)$.
2. **Top-K HDI menggunakan Priority Queue:** Menggunakan struktur data Max-Heap (`std::priority_queue`) untuk menyaring dan mengurutkan wilayah dengan Indeks Pembangunan Manusia tertinggi secara dinamis, mengoptimalkan proses komputasi menjadi $O(N \log K)$.

## Fitur Ekstra (Data Analytics)
- **Kalkulasi Rata-rata Kepadatan:** Melakukan agregasi data untuk menghitung rata-rata kepadatan penduduk (jiwa/km²) di provinsi tertentu.
- **Pengurutan Tingkat Kemiskinan:** Mengurutkan dan menampilkan wilayah dengan persentase kemiskinan terendah.

## Cara Kompilasi dan Eksekusi (Build and Run)
Proyek ini dikonfigurasi menggunakan sistem build **CMake** dan memerlukan standar C++17.

**Menggunakan IDE (CLion/Visual Studio):**
1. Buka folder proyek.
2. Pastikan file `CMakeLists.txt` telah dimuat.
3. Konfigurasikan *Working Directory* agar mengarah ke root proyek, sehingga file `data/regions.csv` dapat terbaca.
4. Lakukan *Build and Run*.

**Menggunakan Terminal / MinGW:**
```bash
g++ -std=c++17 main.cpp Database.cpp -o Lab-Minggu16
./RegionalExplorer