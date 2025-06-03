#include <iostream>
#include <vector>
using namespace std;

class Account {
public:
    int accountNumber;
    string name;
    double balance;

    Account(int accNo, string accName, double initialDeposit) {
        accountNumber = accNo;
        name = accName;
        balance = initialDeposit;
    }

    void display() {
        cout << "Account No: " << accountNumber << ", Name: " << name << ", Balance: ₹" << balance << endl;
    }
};

class ATM {
private:
    vector<Account> accounts;

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.accountNumber == accNo)
                return &acc;
        }
        return nullptr;
    }

public:
    void createAccount() {
        int accNo;
        string name;
        double deposit;
        cout << "Enter account number: ";
        cin >> accNo;
        if (findAccount(accNo)) {
            cout << "Account number already exists.\n";
            return;
        }
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter initial deposit (min ₹500): ";
        cin >> deposit;
        if (deposit < 500) {
            cout << "Minimum deposit must be ₹500.\n";
            return;
        }
        accounts.push_back(Account(accNo, name, deposit));
        cout << "Account created successfully!\n";
    }

    void depositMoney() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (!acc) {
            cout << "Account not found.\n";
            return;
        }
        cout << "Enter deposit amount: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Amount must be greater than 0.\n";
            return;
        }
        acc->balance += amount;
        cout << "Amount deposited. New Balance: ₹" << acc->balance << endl;
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (!acc) {
            cout << "Account not found.\n";
            return;
        }
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        if (amount <= 0 || amount > acc->balance - 500) {
            cout << "Invalid amount. Minimum balance of ₹500 must be maintained.\n";
            return;
        }
        acc->balance -= amount;
        cout << "Withdrawal successful. Remaining Balance: ₹" << acc->balance << endl;
    }

    void checkBalance() {
        int accNo;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (!acc) {
            cout << "Account not found.\n";
            return;
        }
        cout << "Your current balance is: ₹" << acc->balance << endl;
    }
};

void showMenu() {
    cout << "\n==== ATM Menu ====\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ATM atm;
    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: atm.createAccount(); break;
            case 2: atm.depositMoney(); break;
            case 3: atm.withdrawMoney(); break;
            case 4: atm.checkBalance(); break;
            case 5: cout << "Thank you for using the ATM. Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
