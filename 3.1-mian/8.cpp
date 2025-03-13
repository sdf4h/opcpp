
#include <iostream>

struct Rectangle {
    double width;
    double height;

    // Конструктор для удобства
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const { return width * height; }
};

template <typename T>
double sum_array(T arr[], int size) {
    double total_area = 0.0;
    for (int i = 0; i < size; ++i) {
        total_area += arr[i].area();  // Предполагается, что у T есть метод area()
    }
    return total_area;
}

// Специализация для Rectangle
template <>
double sum_array<Rectangle>(Rectangle arr[], int size) {
    double total_area = 0.0;
    for (int i = 0; i < size; ++i) {
        total_area += arr[i].area(); // Используем метод area()
    }
    return total_area;
}

int main() {
    Rectangle rectangles[] = {Rectangle(5.0, 2.0), Rectangle(3.0, 4.0), Rectangle(2.0, 2.0)};
    int rectSize = sizeof(rectangles) / sizeof(rectangles[0]);

    double totalArea = sum_array(rectangles, rectSize);
    std::cout << "Общая площадь: " << totalArea << std::endl; // Выведет 32

    // Пример для int (чтобы показать, что общий шаблон работает)
    int intArray[] = {1, 2, 3};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    // Здесь нужно что-то, что можно "сложить" с int.  Просто складываем сами числа:
    auto sum_int_array = [](int arr[], int size) {
        int sum = 0;
        for(int i = 0; i < size; ++i) sum += arr[i];
        return sum;
    };
    std::cout << "Сумма целых чисел: " << sum_int_array(intArray, intSize) << std::endl; // Выведет 6

    return 0;
}
