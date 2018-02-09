//
//  warehouse.h
//  hw2
//
//  Created by Maged Mahmoud on 4/3/16.
//  Copyright © 2016 Pat. All rights reserved.

#ifndef WAREHOUSE.H
#define WAREHOUSE.H

#include <iostream>

using namespace std;

class Warehouse {
	public:
		string name;
		int quantities[3];

		void print(){ 
			cout << name << '\t' << quantities[0] << '\t' << quantities[1] << '\t' << quantities[2] << '\n';
		}
		
};

#endif
