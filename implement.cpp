#include "BankAccountClass.h"
#include <iomanip>
using namespace std;
int bankAccount::accNum=0;
bankAccount::bankAccount()
{
  nam = "9";
  bal = 0;
  inter = 0;
  theACCnum = accNum++;
}

void  bankAccount::acc_SET()
{
  cout << "Please enter a name: \n";
    cin.ignore(1000, '\n');
    getline(cin, nam);
    cin.clear(); 
  cout << '\n' << "Please enter the initial  deposit: ";
    cin >> bal;
  cout << '\n' << "Please enter the interest rate as a percent: ";
    cin >> inter;
  inter *= 100;
    cout << '\n';
}
void bankAccount::acc_Prt()
{
  if (nam != "9")
  cout << "name is: " << nam <<fixed<< setprecision(2)<<" Bal is: $" << bal << " interest  is: %" << inter
       << " account number is:  " << theACCnum << '\n';
}
void bankAccount::acc_InterestUpdate()
{
  cout << bal << '\n';
    bal += (bal * inter/100);
        cout << "New balance: "<< bal << '\n';
}
int bankAccount::get_accNum() const
{
   return theACCnum;
}
double bankAccount::get_Bal() const
{
  return bal;
}
void bankAccount::acc_DEP(double amt)
{
  if (amt > 0) {
    bal += amt;
        cout << "after depositing: " << amt << "the balance is now: " << fixed
         << setprecision(2) << bal
         << '\n';
  } 
    else
    cout << "\n*****************************************\n"
      << "Error can not deposit a negative amount: \n";
}
void bankAccount::acc_WIT(double amt)
{
  if (amt <= bal) {

    bal -= amt;
    cout << "after Withdrawing: " << amt << '\n'
         << "the balance is now: " << fixed << setprecision(2) << bal << '\n';
  }
  else cout << "error can not withdraw more than current balance: \n"
         << "current balance is: " << fixed << setprecision(2) << bal <<'\n';
}
void bankAccount::acc_UPd()
{ 
 
  char ans = ' ';
  double amt=0;
  while (ans != 'q') 
  {
    cout << "Enter a to make a deposit." << '\n'
         << "Enter b to withdraw." << '\n'
         << "Enter c to check balance." << '\n'
         << "Enter d to upate balance with interest." << '\n'
         << "Enter q to return to previous menu." << '\n';
    cin >> ans;
    switch (ans) {
      case 'a':
      case 'A':
        cout << "Enter the amount you would like to Deposit: \n";
        cin >> amt;
        acc_DEP(amt);
        break;
      case 'b':
      case 'B':
        cout << "Enter the amount you would like to Withdraw: \n";
        cin >> amt;
        acc_WIT(amt);
        break;
      case 'c':
      case 'C':
        cout << "The current balance is: $" << bal << '\n';
        break;
      case 'd':
      case 'D':
        acc_InterestUpdate();
        break;
      case 'q':
      case 'Q':
      default:
          break;

    }
  }
}

  string bankAccount::get_name() const
  {   
    return nam;
  }

  /*void bankAccount::set_name(string name)
  {
    nam = name; 
  }*/

  
//void bankAccount::set_accNum()
//{
//  //accNum++;
//}


  /*double bankAccount::set_interest(double percent)
  {
    percent *= 100;
    return percent;
  }*/

 /* cout << "PLease enter the name you would like to replace " << nam
       << " with: " << '\n';
  cin >> nam;
  cout << "PLease enter bal you would like to replace " << bal
       << " with: " << '\n';
  cin >> bal;
  cout << "PLease enter the name you would like to replace " << inter
       << " with: " << '\n';
  cin >> inter;
  cout << accNum << " has been updated to: " << '\n';
  acc_Prt();*/
////bankAccount::~bankAccount()
//{
//  accNum--;
//}