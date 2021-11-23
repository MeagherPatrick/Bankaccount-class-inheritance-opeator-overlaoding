/***************************************
Program Name: Client.cpp
Author: Patrick Meagher
Date: 11/13/2021
input: from User 
output: to Console
This program allows a client to 
set and update customers' bank accounts
***************************************/

#include "checkingAccount.h"
#include "BankAccountClass.h"
const int SIZE = 20;
int main()
{
  double amt = 0;
  char ans ='q';
  char ans2 = ' ';
    int acc;
  checkingAccount test[SIZE];
  do {
        static int newACC=0;
    cout << "Enter a to add a new customer's data. \n"
         << "Enter b to edit customer data. \n"
         << "Enter c to print all customer data. \n"
         << "Enter q to exit the program. \n";
    cin >> ans;
    switch (ans) {
      case 'a':
      case 'A':
        if (newACC < 20) {
          test[newACC].acc_SET();
          cout << "please enter the Monthly Service Charge";
          cin >> amt;
          test[newACC].set_sc(amt);
          cout << "please enter the Minimum Balance";
          cin >> amt;
          test[newACC].set_mb(amt);
          newACC++;
          break;
        }
        cout << "No more accounts can be created max of 20 was reached \n";
         break;
      case 'b':
      case 'B':
        for (int i = 0; i < SIZE; i++)
          test[i].acc_Prt();
        cout << "Please enter the account num you would to edit: \n  ";      
        cin >> acc;
        while (ans != 'q') {
          cout << "Enter a to make a deposit. \n"
               << "Enter b to withdraw. \n"
               << "Enter c to check balance. \n"
               << "Enter d to upate balance with interest.\n"
               << "Enter e to update the monthly service charge. \n"
               << "Enter f to update the minimum allowed balance \n"
               << "Enter q to return to previous menu. \n";
          cin >> ans;
          amt = 0;
          switch (ans) {
            case 'a':
            case 'A':
              cout << "Enter the amount you would like to Deposit: \n";
              cin >> amt;
             test[acc] = test[acc] + amt;
              break;
            case 'b':
            case 'B':
              cout << "Enter the amount you would like to Withdraw: \n";
              cin >> amt;
              test[acc].acc_WIT(amt);
              break;
            case 'c':
            case 'C':
              cout << "The current balance is: $" << test[acc].get_Bal() << '\n';
              break;
            case 'd':
            case 'D':
              test[acc].acc_InterestUpdate();
              break;
            case 'e':
            case 'E':
              amt = 0;
              cout << "the current Monthly Service charge is: "
                   << test[acc].get_sc() << '\n';
              cout << "please enter the new Monthly Service charge \n";
              cin >> amt;
              test[acc].set_sc(amt);
              cout << "the NEW Monthly Service charge is: "
                   << test[acc].get_sc() << '\n';
            case 'f':
            case 'F':
              amt = 0;
              cout << "the current Monthly Service charge is: "
                   << test[acc].get_mb() << '\n';
              cout << "PLease Enter The NEW Minimum Required Balance\n";
              cin >> amt;
              test[acc].set_mb(amt);
              cout << "the New Minimum  reuired balance is: "
                   << test[acc].get_mb() << '\n';
            case 'q':
            case 'Q':
            default:
              break;
          }
        }
        break;
      case 'c':
      case 'C':
        for (int i = 0; i < SIZE; i++)
          cout << test[i];
        break;
      case 'q':
      case 'Q':
       return 0;
        break;
    }
  } while (ans != 'q');
  return 0;
  }

  //double balance=0;
  //double intrest=0;
  //double amt =100;
 // for (int i = 0; i < SIZE; i++)
   // test[i].acc_Prt();
  /*test[0].acc_DEP(amt);
  test[0].acc_Prt();
  amt = 0.4;
  test[0].acc_WIT(amt);*/

