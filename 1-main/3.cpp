#include <iostream>
using namespace std;

struct person {
    int age;
    string name;
    float bal;
    string facultet;
};

struct City {
    string cityName;
    string countryName;
    int population;
};

struct Universion {
    string unoversionName;
    City city;
    person Student[3];
};

int main() {
    
    person student1 = {12, "Dan", 2.3, "Programist"};
    person student2 = {13, "Anton", 3.5, "Developer"};
    person student3 = {14, "Kamil", 5.0, "Krutoi"};


    City kazan = {"Kazan", "Russia", 10000};

    
    Universion kai = {"KFU",kazan,{student1, student2, student3}};


    cout << "University: " << kai.unoversionName << endl;
    cout << "Location: " << kai.city.cityName << ", " << kai.city.countryName << endl;
    cout << "Population: " << kai.city.population << endl;
    cout << "Students: ";

    cout << kai.Student[0].name << ", Age: " << kai.Student[0].age 
         << ", info: " << kai.Student[0].bal 
         << ", Facultet: " << kai.Student[0].facultet << "] ";

    cout << kai.Student[1].name << ", Age: " << kai.Student[1].age 
         << ", info " << kai.Student[1].bal 
         << ", Facultet: " << kai.Student[1].facultet << "] ";

    cout << kai.Student[2].name << ", Age: " << kai.Student[2].age 
         << ", info: " << kai.Student[2].bal 
         << ", Facultet: " << kai.Student[2].facultet << "] ";

    cout << endl;

    return 0;
}