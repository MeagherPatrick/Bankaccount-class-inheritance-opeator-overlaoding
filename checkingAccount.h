#include "BankAccountClass.h"
class checkingAccount : public bankAccount
{
  friend ostream& operator<<(ostream&, checkingAccount&);
  // overloaded << operator
  // Precondition:
  //				 Object of checkingAccountClass must be created in client
  //.cpp
  // Postcondition:
  //				  Outputs to console:
  //										 Name
  //										 Balance
  //										 Interest
  //								         Acc
  //Num 										 Min Bal 										 Service Charge

public:
  checkingAccount();
  // Constructor
  // Precondition:
  //				 Object must be created in main
  // Postcondition:
  //				 Sets service Charge to 1
  //						 and min balance to 5

  void set_sc(double);
  //  user set service charge
  // Precondition:
  //				Service charge >= 0
  //
  // Postcondition:
  //				cin(user) sets Service Charge
  void set_mb(double);
  //  user set Minimum Balance
  // Precondition:
  //				Minimum Balance >= 0
  //
  // Postcondition:
  //				cin(user) sets Minimum Balance
  double get_sc() const;
  //  returns Service Charge
  // Precondition:
  //				function must  return  to a double type
  //
  // Postcondition:
  //				returns service charge as double type
  double get_mb() const;
  //  returns Minimum Balance
  // Precondition:
  //				function must  return  to a double type
  //
  // Postcondition:
  //				returns Minimum Balance as double type
  void acc_WIT(double);
  // over rides base class (bankAccount) withdraw function
  // Precondition:
  //              withdrawal  < minimum balance
  //			  withdrawal can be made for more than min balance
  //			  but service charge will apply
  //			  if service charge takes balance below 0 than transaction is
  //denied
  // Postcondition:
  //			  Balance is decreased by the withdrawal
  //			  cout to console:
  //								 withdrawal
  // 								 New Balance
  //				if balance is dropped below min balance (see
  //precondition)
  checkingAccount operator+(const double);
  // over rides the + operator
  //   Precondition:
  //            a double must be added to object
  //   Postcondition:
  //				amount will be added to and stored in balance
  //

private:
  double service_Charge;
  double min_balance;
};
