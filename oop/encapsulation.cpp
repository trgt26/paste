#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float gpa;

public:
    // Constructor
    Student(string n, int r, float g) {
        name = n;
        rollNumber = r;
        setGPA(g); // validate GPA through setter
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Setter for name
    void setName(string newName) {
        name = newName;
    }

    // Getter for GPA
    float getGPA() {
        return gpa;
    }

    // Setter for GPA (with validation)
    void setGPA(float newGPA) {
        if (newGPA >= 0.0 && newGPA <= 4.0)
            gpa = newGPA;
        else
            cout << "Invalid GPA. Must be between 0.0 and 4.0." << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Roll: " << rollNumber << ", GPA: " << gpa << endl;
    }
};

int main() {
    Student s("John", 101, 3.5);

    s.displayInfo();
    s.setGPA(4.2);      // Invalid, will show error
    s.setGPA(3.8);      // Valid
    s.setName("Johnny");

    cout << "\nUpdated Info:\n";
    s.displayInfo();

    // s.gpa = 10; // ❌ Not allowed, gpa is private

    return 0;
}
