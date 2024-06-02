#include <iostream>
#include <fstream>

using namespace std;

void showMenu() {
    cout << "**********MENU**********" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Create new account" << endl;
    cout << "5. Exit" << endl;
    cout << "************************" << endl;
}

void checkBalance(string account)
{
    fstream accountFile;
    double balance;

    account += ".txt";
    accountFile.open(account);

    if (accountFile.fail())
    {
        cout << "Account doesn't exist." << endl;
        return;
    }

    accountFile >> balance;
    cout << "Balance is: " << balance << "$" << endl;

    accountFile.close();

    balance = 0.0;
    account = account.substr(0, account.size() - 4);
}

void makeDeposit(string account)
{
    fstream accountFile;
    double balance;
    double deposit;

    account += ".txt";
    accountFile.open(account);

    if (accountFile.fail())
    {
        cout << "Account doesn't exist." << endl;
        return;
    }

    accountFile >> balance;
    cout << "Deposit amount: ";
    cin >> deposit;
    balance += deposit;
    accountFile.clear();
    accountFile.seekp(0);
    accountFile << balance;

    accountFile.close();

    balance = 0.0;
    deposit = 0.0;
    account = account.substr(0, account.size() - 4);

}

void makeWithdraw(string account) {
    fstream accountFile;
    double balance;
    double withdraw;

    account += ".txt";

    accountFile.open(account);

    if (accountFile.fail())
    {
        cout << "Account doesn't exist." << endl;
        return;
    }

    cout << "Withdraw amount: ";
    cin >> withdraw;
    accountFile >> balance;
    if (withdraw <= balance) {
        balance -= withdraw;
        accountFile.clear();
        accountFile.seekp(0);
        accountFile << balance;
    }
    else {
        cout << "Not enough money." << endl;
    }

    accountFile.close();

    balance = 0.0;
    withdraw = 0.0;
    account = account.substr(0, account.size() - 4);
}

void createAccount(string newAccount) {
    fstream newAccFile;
    int option;
    double startBalance = 0;
    newAccount += ".txt";

    newAccFile.open(newAccount, ios::out);
    if (newAccFile.fail()) {
        cout << "Couldn't open new Account." << endl;
        return;
    }

    newAccFile << startBalance;

    cout << "New Account successfully opened." << endl;

    newAccFile.close();

    newAccount = newAccount.substr(0, newAccount.size() - 4);

    cout << "Do you want to deposit money now?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Option: ";
    cin >> option;

    if (option == 1) {
        makeDeposit(newAccount);
    }
    else {
        return;
    }
}


int main()
{
    int option;
    string account;
    string newAccount;

    do {
        showMenu();
        cout << "Option: ";
        cin >> option;

        system("cls");

        if (option == 1) {
            cout << "Write Account name: ";
            cin >> account;

            checkBalance(account);
        }
        else if (option == 2) {
            cout << "Write Account name: ";
            cin >> account;

            makeDeposit(account);
        }
        else if (option == 3) {
            cout << "Write Account name: ";
            cin >> account;

            makeWithdraw(account);
        }
        else if (option == 4) {
            string newAccount;
            cout << "Enter new account name: ";
            cin >> newAccount;

            createAccount(newAccount);
        }
        system("pause>0");
    } while (option != 5);
    return 0;
}