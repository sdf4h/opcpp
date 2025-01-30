#include <iostream>
using namespace std;
struct Person {
    char gender;   
    int age;       
    float gpa;    
};
int main() {
    Person person;

    person.gender = 'M';
    person.age = 21;
    person.gpa = 4.5;
    cout<< (sizeof person) << endl;
    size_t sizePerson = sizeof(char) + sizeof(int) + sizeof(float);
    cout << sizePerson << endl;
    size_t gensize = sizeof(char);
    size_t agesize = sizeof(int);
    size_t gpasize = sizeof(float);
    cout << "info:" << gpasize << "," << gensize << "," << agesize;
}