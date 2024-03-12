//Program to Show piggy bank menu, where we can deposit, withdraw, view the coins.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Initialize variables
    double balance = 0.0;
    double depositAmount, withdrawAmount;
    int choice;

    do {
        // Display menu
        cout << "***********************************" << endl;
        cout << "* Piggy Bank Menu *" << endl;
        cout << "* *" << endl;
        cout << fixed << setprecision(3);
        cout << "* Current Balance $ " << balance << " *" << endl;
        cout << "***********************************" << endl;
        cout << "* *" << endl;
        cout << "* 1) Make Deposit *" << endl;
        cout << "* 2) Make Withdrawal *" << endl;
        cout << "* 3) View Coins *" << endl;
        cout << "* 4) Exit Program *" << endl;
        cout << "* *" << endl;
        cout << "***********************************" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // deposit
                cout << "Enter the amount to be deposited: $ ";
                cin >> depositAmount;
                if (depositAmount < 0) {
                    cout << "Invalid amount -- Negative values are not allowed." << endl;
                } else if (balance + depositAmount > 900.00) {
                    cout << "The piggy bank will not hold that much." << endl;
                    cout << "You may deposit up to $ " << 900.00 - balance << endl;
                } else {
                    balance += depositAmount;
                    cout << "Valid amount." << endl;
                }
                break;

            case 2:
                // withdrawal
                cout << "Enter the amount to be withdrawn: $ ";
                cin >> withdrawAmount;
                if (withdrawAmount < 0) {
                    cout << "Invalid amount -- Negative values are not allowed." << endl;
                } else if (withdrawAmount > balance) {
                    cout << "The piggy bank does not contain that much." << endl;
                    cout << "You may withdraw up to $ " << balance << endl;
                } else {
                    balance -= withdrawAmount;
                    cout << "Valid amount." << endl;
                }
                break;

            case 3:
                // coins
                int quarters, dimes, nickels, pennies;
                if (balance > 0) {
                    quarters = static_cast<int>(balance / 0.25);
                    balance -= quarters * 0.25;
                    dimes = static_cast<int>(balance / 0.10);
                    balance -= dimes * 0.10;
                    nickels = static_cast<int>(balance / 0.05);
                    balance -= nickels * 0.05;
                    pennies = static_cast<int>(balance / 0.01);

                    cout << "*****************************" << endl;
                    cout << "* Statistics *" << endl;
                    cout << "*****************************" << endl;
                    cout << "* *" << endl;
                    cout << "* Quarters " << quarters << " $ " << quarters * 0.25 << " *" << endl;
                    cout << "* Dimes " << dimes << " $ " << dimes * 0.10 << " *" << endl;
                    cout << "* Nickels " << nickels << " $ " << nickels * 0.05 << " *" << endl;
                    cout << "* Pennies " << pennies << " $ " << pennies * 0.01 << " *" << endl;
                    cout << "* *" << endl;
                    cout << "*****************************" << endl;
                } else {
                    cout << "No balance to convert to coins." << endl;
                }
                break;

            case 4:
                // Exit program
                cout << "Exiting the Program" << endl;
                break;

            default:
                // Invalid choice
                cout << "Invalid Menu Choice error" << endl;
                cout << "Invalid Option -- Try again" << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
