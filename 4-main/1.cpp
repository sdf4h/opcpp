#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;

    std::cout << "Введите имя файла (с расширением, например, 'output.txt'): ";
    std::getline(std::cin, fileName);
    std::ofstream outFile(fileName);

    for (int i = 0; i < 5; ++i) {
        std::string line;
        std::cout << "Введите строку " << (i + 1) << ": ";
        std::getline(std::cin, line);
        outFile << line << std::endl; 
    }

}