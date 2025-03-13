#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<int> numbers(10);
    std::ofstream outFile("numbers.txt");

    for (auto& num : numbers) {
        num = rand() % 100;
        outFile << num << std::endl;
    }
    outFile.close();

    std::ifstream inFile("numbers.txt");
    numbers.clear();
    int number;
    while (inFile >> number) {
        numbers.push_back(number);
    }
    inFile.close();

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(numbers.begin(), numbers.end());
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Отсортированные числа:\n";
    for (const int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    std::cout << "Время выполнения: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
        << " мс" << '\n';
}
