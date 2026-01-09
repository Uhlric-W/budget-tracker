#include "Transaction.h"

Transaction::Transaction(){
    amount = 0;
    id = -1;
    category = "";
    description = "";
    time(&date);
}

Transaction::Transaction(int in_id, double in_amount, string in_description, time_t in_date, string in_category){
    id = in_id;
    amount = in_amount;
    description = in_description;
    date = in_date;
    category = in_category;
}

int Transaction::get_id(){
    return id;
}

double Transaction::get_amount(){
    return amount;
}

string Transaction::get_category(){
    return category;
}

time_t Transaction::get_date(){
    return date;
}

string Transaction::get_description(){
    return description;
}

void Transaction::set_id(int new_id){
    id = new_id;
}

void Transaction::set_date(time_t new_date){
    date = new_date;
}

void Transaction::set_amount(double new_amount){
    amount = new_amount;
}

void Transaction::set_category(string new_category){
    category = new_category;
}

// returns data in this format id, amount, date, category, description
string Transaction::summarize(){
    string summary = to_string(id) + "," + to_string(amount) + "," +
        to_string(static_cast<long long>(date)) + "," + category + "," + description + '\n';
    return summary;
}