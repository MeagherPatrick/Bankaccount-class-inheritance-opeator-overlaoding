#pragma once
#include "BankAccountClass.h"
class checkingAccount: public bankAccount
{
public:
  checkingAccount();


private:
  double service_Charge;
  double min_balance;
};
