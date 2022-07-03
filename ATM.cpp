//
// Created by IonCicala on 03/07/2022.
//

#include <iostream>
#include "ATM.h"

ATM::ATM(): bill5(0), bill20(0), bill50(0) {
    totalAmount = 0;
}

void ATM::refill(int new5, int new20, int new50) {
    if(new5 >=0 && new20 >= 0 && new50 >= 0){
        if(new5%5 == 0){
            this->bill5+=new5/5;
            totalAmount+=new5;
        }else{
            std::cout << "Please insert only 5 notes";
        }
        if(new20%20 == 0){
            this->bill20 += new20/20;
            totalAmount +=new20;
        }else{
            std::cout << "Please insert only 20 notes";
        }
        if(new50%50 == 0){
            this->bill50 += new50/50;
            totalAmount +=new50;
        }else{
            std::cout << "Please insert only 50 notes";
        }

    }


}

bool ATM::cash(int amount) {
    if(totalAmount >= amount && amount > 0 && amount%5 == 0 ){
        int bill50nr{};
        int bill20nr{};
        int bill5nr{};
        if(checkOfWithdraw(amount,bill5nr, bill20nr,bill50nr)){
            totalAmount -=amount;
            bill5 -= bill5nr;
            bill20 -=bill20nr;
            bill50 -= bill50nr;
            std::cout << "The total amount:" << amount <<" was successful withdraw in 50 notes:" << bill50nr << " ,20 notes:"<<bill20nr << " ,5 notes:" << bill5nr << std::endl;
            return true;
        }else{
            std::cout << "The amount can not withdraw due to not enough notes, available notes are 5 notes "<< bill5 << " 20 notes " << bill20 << " 50 notes " << bill50 << std::endl;
            return false;
        }
    }
    std::cout << "Not enough resources in ATM, Please insert an amount lower then: " << totalAmount << std::endl;
    return false;
}

int ATM::getTotalAmount() const {
    return totalAmount;
}

bool ATM::checkOfWithdraw(int amount, int & nrbill5, int & nrbill20, int & nrbill50) {
int requireBill50 ;
int requireBill20{};
int requireBill5{};
int availableBill50{};
int availableBill20{};
int availableBill5{};

if(bill50 > 0 && amount > 0){
    requireBill50 = (amount - (amount%50))/50;
    availableBill50 = (bill50 >= requireBill50)? requireBill50: bill50;
    nrbill50 = availableBill50;
    amount = amount - availableBill50*50;

}
if(bill20 > 0 && amount > 0){

   requireBill20 = (amount - amount%50%20)/20;
   availableBill20 = (bill20 >= requireBill20)? requireBill20: bill20;
   nrbill20 = availableBill20;
   amount = amount - availableBill20*20;

}
if(bill5 > 0 && amount > 0){
    requireBill5 = (amount - amount%50%20%5)/5;
    availableBill5 = (bill5 >= requireBill5)? requireBill5: bill5;
    nrbill5 = availableBill5;
    amount = amount - availableBill5*5;}

return amount == 0;
}


