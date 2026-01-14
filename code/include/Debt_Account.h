#ifndef DEBT_ACCOUNT_H_
#define DEBT_ACCOUNT_H_

#include "IAccount.h"
#include <string>
#include <vector>
#include "Transaction.h"

class Debt_Account : public IAccount {
    public:
     Debt_Account();

     Debt_Account(int start_id, double start_balance, double start_interest_rate, std::string start_creditor, vector<Transaction> start_transactions);
     
     int get_id() override;

     double get_balance() override;

     std::string get_creditor();

     const vector<Transaction> get_transactions() const;

     std::string process_transaction(Transaction* transaction);

     double get_interest_rate();

     void set_id(int new_id) override;

     void set_balance(double new_balance) override;

     void set_interest_rate(double new_interest_rate);

     void set_creditor(string new_creditor);

     void set_transactions(vector<Transaction> new_transactions);
    
    private:
     int id;
     double balance;
     vector<Transaction> transactions;
     std::string creditor;
     double interest_rate;

};

#endif
