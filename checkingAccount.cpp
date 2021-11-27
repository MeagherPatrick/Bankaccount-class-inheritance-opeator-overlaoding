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
  double test_bal = bal;
  // cout << bal << '\n';
  if ((test_bal -= amt) >= min_balance) {
    bal -= amt;
    cout << "after Withdrawing: " << amt << '\n'
         << "the balance is now: " << fixed << setprecision(2) << bal << '\n';
    set_bal(bal);
  } else {

    cout << bal << '\n';
    cout << "****Amount will reduce account below min balance: current min "
            "balance required: "
         << min_balance << '\n'
         << " The Service charge will be applied to current balance: **** \n "
         << "Current balance is: " << fixed << setprecision(2) << bal << '\n'
         << "Current service charge is: " << service_Charge << '\n';
    bal -= service_Charge;
    bal -= amt;
    cout << "The balance is now: " << fixed << setprecision(2) << bal << '\n';
    if (bal < 0) {
      cout << "**** Balance has dropped below \"0.00\" : "
           << " transaction is cancelled \n";
      bal = get_Bal();
      cout << "current balance is: " << fixed << setprecision(2) << bal
           << '\n';

    } else
      set_bal(bal);
  }
}

checkingAccount checkingAccount::operator+(const double amt)
{
  double balance = 0;
  checkingAccount temp = *this;
  balance = temp.get_Bal();
  balance += amt;
  temp.set_bal(balance);
  return temp;
}

ostream& operator<<(ostream& output, checkingAccount& obj)
{

  if (obj.get_name() != "9") {

    output << "name is: " << obj.get_name() << fixed << setprecision(2)
           << " Bal is: $" << obj.get_Bal() << " interest  is: %"
           << obj.get_interest() << " account number is:  " << obj.get_accNum()
           << "min balance: " << obj.min_balance
           << " Monthly Service Fee: " << obj.service_Charge << '\n';
  }
  return output;
}
