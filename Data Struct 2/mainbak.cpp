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


bool openOutputStream(ofstream &stream, string fileName){

    stream.open(fileName.c_str());

    if (!stream.good()) {
        return false;
    }

    return true;
}

bool openInputStream(ifstream &stream, string fileName){

    stream.open(fileName.c_str());

    if (!stream.good()) {
        return false;
    }

    return true;
}

void closeOutputStream(ofstream &stream){
}

void closeInputStream(ifstream &stream){
    stream.close();
}

bool PriceStringToArray(string input, double *);
string getCityName(string);
string warehousePrices(string card);
bool loadQuantitiesFromString(string, int[], const int);
Warehouse *warehouseForNameFromArray(string , Warehouse [], int);
Warehouse *warehouseMostStockThatFillsItemAndAmount(Warehouse[], int, int, int);
bool warehouseHasDesiredAmountOfItem(Warehouse, int, int);

const int numWarehouses = 5;
string warehouseNames[numWarehouses] = {"New York", "Los Angeles", "Miami", "Houston", "Chicago"};

int main() {
    Warehouse warehouses[numWarehouses];


    ifstream recordsFile;
    string fileName = "cards.txt";

    if(!openInputStream(recordsFile, fileName)){ /
        cout << "Could not open " << fileName << endl;
    }

    else {

        double prices[3];
        int quantities[3];

        string pricesString;

        getline(recordsFile, pricesString);

        PriceStringToArray(pricesString, prices);

        while (!recordsFile.eof()) {

            string cardString;

            getline(recordsFile, cardString);

            if (cardString != "") {
                Card card;

                card.cardType = cardString[0];
                for (int i = 0; i < numWarehouses; i++) {

                    if (card.warehouseNames[i] != string::npos) {
                        card.city = warehouseNames[i];
                    }
                }
               

                card.amount1 = quantities[0]; //insert the quantities into the cards
                card.amount2 = quantities[1];
                card.amount3 = quantities[2];

                Warehouse &workingWarehouse = *warehouseForNameFromArray(card.city, warehouses, numWarehouses);

                cout << card.description();

                //handle the shipments
                if (card.cardType == 's') {


                    workingWarehouse.quantities[0] += card.amount1;
                    workingWarehouse.quantities[1] += card.amount2;
                    workingWarehouse.quantities[2] += card.amount3;

                    cout << workingWarehouse.description();

                }


                //the orders
                else if(card.cardType == 'o'){

                    double price = 0;
                    bool orderFilled = true;

                    for(int i=0; i <3; i++){

                    if (warehouseHasDesiredAmountOfItem(workingWarehouse, quantities[i], i)) {

                        /
                            price += quantities[i] * prices[i];
                            workingWarehouse.quantities[i] -= quantities[i];

                        }


                    else{

                        Warehouse *alternateWarehouse = warehouseMostStockThatFillsItemAndAmount(warehouses, numWarehouses, i, quantities[i]);

                    

                        bool alternateWarehouseIsSufficient = warehouseHasDesiredAmountOfItem((*alternateWarehouse), quantities[i], i);

                     
                        if (alternateWarehouse == NULL || !alternateWarehouseIsSufficient) orderFilled = false;


                    /

                        else{

                          
                            price += quantities[i] * (prices[i] * 1.1);
                            (*alternateWarehouse).quantities[i] -= quantities[i];

                       
                            cout << quantities[i] << " of item " << i+1 << " shipped from ";
                            cout << (*alternateWarehouse).name << " to " << workingWarehouse.name << "." << endl;

                         

                            cout << (*alternateWarehouse).description();
                        }


                    }
                }

                cout << workingWarehouse.description();


                cout << "Price: $" << price << endl;

                if(!orderFilled){
                    cout << "Order Unfulfilled" << endl;
                }

              }

        }
    }
    }

    return 0;
}



bool PriceStringToArray(string input, double *buffer){

    size_t position = 0;

    int indexForBuffer = 0;

    while (position < input.length()-1) {

        size_t positionOfDollarSign = input.find("$", position);

     
        if (positionOfDollarSign == string::npos) {
            position = input.length();
            break;
        }

        size_t positionOfTrailingSpace = input.find(" ", positionOfDollarSign-1);

       

        if(positionOfTrailingSpace == string::npos){

        

            positionOfTrailingSpace = input.length()-1;
        }



        string priceValueAsString;

        priceValueAsString = input.substr(positionOfDollarSign+1, positionOfTrailingSpace-positionOfDollarSign);


        istringstream stringToDoubleConverter(priceValueAsString);

        if(!(stringToDoubleConverter >> buffer[indexForBuffer])){
            return false;
        }

        position = positionOfTrailingSpace;

        indexForBuffer++;
    }

    return true;
}


string cityNameFromCard(string card){
    for (int i = 0; i < numWarehouses; i++) {

        if (card.find(warehouseNames[i]) != string::npos) {
            return warehouseNames[i];
        }
    }

    return "";
}


string pricesForWarehouse(string card){

    string warehouseName = cityNameFromCard(card);

    size_t locationOfString = card.find(warehouseName);

    return card.substr(locationOfString+warehouseName.length());
}



bool loadQuantitiesFromString(string pricesString, int quantities[], const int numberOfQuantities){

    istringstream conversionStream(pricesString);

    for (int i = 0; i < numberOfQuantities; i++) {
        if(!(conversionStream >> quantities[i])){
            return false;
        }
    }

    return true;
}

Warehouse *warehouseForNameFromArray(string name, Warehouse warehouses[], int numWarehouses){

    Warehouse *workingWarehouse = NULL;

    for (int i = 0; i<numWarehouses; i++) {
        if (warehouses[i].name == name) {
            workingWarehouse = &warehouses[i];
        }
    }

    return workingWarehouse;
}


bool warehouseHasDesiredAmountOfItem(Warehouse warehouse, int desiredAmount, int item){
    return warehouse.quantities[item] >= desiredAmount;

}


Warehouse *warehouseMostStockThatFillsItemAndAmount(Warehouse warehouses[], int numWarehouses, int desiredAmount, int item){

    Warehouse *workingWarehouse = NULL;
  
    for (int i = 0; i<numWarehouses; i++) {
        if (warehouses[i].quantities[item] >= desiredAmount) {
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
