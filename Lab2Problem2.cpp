//Nhan Vo and Ian Lee
//CECS 282 LAB 2 - Problem 2
#include <iostream>
using namespace std;

class Account {
    float balance;
//Constructors
    public:
    Account() {
        balance = 0;
    }

    Account(int balance) {
        this -> balance = balance;
    }
//This function deposits money into an account
    int deposit(int amount) {
        balance += amount;
        return 0;
    }
//This function withdraws money from an account
    int withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            return 0;
        }

        else if ((amount > balance) && (balance > 5)) {
            balance -= 5;
            return 0; 
        }
        
        return 0;
    }
//This function returns a balance fo an account
    float get_balance() {
        return balance;
    }
//This function calculates interests for a balance
    int add_interest(float rate) {
        balance *= (1 + rate / 100);
        return 0;
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
