#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    Student(int r, string n, float m) {
        roll = r;
        name = n;
        marks = m;
    }

    char getGrade() {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }

    void display() {
        cout << "Roll No: " << roll << ", Name: " << name << ", Marks: " << marks
             << ", Grade: " << getGrade() << endl;
    }
};

class ReportCardSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        int roll;
        string name;
        float marks;

        cout << "Enter Roll Number: ";
        cin >> roll;

        // Check for duplicate roll number
        for (auto &s : students) {
            if (s.roll == roll) {
                cout << "Student with this roll number already exists!\n";
                return;
            }
        }

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks (0-100): ";
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid marks. Please enter between 0 and 100.\n";
            return;
        }

        students.push_back(Student(roll, name, marks));
        cout << "Student added successfully!\n";
    }

    void showAll() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        for (auto &s : students) {
            s.display();
        }
    }

    void searchStudent() {
        int roll;
        cout << "Enter Roll Number to search: ";
        cin >> roll;

        for (auto &s : students) {
            if (s.roll == roll) {
                s.display();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void calculateAverage() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        float sum = 0;
        for (auto &s : students) {
            sum += s.marks;
        }

        cout << "Average Marks: " << (sum / students.size()) << endl;
    }
};

void showMenu() {
    cout << "\n--- Student Report Card System ---\n";
    cout << "1. Add Student\n";
    cout << "2. Show All Students\n";
    cout << "3. Search Student by Roll Number\n";
    cout << "4. Show Average Marks\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ReportCardSystem system;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: system.addStudent(); break;
            case 2: system.showAll(); break;
            case 3: system.searchStudent(); break;
            case 4: system.calculateAverage(); break;
            case 5: cout << "Thank you! Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}


