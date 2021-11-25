#include "BankAccountClass.h"
class checkingAccount: public bankAccount
{
  friend ostream& operator<<(ostream&, checkingAccount&);
 
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
	  //				function must be return a double type
	  //
	  // Postcondition:
	  //				reurns service charge as double type
  double get_mb() const;
	  //  returns Minimum Balance
	  // Precondition:
	  //				function must be return a double type
	  //
	  // Postcondition:
	  //				reurns Minimum Balance as double type
  void acc_WIT(double);
  //over rides base class (bankAccount) withdraw fucntion
  // Precondition:
  //              withdrawal  < Balance
  // Postcondition:
  //			  Balance is decreased by the withdrawal
  //			  cout to console:
  //								 withdrawal
  // 								 New Balance
  checkingAccount operator+(const double);
  //over rides the + operator
  //   Precondition:
  //            a double must be added to object
  //   Postcondition:
  //				amount will be added to and stored in balance
  //

private:
  double service_Charge;
  double min_balance;
};
