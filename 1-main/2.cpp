#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    std::string color; 
    Point* next;
};

double distance(Point* p1, Point* p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

Point* findMinPoint(Point* head) {
    if (head == nullptr) return nullptr;

    Point* minPoint = head;
    Point* current = head->next;

    do {
        if ((current->x < minPoint->x) || (current->x == minPoint->x && current->y < minPoint->y)) {
            minPoint = current;
        }
        current = current->next;
    } while (current != head);

    return minPoint;
}

double calculatePerimeter(Point* head) {
    if (head == nullptr) return 0;

    double perimeter = 0;
    Point* current = head;

    do {
        perimeter += distance(current, current->next);
        current = current->next;
    } while (current != head);

    return perimeter;
}

void printPointColor(Point* point) {
    cout << "Point color: " << point->color << endl;
}

int main() {
    Point p1, p2, p3;

    p1.x = 1; p1.y = 2; p1.color = "Red";
    p2.x = 4; p2.y = 6; p2.color = "Green";
    p3.x = 7; p3.y = 8; p3.color = "Blue";

    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p1;

    Point* current = &p1;
    do {
        cout << "Point: (" << current->x << ", " << current->y << ")" << endl;
        printPointColor(current);
        current = current->next;
    } while (current != &p1);

    Point* minPoint = findMinPoint(&p1);
    if (minPoint != nullptr) {
        cout << "Point with the smallest coordinates: (" << minPoint->x << ", " << minPoint->y << ")" << endl;
        printPointColor(minPoint);
    }

    double perimeter = calculatePerimeter(&p1);
    cout << "Perimeter of the polygon formed by the points: " << perimeter << endl;

    return 0;
}