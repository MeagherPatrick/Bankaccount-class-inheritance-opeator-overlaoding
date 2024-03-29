#ifndef H_bankAccount
#  define H_bankAccount
#  include <iostream>
#  include <string>
using namespace std;
class bankAccount
{
public:
  bankAccount();
  // Constructor
  // Precondition:
  //				 Object must be created in main
  // Postcondition:
  //				 Sets the name to a default of 9
  //				 Balance to 0
  //				 Interest to 0
  //				 Sets & Increments the Acc Num
  void acc_SET();
  // User input of new Acc
  // Precondition:
  //				position  of object array must be indicated
  //				by a static int
  // Postcondition:
  //				 cin(user) Sets:
  //								 Name
  //								 Balance
  //								 Interest

  void acc_DEP(double);
  // Precondition:
  //              Deposit > 0
  // Postcondition:
  //			  Balance is increased by the deposit
  //			  cout to console:
  //								 Deposited
  //amount 								 New Balance
  void acc_WIT(double);
  // Precondition:
  //              withdrawal  < Balance
  // Postcondition:
  //			  Balance is decreased by the withdrawal
  //			  cout to console:
  //								 withdrawal
  // 								 New Balance
  void acc_UPd();
  // User input update to customer balance
  // Precondition:
  //				at least one customer account must have been
  //created.
  // Postcondition:
  //			   cin(user) Updates Balance:
  //										  Withdrawal
  // 										  Deposit
  void acc_Prt();
  // prints all uses created customers and all data
  // Precondition:
  //				at least one customer account should have been
  //created.
  // Postcondition:
  //				 cout to console:
  //								  Name
  //								  Balance
  //								  Interest
  //								  Acc Num
  void acc_InterestUpdate();
  // updates balance with interest.
  // Precondition:
  //              balance and interest must be set
  // Postcondition:
  //			  Balance is increased interest
  //			  cout to console:
  //							  New Balance
  string get_name() const;
  //  returns Name
  // Precondition:
  //				function must return to a string type
  // Postcondition:
  //				returns name as a string type
  int get_accNum() const;
  //  returns account number
  // Precondition:
  //				function must return to an int type
  // Postcondition:
  //				returns account number as an int type
  double get_Bal() const;
  //  returns balance
  // Precondition:
  //				function must return to a double type
  // Postcondition:
  //				returns balance as a double type
  double get_interest() const;
  //  returns interest
  // Precondition:
  //				function must return to a double type
  // Postcondition:
  //				returns interest as a double type
  void set_bal(double);
  //  sets balance
  // Precondition:
  //				balance must already be set and > 0
  // Postcondition:
  //				will set a new balance

private:
  static int accNum;
  int theACCnum;
  string nam;
  double bal, inter;
};
#endif
// const int MAX = 25;
/* double set_interest(double);*/
// bankAccount(static int);
// void set_name(string);
// string, double, double, static int
// void set_accNum();
