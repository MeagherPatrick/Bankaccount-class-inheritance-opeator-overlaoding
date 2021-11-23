#pragma once
#include "BankAccountClass.h"
class checkingAccount: public bankAccount
{
  friend ostream& operator<<(ostream&, checkingAccount&);
 
public:
  checkingAccount();
  void set_sc(double);
  void set_mb(double);
  double get_sc() const;
  double get_mb() const;
  void acc_WIT(double);
  checkingAccount operator+(const double);

private:
  double service_Charge;
  double min_balance;
};
