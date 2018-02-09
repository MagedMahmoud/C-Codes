//
//  Customer.h
//  AccountsReceivable
//
//  Created by Maged Mahmoud on 4/27/16.
//  Copyright © 2016 Pat. All rights reserved.
//



#ifndef AccountsReceivable_Customer_h
#define AccountsReceivable_Customer_h

#include <iostream>
#include <iomanip>

using namespace std;

class Customer {
public:
    int customerNumber;
    char name[20];
    double balanceDue;
    int previousBalance;
 
    
    void description(){
        
        cout << "Customer:\n---\nCustomer Number: " << customerNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << setprecision(2) << fixed << balanceDue;
        cout << "\nPrevious \nBalance: " << setprecision(2) << fixed << previousBalance;
        cout << '\n';
    }
};


#endif