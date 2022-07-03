//
// Created by IonCicala on 03/07/2022.
//

#ifndef C___ATM_H
#define C___ATM_H


class ATM {
public:
int bill5;
int bill20;
int bill50;
int totalAmount;

public:
    explicit ATM();
    void refill(int new5, int new20, int new50);
    bool cash(int amount);
    bool checkOfWithdraw(int amount, int & nrbill5, int & nrbill20, int & nrbill50);

    int getTotalAmount() const;

};


#endif //C___ATM_H
