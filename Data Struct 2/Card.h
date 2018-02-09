//
//  card.h
//  hw2
//
//  Created by Maged Mahmoud on 4/3/16.
//  Copyright © 2016 Pat. All rights reserved.

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
	public:
		char type;
		string city;
		int amt1 = 0;
		int amt2 = 0;
		int amt3 = 0;

		void print(){
			
			string heading = type == 'o' ? "~~ Order: ~~\n" : "~~ Shipment: ~~\n";
			cout << heading << city << '\t' << amt1 << '\t' << amt2 << '\t' << amt3 << '\n';

		}
};
#endif
