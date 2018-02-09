//
//  main.cpp
//  hw2
//
//  Created by Maged Mahmoud on 4/3/16.
//  Copyright © 2016 Pat. All rights reserved.


#include <iostream>
#include <fstream>
#include <sstream>
#include "Warehouse.h"
#include "Card.h"
using namespace std;

const int numWarehouses = 5;
string warehouseNames[numWarehouses] = {"NewYork", "LosAngeles", "Miami", "Houston", "Chicago"};

 
string warehousePrices(string card){
	string wareName = getCity(card);
	int location = card.find(wareName);
	return card.substr(location + wareName.length());
}


string getCity(string card){
    for (int i = 0; i < numWarehouses; i++) {
		if (card.find(warehouseNames[i]) != string::npos) {
            return warehouseNames[i];
        }
    }
	return "";
}


Warehouse *mostStock(Warehouse warehouses[], int asking, int item){

    Warehouse *workingWarehouse = NULL;
   
    for (int i = 0; i<numWarehouses; i++) {
        if (warehouses[i].quantities[item] >= asking) {Q
            if (workingWarehouse == NULL){
                workingWarehouse = &warehouses[i];
            }
            else if(warehouses[i].quantities[item] > (*workingWarehouse).quantities[item]){
                workingWarehouse = &warehouses[i];
            }
        }
    }

    return workingWarehouse;
}

int main(){
    Warehouse warehouses[numWarehouses];

    for (int i=0; i<numWarehouses; i++) {
        warehouses[i].name = warehouseNames[i];
        warehouses[i].quantities[0] = 0;
        warehouses[i].quantities[1] = 0;
        warehouses[i].quantities[2] = 0;
    }
	
	ifstream records;
    string fileName = "cards.txt";
	
	ifstream records; 
	records.open("cards.txt");

    int quantities[3];
	double prices[3];

    string pricesStr; 
	getline(records, pricesStr);
    pricesConvert(pricesStr, prices);
    
    while (!records.eof()) {

		string cardString;

		getline(records, cardString);


		if (cardString != "") { /
			
			Card card;

			card.type = cardString[0];
			card.city = getCity(cardString);

			//Store the quantities into the card.
			card.amount1 = quantities[0];
			card.amount2 = quantities[1];
			card.amount3 = quantities[2];


			//fetches and picks the right ware.
			Warehouse &workingWarehouse = *findWareName(card.city, warehouses);
			cout << card.print();

			//Handling of the shipments first
			if (card.type == 's') {
				workingWarehouse.quantities[0] += card.amount1;
				workingWarehouse.quantities[1] += card.amount2;
				workingWarehouse.quantities[2] += card.amount3;

				cout << workingWarehouse.print();

			}
				
			
			else if(card.type == 'o'){
				double price = 0;
				bool isFulfilled = true;

				for(int i=0; i <3; i++){
					//To check if there's enough
					if (workingWarehouse.quantities[i] >= quantities[i]) {
						price += quantities[i] * prices[i];
						workingWarehouse.quantities[i] -= quantities[i];

					}
					else{

						
						Warehouse *alternateWarehouse = mostStock(warehouses, i, quantities[i]);
					  
						
						if (alternateWarehouse == NULL || !(alternateWarehouse->quantities[i] >= quantities[i])) {
							isFulfilled = false;
						}

						
						else{
							(*alternateWarehouse).quantities[i] -= quantities[i];
							price += quantities[i] * (prices[i] * 1.1); // 10% fee if to another ware
							cout << quantities[i] << " of item #" << i+1 << " shipped from ";
							cout << (*alternateWarehouse).name << " to " << workingWarehouse.name << "." << endl;

							cout << alternateWarehouse->print();
						}


					}
				}

				cout << workingWarehouse.print();
				cout << "TOTAL: $" << price << endl;

				if(!isFulfilled){ //checks if order is done
						cout << "ALERT: Order Unfulfilled" << endl;
				}

			}

		}

    }
    return 0;
}



