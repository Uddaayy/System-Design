#include <iostream>
#include <vector>
using namespace std;

class Parking {
private:
    vector<vector<string>> slots;
public:
    Parking() {
        slots = vector<vector<string>>(3, vector<string>(10, "Empty"));
    }

    void display(int wheels) {
        int row = getRow(wheels);
        if (row == -1) {
            cout << "Invalid number of wheels!\n";
            return;
        }

        cout << "\nParking Row for " << wheels << "-wheelers (Row " << row << "):\n";
        for (int col = 0; col < 10; col++) {
            cout << "[" << slots[row][col] << "] ";
        }
        cout << endl;
    }

    void parkVehicle(int wheels, int col) {
        int row = getRow(wheels);
        if (row == -1 || col < 0 || col >= 10) {
            cout << "Invalid input.\n";
            return;
        }

        if (slots[row][col] == "Empty") {
            slots[row][col] = "Parked";
            cout << "Vehicle parked at Row " << row << ", Slot " << col << endl;
        } else {
            cout << "Slot already occupied.\n";
        }
    }
    void unparkVehicle(int wheels, int col) {
        int row = getRow(wheels);
        if (row == -1 || col < 0 || col >= 10) {
            cout << "Invalid input.\n";
            return;
        }

        if (slots[row][col] == "Parked") {
            slots[row][col] = "Empty";
            cout << "Vehicle unparked from Row " << row << ", Slot " << col << endl;
        } else {
            cout << "Slot is already empty.\n";
        }
    }

    int getRow(int wheels) {
        if (wheels == 2) return 0;
        if (wheels == 4) return 1;
        if (wheels >= 6) return 2;
        return -1;
    }
};
void showMenu() {
    cout << "\n==== Parking System ====\n";
    cout << "1. Show Available Slots\n";
    cout << "2. Park Vehicle\n";
    cout << "3. Unpark Vehicle\n";
    cout << "4. Exit\n";
}

int main() {
    Parking p;
    while (true) {
        showMenu();
        int choice;
        cout << "Enter the choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the number of wheels: ";
            int wheels;
            cin >> wheels;
            p.display(wheels);
        } else if (choice == 2) {
            cout << "Enter the number of wheels: ";
            int wheels;
            cin >> wheels;
            cout << "Enter the column number (0 to 9): ";
            int col;
            cin >> col;
            p.parkVehicle(wheels, col);
        } else if (choice == 3) {
            cout << "Enter the number of wheels: ";
            int wheels;
            cin >> wheels;
            cout << "Enter the column number (0 to 9): ";
            int col;
            cin >> col;
            p.unparkVehicle(wheels, col);
        } else if (choice == 4) {
            cout << "Thank you!!\n";
            break;
        } else {
            cout << "Enter a valid input\n";
        }
    }
    return 0;
}
