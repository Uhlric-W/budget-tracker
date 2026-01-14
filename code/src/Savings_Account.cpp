#include "Savings_Account.h"

Savings_Account::Savings_Account(){
    id = -1;
    balance = 0;
    trustee = "";
    apy = 0;
}

Savings_Account::Savings_Account(int start_id, double start_balance, double start_apy, std::string start_trustee, vector<Transaction> start_transactions) {
    id = start_id;
    balance = start_balance;
    apy = start_apy;
    trustee = start_trustee;
    transactions = start_transactions;
}

int Savings_Account::get_id() {
    return id;
}

double Savings_Account::get_balance() {
    return balance;
}

std::string Savings_Account::get_trustee() {
    return trustee;
}

const vector<Transaction> Savings_Account::get_transactions() const {
    return transactions;
}

double Savings_Account::get_apy() {
    return apy;
}

void Savings_Account::set_id(int new_id) {
    id = new_id;
}

void Savings_Account::set_trustee(std::string new_trustee) {
    trustee = new_trustee;
}

void Savings_Account::set_balance(double new_balance) {
    balance = new_balance;
}

void Savings_Account::set_transactions(vector<Transaction>new_transactions) {
    transactions = new_transactions;
}

// positive amount values in transaction mean deposit while negative is withdrawl
std::string Savings_Account::process_transaction(Transaction* transaction) {
    double amount;

    if (transaction == nullptr) {
        return "Transaction was provided";
    }

    amount = transaction -> get_amount();

    if(balance >= 0 && (balance + amount) < 0) {
        return "Denied: Insufficient funds";
    } else if (balance < 0 && amount < 0) {
        return "Denied: Insufficient funds";
    } else {
        balance += amount;
        transactions.push_back(*transaction);
        return "Accepted";
    }
}