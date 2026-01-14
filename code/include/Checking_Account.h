#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_

#include <string>
#include <vector>
#include "Transaction.h"
#include "IAccount.h"

class Checking_Account : public IAccount {
    public:
     Checking_Account();

     Checking_Account(int id, double balance, double interest_rate, std::string creditor, vector<Transaction> transactions);

     int get_id() override;

     double get_balance() override;

     std::string get_trustee();

     const vector<Transaction> get_transactions() const;

     double get_apy();

     void set_id(int new_id);

     void set_trustee(std::string trustee);

     void set_balance(double new_balance) override;

     void set_apy(double new_apy);

     void set_transactions(vector<Transaction> new_transactions);

     std::string process_transaction(Transaction *transaction);

    private:
     int id;
     double balance;
     vector<Transaction> transactions;
     std::string trustee;
     double apy;
};

#endif
