#include <bits/stdc++.h>
using namespace std;
class Bus {
private:
    vector<vector<char>> seats; 
public:
    Bus() {
        seats = vector<vector<char>>(20, vector<char>(4, 'E'));
    }
    bool isValid(int row, int col) {
        if (row < 0 || row >= 20 || col < 0 || col >= 4)
            return false;
        if (seats[row][col] != 'E')
            return false;
        return true;
    }
    void seatformale(int row, int col) {
        if (!isValid(row, col)) {
            cout << "Invalid or already booked seat!" << endl;
            return;
        }
        if ((col > 0 && seats[row][col - 1] == 'F') ||
            (col < 3 && seats[row][col + 1] == 'F')) {
            cout << "Sorry!! It is restricted (Female adjacent)" << endl;
        } else {
            seats[row][col] = 'M';
            cout << "Hurray!! Your seat has been booked (Male)" << endl;
        }
    }
    void seatforfemale(int row, int col) {
        if (!isValid(row, col)) {
            cout << "Invalid or already booked seat!" << endl;
            return;
        }
        if ((col > 0 && seats[row][col - 1] == 'M') ||
            (col < 3 && seats[row][col + 1] == 'M')) {
            cout << "Sorry!! It is restricted (Male adjacent)" << endl;
        } else {
            seats[row][col] = 'F';
            cout << "Hurray!! Your seat has been booked (Female)" << endl;
        }
    }
    void displaySeats() {
        cout << "\nSeat Layout:\n";
        for (int i = 0; i < 20; i++) {
            cout << "Row " << setw(2) << i << ": ";
            for (int j = 0; j < 4; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Bus b;
    while (true) {
        string gen;
        cout << "\nEnter gender (M/F), or 'e' to exit, or 'd' to display seats: ";
        cin >> gen;
        if (gen == "e") {
            cout << "Thank you!! Visit Again" << endl;
            break;
        } else if (gen == "d") {
            b.displaySeats();
        } else if (gen == "M" || gen == "F") {
            int row, col;
            cout << "Enter the row (0-19): ";
            cin >> row;
            cout << "Enter the col (0-3): ";
            cin >> col;
            if (gen == "M")
                b.seatformale(row, col);
            else
                b.seatforfemale(row, col);
        } else {
            cout << "Enter a valid input (M/F/d/e)" << endl;
        }
    }
    return 0;
}


