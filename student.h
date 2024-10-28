#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    int IdNumber;
    string major;
    double gpa;
    string gradeLevel;

public:
    // Constructors
    Student();
    Student(const string& n, int id, const string& m, double g, const string& grade);

    // Mutators and accessors
    void setName(const string& n);
    string getName() const;
    void setIdNumber(int id);
    int getIdNumber() const;
    void setMajor(const string& m);
    string getMajor() const;
    void setGpa(double g);
    double getGpa() const;
    void setGradeLevel(const string& grade);
    string getGradeLevel() const;
};

#endif // STUDENT_H
