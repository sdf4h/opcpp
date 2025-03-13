
#include <iostream>

template <typename T>
T findMax(T arr[], int size) {
    if (size <= 0) {

        return T{}; // Возвращаем значение по умолчанию для типа T (обычно 0 для чисел)
    }

    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int intArray[] = {1, 5, 2, 8, 3};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Max int: " << findMax(intArray, intSize) << std::endl;

    double doubleArray[] = {1.5, 2.7, 0.9, 4.2};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Max double: " << findMax(doubleArray, doubleSize) << std::endl;

    return 0;
}
