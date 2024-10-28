#include "Student.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Default Student constructor
Student::Student() : name("Unknown"), IdNumber(0), major("Undeclared"), gpa(0.0), gradeLevel("Unknown") {}

// Fully qualified Student constructor
Student::Student(const string& n, int id, const string& m, double g, const string& grade) {
    setName(n);            // use setName to validate data
    setIdNumber(id);
    setMajor(m);          // use setMajor to validate data
    setGpa(g);             // use setGpa to validate data
    setGradeLevel(grade);  // use setGradeLevel to validate data
}

// Mutators and accessors
void Student::setName(const string& n) {
    if (!n.empty() && isupper(n[0])) // Ensure the first character is uppercase
        name = n;
    else
        name = "Unknown"; // Default value for bad name
}

string Student::getName() const {
    return name;
}

void Student::setIdNumber(int id) {
    if (id > 1 && id < 100000) // must be from 0 to 100000 (Valid ID range)
        IdNumber = id;
    else
        IdNumber = -1; // Indicates invalid ID (using -1 for clarity)
}

int Student::getIdNumber() const {
    return IdNumber;
}

void Student::setMajor(const string& m) {
    major = m; // No validation for major, you can add it if necessary
}

string Student::getMajor() const {
    return major;
}

void Student::setGpa(double g) {
    if (g >= 0.0 && g <= 4.0) { // Valid GPA range
        gpa = g;
    } else {
        gpa = -1; // Use -1 to indicate invalid GPA
        cout << name << ": GPA must be between 0.0 and 4.0" << endl;
    }
}

double Student::getGpa() const {
    return gpa;
}

void Student::setGradeLevel(const string& grade) {
    gradeLevel = grade;
}

string Student::getGradeLevel() const {
    return gradeLevel;
}
