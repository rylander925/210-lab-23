// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string name)               { this->name = name; }
    Goat(string name, int age)      { this->name = name; this->age = age; }
    Goat(string name, int age, string color): name(name), age(age), color(color) {}

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // Overloads < operator to sort goats in lexicographic order, prioritizing name > age > color
    bool operator< (const Goat &otherGoat) const {
        if (otherGoat.name == name) {
            if (otherGoat.age == age) {
                //if names and ages are equal, evaluates based on color
                return color < otherGoat.color;
            }
            //if names are equal, evaluates based on age
            return age < otherGoat.age;
        }
        //first evaluate based on name
        return name < otherGoat.name;
    }
};

#endif