#include <iostream>
using namespace std;

// Base class
class Human {
protected:
    string name;
    int age;

public:
    Human(string n, int a) : name(n), age(a) {}

    void introduce() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student
class Student : public Human {
private:
    string studentId;

public:
    Student(string n, int a, string id) : Human(n, a), studentId(id) {}

    void study() {
        cout << name << " is studying. ID: " << studentId << endl;
    }
};

// Derived class: Teacher
class Teacher : public Human {
private:
    string subject;

public:
    Teacher(string n, int a, string sub) : Human(n, a), subject(sub) {}

    void teach() {
        cout << name << " is teaching " << subject << "." << endl;
    }
};

int main() {
    Student s("Alice", 20, "S123");
    Teacher t("Mr. Smith", 40, "Mathematics");

    s.introduce(); // Inherited from Human
    s.study();     // Specific to Student

    cout << endl;

    t.introduce(); // Inherited from Human
    t.teach();     // Specific to Teacher

    return 0;
}
