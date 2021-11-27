/***************************************
Program Name: Client.cpp
Author: Patrick Meagher
Date: 11/26/2021
input: from User
output: to Console
This program allows a client to
set and update customers' bank accounts
***************************************/

#include "BankAccountClass.h"
#include "checkingAccount.h"
const int SIZE = 20;
int main()
{
  double amt = 0;
  char ans = 'q';
  char ans2 = ' ';
  int acc;
  checkingAccount test[SIZE];
  do {
    static int newACC = 0;
    cout << "Enter A to add a new customer's data. \n"
         << "Enter B to edit customer data. \n"
         << "Enter C to print all customer data. \n"
         << "Enter Q to exit the program. \n";
    cin >> ans;
    ans = toupper(ans);
    switch (ans) {

      case 'A':
        if (newACC < 20) {
          test[newACC].acc_SET();
          do {
            cout << "Please enter the Monthly Service Charge: \n Amount equal "
                    "to \"$0.00\" will set the default service. \n enter "
                    "amount now:  ";
            cin >> amt;
            if (amt < 0)
              cout << "****Amount must be greater than or equal to: "
                      "\"$0.00\"****  \n ";
          } while (amt < 0);
          if (amt == 0) {
            cout << "Amount equal to \"$0.00\" will set the default service "
                    "charge of: \"$1.00\" \n";
          } else {
            test[newACC].set_sc(amt);
          }
          do {
            cout << "Please enter the Minimum Balance: ";
            cin >> amt;
            if (amt < 0) {
              cout << "****Amount must be greater than or equal to: "
                      "\"$0.00\"****  \n ";
            }
          } while (amt < 0);
          test[newACC].set_mb(amt);
          newACC++;
          break;
        }
        cout << "No more accounts can be created max of 20 was reached \n";
        break;

      case 'B':
        for (int i = 0; i < SIZE; i++)
          test[i].acc_Prt();
        cout << "Please enter the account num you would to edit: \n  ";
        cin >> acc;
        while (ans != 'Q') {
          cout << "Enter A to make a deposit. \n"
               << "Enter B to withdraw. \n"
               << "Enter C to check balance. \n"
               << "Enter D to update balance with interest.\n"
               << "Enter E to update the monthly service charge. \n"
               << "Enter F to update the minimum allowed balance \n"
               << "Enter Q to return to previous menu. \n";
          cin >> ans;
          ans = toupper(ans);
          amt = 0;
          switch (ans) {
            case 'A':
              cout << "Enter the amount you would like to Deposit: \n";
              cin >> amt;
              test[acc] = test[acc] + amt;
              break;

            case 'B':
              cout << "Enter the amount you would like to Withdraw: \n";
              cin >> amt;
              test[acc].acc_WIT(amt);
              break;

            case 'C':
              cout << "The current balance is: $" << test[acc].get_Bal()
                   << '\n';
              break;

            case 'D':
              test[acc].acc_InterestUpdate();
              break;

            case 'E':
              amt = 0;
              cout << "the current Monthly Service charge is: "
                   << test[acc].get_sc() << '\n';
              do {
                cout << "please enter the new Monthly Service charge \n";
                cin >> amt;
                if (amt < 0)
                  cout << "****Amount must be greater than or equal to: "
                          "\"$0.00\"****  \n ";
              } while (amt < 0);
              test[acc].set_sc(amt);
              cout << "the NEW Monthly Service charge is: "
                   << test[acc].get_sc() << '\n';
              break;
            case 'F':
              amt = 0;
              cout << "the current Monthly Service charge is: "
                   << test[acc].get_mb() << '\n';
              do {
                cout << "Please Enter The NEW Minimum Required Balance\n";
                cin >> amt;
                if (amt < 0)
                  cout << "****Amount must be greater than or equal to: "
                          "\"$0.00\"****  \n ";
              } while (amt < 0);
              test[acc].set_mb(amt);
              cout << "The New Minimum Required Balance is: "
                   << test[acc].get_mb() << '\n';
              break;
            case 'Q':
              break;
            default:
              break;
          }
        }
        break;
      case 'C':
        for (int i = 0; i < SIZE; i++)
          cout << test[i];
        break;
      case 'Q':
        return 0;
        break;
    }
  } while (ans != 'Q');
  return 0;
}

// double balance=0;
// double intrest=0;
// double amt =100;
// for (int i = 0; i < SIZE; i++)
// test[i].acc_Prt();
/*test[0].acc_DEP(amt);
test[0].acc_Prt();
amt = 0.4;
test[0].acc_WIT(amt);*/
