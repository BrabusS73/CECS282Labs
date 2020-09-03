//Nhan Vo and Ian Lee
//CECS 282 LAB 2 - Problem 2
#include <iostream>
using namespace std;

class Account {
    double balance;
//Constructors
    public:
    Account() {
        balance = 0;
    }

    Account(double balance) {
        this -> balance = balance;
    }
//This function deposits money into an account
    void deposit(double amount) {
        balance += amount;
    }
//This function withdraws money from an account
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }

        else if ((amount > balance) && (balance > 5)) {
            balance -= 5;
        }
        
    }
//This function returns a balance fo an account
double get_balance() {
        return balance;
    }
//This function calculates interests for a balance
    void add_interest(float rate) {
        balance *= (1 + rate / 100);
    }
};

int main() {
    int init_amount;
    float rate;
    int months = 0;
    cout << "Enter initial amount of your account:";
    cin >> init_amount;
    cout << "Enter your interest rate:";
    cin >> rate;
    Account my_account(init_amount);
    int final_amount = init_amount * 2;
    while (my_account.get_balance() < final_amount) {
        my_account.add_interest(rate / 12);
        months++;
    }

    cout << "It took " << months << " for $" << init_amount << " to double at " << rate << "% annual interest." << "\n"; 
    cout << "Account balance: $" << my_account.get_balance() << "\n";
    return 0;

}
