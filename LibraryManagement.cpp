#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string id, name, author;
    bool isIssued;
    Book(string id, string name, string author) {
        this->id = id;
        this->name = name;
        this->author = author;
        this->isIssued = false;
    }
    void display() {
        cout << "ID: " << id << ", Title: " << name
             << ", Author: " << author
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};
class Library {
private:
    vector<Book> books;
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }
    void showBooks() {
        if (books.empty()) {
            cout << "The library is empty." << endl;
        } else {
            for (auto &b : books) {
                b.display();
            }
        }
    }

    void issueBook(string id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "✅ The book has been issued." << endl;
                    book.isIssued = true;
                } else {
                    cout << "❌ The book is already issued." << endl;
                }
                return;
            }
        }
        cout << "❌ Book not found." << endl;
    }

    void returnBook(string id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "✅ The book has been returned." << endl;
                    book.isIssued = false;
                } else {
                    cout << "⚠️ The book was not issued." << endl;
                }
                return;
            }
        }
        cout << "❌ Book not found." << endl;
    }
};

void showMenu() {
    cout << "\n--- Library Management Menu ---\n";
    cout << "1. Add Book\n";
    cout << "2. Show All Books\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Library lib;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Let's add a book.\n";
            string author, name, id;
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Name: ";
            cin >> name;
            cout << "Enter Author Name: ";
            cin >> author;
            lib.addBook(Book(id, name, author));
        } else if (choice == 2) {
            lib.showBooks();
        } else if (choice == 3) {
            cout << "Enter the ID of the book to issue: ";
            string id;
            cin >> id;
            lib.issueBook(id);
        } else if (choice == 4) {
            cout << "Enter the ID of the book to return: ";
            string id;
            cin >> id;
            lib.returnBook(id);
        } else if (choice == 5) {
            cout << "Thank you! Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
