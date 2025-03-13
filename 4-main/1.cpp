#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

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

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<int> arr(1000);
    for (int& num : arr) {
        num = rand() % 10000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " мс" << '\n';

}
