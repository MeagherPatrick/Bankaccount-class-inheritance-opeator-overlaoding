#include <iomanip>

#include "BankAccountClass.h"
using namespace std;
int bankAccount::accNum = 0;
bankAccount::bankAccount()
{
  nam = "9";
  bal = 0;
  inter = 0;
  theACCnum = accNum++;
}

void bankAccount::acc_SET()
{
  cout << "Please enter a name: \n";
  cin.ignore(1000, '\n');
  getline(cin, nam);
  cin.clear();
  cout << '\n' << "Please enter the Initial Deposit: ";
  cin >> bal;
  cout << '\n' << "Please enter the Interest Rate as a percent: ";
  cin >> inter;
  inter *= 100;
  cout << '\n';
}
void bankAccount::acc_Prt()
{
  if (nam != "9")
    cout << "name is: " << nam << fixed << setprecision(2) << " Bal is: $"
         << bal << " interest  is: %" << inter
         << " Account number is:  " << theACCnum << '\n';
}
void bankAccount::acc_InterestUpdate()
{
  cout << bal << '\n';
  bal += (bal * inter / 100);
  cout << "New Balance: " << bal << '\n';
}
int bankAccount::get_accNum() const
{
  return theACCnum;
}
double bankAccount::get_Bal() const
{
  return bal;
}
double bankAccount::get_interest() const
{
  return inter;
}
void bankAccount::set_bal(double amt)
{
  bal = amt;
}
void bankAccount::acc_DEP(double amt)
{
  if (amt > 0) {
    bal += amt;
    cout << "After Depositing: " << amt << "The Balance is now: " << fixed
         << setprecision(2) << bal << '\n';
  } else
    cout << "\n*****************************************\n"
         << "Error can not Deposit a negative amount: \n";
}
void bankAccount::acc_WIT(double amt)
{
  if (amt <= bal) {

    bal -= amt;
    cout << "After Withdrawing: " << amt << '\n'
         << "The Balance is now: " << fixed << setprecision(2) << bal << '\n';
  } else
    cout << "Error can not withdraw more than current balance: \n"
         << "Current balance is: " << fixed << setprecision(2) << bal << '\n';
}
void bankAccount::acc_UPd()
{
}

string bankAccount::get_name() const
{
  return nam;
}

/*void bankAccount::set_name(string name)
{
  nam = name;
}*/

// void bankAccount::set_accNum()
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
