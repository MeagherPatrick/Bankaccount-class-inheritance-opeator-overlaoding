#include "checkingAccount.h"
#include <iomanip>

checkingAccount::checkingAccount()
{
  service_Charge = 1;
  min_balance = 5;
}

void checkingAccount::set_sc(double charge)
{
  service_Charge = charge;
}

void checkingAccount::set_mb(double min)
{
  min_balance = min;
}

double checkingAccount::get_sc() const
{
  return service_Charge;
}

double checkingAccount::get_mb() const
{
  return min_balance;
}

void checkingAccount::acc_WIT(double amt)
{
  double bal = 0;
  bal = get_Bal();
    if (amt <= bal) {

      bal -= amt;
      cout << "after Withdrawing: " << amt << '\n'
           << "the balance is now: " << fixed << setprecision(2) << bal
           << '\n';
      set_bal(bal);
    } else
      cout << "error can not withdraw more than current balance: \n"
           << "current balance is: " << fixed << setprecision(2) << bal
           << '\n';
}

checkingAccount checkingAccount::operator+(const double x)
{
  double i = 0;
  checkingAccount temp = *this;
  i = temp.get_Bal();
  i += x;
   temp.set_bal(i);  
  return temp;
}

ostream& operator<<(ostream& output, checkingAccount& obj)
{
  
  if (obj.get_name() != "9") {

    output << "name is: " << obj.get_name() << fixed << setprecision(2)
           << " Bal is: $" << obj.get_Bal() << " interest  is: %"
           << obj.get_interest() << " account number is:  " << obj.get_accNum()
           << "min blance: " << obj.min_balance
           << " Monthly Serivce Fee: " << obj.service_Charge << '\n';
  }
  return output;
}
