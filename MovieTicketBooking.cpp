#include <iostream>
#include <vector>
using namespace std;

class Theatre {
private:
    vector<vector<char>> seats;
    int emptySeats;

public:
    Theatre() {
        for (int i = 0; i < 5; i++) {
            vector<char> row;
            for (int j = 1; j <= 20; j++) {
                if (j <= 9) row.push_back('0' + j);       
                else row.push_back('A' + (j - 10));       
            }
            seats.push_back(row);
        }
        emptySeats = 100;
    }

    void displayTickets() {
        cout << "\n     ";
        for (int j = 1; j <= 20; j++) {
            if (j <= 9) cout << " " << j << " ";
            else cout << (char)('A' + (j - 10)) << "  ";
        }
        cout << "\n";

        for (int i = 0; i < 5; i++) {
            cout << "Row " << i << " ";
            for (int j = 0; j < 20; j++) {
                cout << " " << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bookTickets(int tickets) {
        if (emptySeats < tickets) {
            cout << "Sorry! Not enough seats available.\n";
            return;
        }

        for (int i = 0; i < tickets; i++) {
            int row, col;
            cout << "Enter the row (0–4): ";
            cin >> row;
            cout << "Enter the seat number (1–20): ";
            cin >> col;
            col -= 1;  // Convert to 0-based index

            if (!isValid(row, col)) {
                cout << "Invalid seat. Try again.\n";
                i--;
                continue;
            }

            if (seats[row][col] == 'X') {
                cout << "Seat already booked. Choose another.\n";
                i--;
                continue;
            }

            seats[row][col] = 'X';
            emptySeats--;
            cout << "Seat booked successfully.\n";
        }
    }

    void cancelTickets(int tickets) {
        if ((100 - emptySeats) < tickets) {
            cout << "You haven't booked that many seats.\n";
            return;
        }

        for (int i = 0; i < tickets; i++) {
            int row, col;
            cout << "Enter the row (0–4): ";
            cin >> row;
            cout << "Enter the seat number (1–20): ";
            cin >> col;
            col -= 1;

            if (!isValid(row, col)) {
                cout << "Invalid seat. Try again.\n";
                i--;
                continue;
            }

            if (seats[row][col] != 'X') {
                cout << "Seat not booked yet. Try again.\n";
                i--;
                continue;
            }

            // Restore original seat label
            if (col <= 8) seats[row][col] = '0' + (col + 1);
            else seats[row][col] = 'A' + (col - 9);

            emptySeats++;
            cout << "Seat cancelled successfully.\n";
        }
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < 5 && col >= 0 && col < 20;
    }
};

void showMenu() {
    cout << "\n======== Movie Ticket Booking System ========\n";
    cout << "1. Display Available Seats\n";
    cout << "2. Book Tickets\n";
    cout << "3. Cancel Tickets\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Theatre t;
    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            t.displayTickets();
        } else if (choice == 2) {
            int tickets;
            cout << "Enter number of tickets to book: ";
            cin >> tickets;
            t.bookTickets(tickets);
        } else if (choice == 3) {
            int tickets;
            cout << "Enter number of tickets to cancel: ";
            cin >> tickets;
            t.cancelTickets(tickets);
        } else if (choice == 4) {
            cout << "Thank you for using the system!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
