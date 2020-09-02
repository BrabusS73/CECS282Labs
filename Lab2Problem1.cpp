//Nhan Vo and Ian Lee
//CECS 282 LAB 2 - Problem 1
#include <iostream>
using namespace std;

class Account {
float balance;

    public:
    Account() {
        balance = 0;
    }

    Account(int balance) {
        this -> balance = balance;
    }

    int deposit(int amount) {
        balance += amount;
        return 0;
    }

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

    int get_balance() {
        return balance;
    }
};

int main() {
    Account my_account(100);
    my_account.deposit(50);
    my_account.withdraw(175);
    my_account.withdraw(25);

    cout  << "Account balance:" << my_account.get_balance() << "\n";

    my_account.withdraw(my_account.get_balance());
    cout  << "Account balance:" << my_account.get_balance() << "\n";

    return 0;

}
