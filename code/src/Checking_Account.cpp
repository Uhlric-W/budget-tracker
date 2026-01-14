#include "Checking_Account.h"

Checking_Account::Checking_Account(){
    id = -1;
    balance = 0;
    trustee = "";
    apy = 0;
}

Checking_Account::Checking_Account(int start_id, double start_balance, double start_apy, std::string start_trustee, vector<Transaction> start_transactions) {
    id = start_id;
    balance = start_balance;
    apy = start_apy;
    trustee = start_trustee;
    transactions = start_transactions;
}

int Checking_Account::get_id() {
    return id;
}

double Checking_Account::get_balance() {
    return balance;
}

std::string Checking_Account::get_trustee() {
    return trustee;
}

const vector<Transaction> Checking_Account::get_transactions() const {
    return transactions;
}

double Checking_Account::get_apy() {
    return apy;
}

void Checking_Account::set_id(int new_id) {
    id = new_id;
}

void Checking_Account::set_trustee(std::string new_trustee) {
    trustee = new_trustee;
}

void Checking_Account::set_balance(double new_balance) {
    balance = new_balance;
}

void Checking_Account::set_transactions(vector<Transaction>new_transactions) {
    transactions = new_transactions;
}

// positive amount values in transaction mean deposit while negative is withdrawl
std::string Checking_Account::process_transaction(Transaction* transaction) {
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