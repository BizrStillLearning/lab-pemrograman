#include <iostream>

void buatKebocoran() {
    int* data = new int[100];
    
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }

    std::cout << "Memori dialokasikan, tapi tidak dibebaskan." << std::endl;
}

int main() {
    buatKebocoran();
    return 0;
}