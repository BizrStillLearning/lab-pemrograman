#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> original = {64, 25, 12, 22, 11};

    std::vector<int> arr1 = original;
    bubbleSort(arr1);
    std::cout << "Bubble Sort   : "; printArray(arr1);

    std::vector<int> arr2 = original;
    selectionSort(arr2);
    std::cout << "Selection Sort: "; printArray(arr2);

    std::vector<int> arr3 = original;
    insertionSort(arr3);
    std::cout << "Insertion Sort: "; printArray(arr3);

    return 0;
}