//
//
//  Record.h
//  AccountsReceivable
//
//  Created by Maged Mahmoud on 4/27/16.
//  Copyright © 2016 Pat. All rights reserved.
//


#ifndef AccountsReceivable_Record_h
#define AccountsReceivable_Record_h

#include <iostream>
#include <iomanip>

using namespace std;


enum RecordType {
    Order = 0,
    Payment = 1
    };


class Record {
    
public:
    
    RecordType type;
    
    
    double cashAmount;
    char itemName[20];
    int itemQuantity;
    
    
    
    void description(){
        
        cout << "Record:\n---\nType: " << type;
        cout << "\nAmount: " << setprecision(2) << fixed << cashAmount;
        cout << "\nItem: " << itemName;
        cout << "\nQuantity: " << itemQuantity;
        cout << '\n';
    }
    
};

#endif