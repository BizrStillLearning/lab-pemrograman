#include <iostream>
using namespace std;

void solve(int caseNum, int n) {
    long long result = (long long)n * n; // Contoh logika
    cout << "Case #" << caseNum << ": " << result << endl;
}

int main() {
    // Optimasi I/O untuk mencegah TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, caseCount = 1;
    while (cin >> n && n != 0) {
        solve(caseCount, n);
        caseCount++;
    }
    return 0;
}