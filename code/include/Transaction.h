#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

class Transaction {
    public:
     Transaction();
    
     //getters and setters for each variable
     double get_amount();

     time_t get_date();

     string get_category();

     int get_id();

     string get_description();

     void set_id(int new_id);

     void set_date(time_t new_date);

     void set_amount(double new_amount);

     void set_category(string new_category);
     
     //creates human readable string of all of the information contained in the transaction
     string summarize();

    private:
     double amount;
     time_t date;
     string category; // label to sort expenses and transactions by types of transactions
     int id;
     string description;
};

#endif