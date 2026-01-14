#include "Debt_Account.h"

Debt_Account::Debt_Account() {
    id = -1;
    balance = 0;
    creditor = "";
    interest_rate = 0;
}

Debt_Account::Debt_Account(int start_id, double start_balance, double start_interest_rate, std::string start_creditor, vector<Transaction> start_transactions) {
    id = start_id;
    balance = start_balance;
    interest_rate = start_interest_rate;
    creditor = start_creditor;
    transactions = start_transactions;
}

int Debt_Account::get_id(){
    return id;
}

double Debt_Account::get_balance() {
    return balance;
}

std::string Debt_Account::get_creditor() {
    return creditor;
}

const vector<Transaction> Debt_Account::get_transactions() const {
    return transactions;
}

double Debt_Account::get_interest_rate() {
    return interest_rate;
}

void Debt_Account::set_id(int new_id) {
    id = new_id;
}

void Debt_Account::set_balance(double new_balance) {
    balance = new_balance;
}

void Debt_Account::set_creditor(std::string new_creditor) {
    creditor = new_creditor;
}

void Debt_Account::set_transactions(vector<Transaction> new_transactions) {
    transactions = new_transactions;
}

// negative means more credit is used positive means payment on debt
std::string Debt_Account::process_transaction(Transaction* transaction) {
    double amount;

    if(transaction == nullptr) {
        return "no transaction information was provided";
    }

    amount = transaction -> get_amount();

    if(balance >= 0 && (balance - amount) < 0) {
        std::string return_string = "Leftover amount: " + std::to_string(amount - balance);
        balance = 0;
        transaction -> set_amount(amount - balance);
        transactions.push_back(*transaction);
        return return_string;
    } else if (balance < 0 && amount > 0) {
        return "Debt balance is negative";
    } else {
        balance -= amount;
        transactions.push_back(*transaction);
        return "accpeted";
    }
}
