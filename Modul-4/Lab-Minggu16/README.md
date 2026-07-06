# Regional Statistics Explorer

## Deskripsi
Aplikasi *command-line* (CLI) berbasis C++ yang dibangun menggunakan arsitektur *N-Tier*. Aplikasi ini dirancang untuk mengeksplorasi, memfilter, dan menganalisis data statistik regional (Kabupaten/Kota) di Indonesia.

## Fitur Tier 2 yang Diimplementasikan
1. **Pencarian Biner (Binary Search) Berdasarkan Kode:** Menggunakan `std::sort` dan algoritma `std::lower_bound` untuk pencarian data wilayah yang efisien secara asimtotik dengan kompleksitas waktu $O(\log N)$.
2. **Top-K HDI Menggunakan Priority Queue:** Memanfaatkan struktur data Max-Heap (`std::priority_queue`) untuk menyaring dan mengurutkan wilayah dengan Indeks Pembangunan Manusia (HDI) tertinggi di provinsi tertentu, meningkatkan efisiensi proses dari $O(N \log N)$ menjadi $O(N \log K)$.

## Cara Kompilasi dan Eksekusi (Build and Run)
Proyek ini dikonfigurasi menggunakan sistem **CMake**.

**Menggunakan CLion (Direkomendasikan):**
1. Buka folder proyek di CLion.
2. Pastikan file `CMakeLists.txt` telah dimuat (Klik Kanan -> *Reload CMake Project*).
3. Pastikan folder `data/` (berisi `regions.csv`) berada di dalam direktori `cmake-build-debug`, atau perbarui konfigurasi *Working Directory* pada *Run Configuration* agar mengarah ke *root* proyek.
4. Eksekusi program menggunakan *shortcut* `Shift + F10`.

**Menggunakan Terminal / PowerShell (MinGW):**
```bash
mkdir build
cd build
cmake ..
cmake --build .
./Lab-Minggu16