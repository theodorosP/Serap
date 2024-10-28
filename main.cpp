#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Define an array of students
Student CIS054[] = {
    Student("Joe Williams", 44536, "CIS", 3.4, "Sophomore"),
    Student("Sally Washington", 55458, "Math", 3.7, "Junior"),
    Student("Fred MacIntosh", 66587, "English", 2.9, "Freshman"),
    Student("Jose De La Cruz", 67892, "Biology", -1.0, "Senior"), // Illegal GPA
    Student("Dan McElroy", 77777, "CIS", 4.5, "Senior"), // Illegal GPA
    Student("Thinh Nguyen", 73657, "Engineering", 3.6, "Junior"),
    Student("Anna Bell", 100000, "History", 3.2, "Freshman"), // Illegal ID
    Student("Mike Johnson", -5, "Chemistry", 2.8, "Sophomore") // Illegal ID
};

// Define number of students
const int NumberOfStudents = sizeof(CIS054) / sizeof(CIS054[0]);

int main() {
    // Display formatted header
    cout << left << setw(15) << "ID Number"
         << setw(25) << "Name"
         << setw(15) << "Major"
         << setw(10) << "GPA"
         << setw(12) << "Grade Level" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    // List all students with formatted output
    for (int i = 0; i < NumberOfStudents; i++) {
        double gpa = CIS054[i].getGpa();
        int id = CIS054[i].getIdNumber();

        // Check for illegal values
        if (id == -1) {
            cout << left << setw(15) << "Invalid ID"
                 << setw(25) << CIS054[i].getName()
                 << setw(15) << CIS054[i].getMajor()
                 << setw(10) << "N/A"
                 << setw(12) << CIS054[i].getGradeLevel() << endl;
        } else {
            cout << left << setw(15) << id
                 << setw(25) << CIS054[i].getName()
                 << setw(15) << CIS054[i].getMajor()
                 << setw(10) << (gpa >= 0 ? to_string(gpa) : "N/A")
                 << setw(12) << CIS054[i].getGradeLevel() << endl;
        }
    }

    // Calculate and display the average GPA
    double total = 0;
    int validCount = 0; // Count only valid GPAs for average calculation
    for (int i = 0; i < NumberOfStudents; i++) {
        double gpa = CIS054[i].getGpa();
        if (gpa >= 0) { // Only consider valid GPAs
            total += gpa;
            validCount++;
        }
    }

    double average = validCount > 0 ? total / validCount : 0;
    cout << "=============================================================================" << endl;
    cout << "The average GPA of all the students is: "
         << fixed << setprecision(2) << average << endl;

    return 0;
}
