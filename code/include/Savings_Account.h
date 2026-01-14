#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include <string>
#include <vector>
#include "Transaction.h"
#include "IAccount.h"

class Savings_Account : public IAccount {
    public:
     Savings_Account();

     Savings_Account(int start_id, double start_balance, double start_apy, std::string start_trustee, vector<Transaction> start_transactions);

     int get_id() override;

     double get_balance() override;

     std::string get_trustee();

     const vector<Transaction> get_transactions() const;

     double get_apy();

     void set_id(int new_id);

     void set_trustee(std::string new_trustee);

     void set_balance(double new_balance) override;

     void set_apy(double new_apy);

     void set_transactions(vector<Transaction> new_transactions);

     std::string process_transaction(Transaction* transaction);

    private:
     int id;
     double balance;
     vector<Transaction> transactions;
     std::string trustee;
     double apy;
};

#endif
