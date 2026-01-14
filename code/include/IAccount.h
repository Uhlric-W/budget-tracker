#ifndef IACCOUNT_H_
#define IACCOUNT_H_

class IAccount {
    public:
     virtual int get_id() = 0;
     virtual void set_id(int new_id) = 0;
     virtual double get_balance() = 0;
     virtual void set_balance(double new_balance) = 0;
     virtual ~IAccount() = default;
};

#endif
