//  Maged Mahmoud
//  main.cpp
//  HOME3
//



#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class LinkedList
{
    
private:
    
    struct ListNode {
        int quantity;
        double price;
        ListNode *next;
        ListNode (int quantity,double price,ListNode *next = NULL) :
        quantity(quantity), price(price), next(next) {};
    };
    
    ListNode *head;
    ListNode *rear;
    
public:
    
    LinkedList(): head(NULL), rear(NULL) {}
    
    int getQ () {
        return head->quantity;
    }
    double getP () {
        return head->price;
    }
    void getNext() {
        head = head->next;
    }
    void setQ (int q) {
        head->quantity = q;
    }
    void setP (double p) {
        head->price = p;
    }
    
    bool isEmpty () {
        if (head == NULL) return true;
        else return false;
    }
    
    void push (int quantity, int price) {
        if (head == NULL) {
            head = new ListNode(quantity, price);
            rear = head;
        } else {
            rear->next = new ListNode(quantity, price);
            rear = rear->next;
        }
    }
    
    void pop () {
        ListNode *temp;
        
        if (head == NULL) {
            cout << "The queue is empty.\n";
            exit(1);
        } else {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

LinkedList data;

int main()
{
    
    char orderType;
    int q, d = 1;
    int remainder;
    int dCount = 0;
    double p, salesPrice, totalSales;
    
    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cout << endl << "ERROR: Unable to open file" << endl;
        exit(1);
    }
    
    ofstream outfile("sales.txt");
    outfile.setf(ios::fixed, ios::floatfield);
    if (!outfile.is_open()) {
        cout << endl << "ERROR: Unable to save file" << endl;
        exit(1);
    }
    
    
    infile >> orderType;
    
    while (!infile.eof()) {
        
        
        if (orderType == 'R') {
            
            infile >> q >> p;
            
            
            data.push(q, p);
            
            outfile.precision(2);
            outfile << q << " received at $" << p << endl;
        }
        
        else if (orderType == 'P') {
            
            infile >> d;
            
            dCount = 2;
            outfile << "The next two customers will recieve a " << d;
            outfile << "% dicsount.";
            outfile << endl;
            
        }
        
        //Sale
        
        else if (orderType == 'S') {
            
            infile >> q;
            
            if (q <= data.getQ() ) {
                if (dCount != 0) {
                    salesPrice = data.getP() * 1.3 * q * (d * .01);
                    outfile << endl << " sold " << q << " @ $" ;
                    outfile << data.getP() * 1.3 * (d * .01);
                    outfile << " each";
                    outfile << "    TOTAL: $" << salesPrice << endl;
                    dCount--;
                }
                
                else {
                    salesPrice = data.getP() * 1.3 * q;
                    outfile << q << " widgets sold at ";
                    outfile << data.getP() * 1.3;
                    outfile << " each" << "    Sales: $";
                    outfile << salesPrice << endl;
                }
                
                data.setQ (data.getQ() - q);
                
                if (data.getQ() == 0) {
                    data.pop();
                }
            }
            
            else {
                outfile << endl << "The remaining "<< q <<" widgets is not available" << endl;
                totalSales = 0;
                
                while (q > 0) {
                    
                    if (q >= data.getQ()) {
                        
                        remainder = (q - data.getQ());
                        
                        if (dCount != 0) {
                            salesPrice = data.getP() * 1.3 * (q-remainder)*(d *.01);
                            outfile << data.getQ() << " at ";
                            outfile << data.getP() * 1.3 * (d * .01);
                            outfile << " each" << "    Sales: $";
                            outfile << salesPrice << endl;
                            dCount--;
                        }
                        
                        else {
                            salesPrice = data.getP() * 1.3 * (q - remainder);
                            outfile << data.getQ() << " at ";
                            outfile << data.getP() * 1.3 << " each";
                            outfile << "    Sales: $" << salesPrice << endl;
                        }
                        
                        totalSales += salesPrice;
                        
                        data.pop();
                        
                        if (data.isEmpty() && remainder != 0) {
                            outfile << "Remainder of " << remainder;
                            outfile << " widgets not available";
                            outfile << endl;
                            q = 0;
                        } else {
                            q = remainder;
                        }
                        
                        
                    }  
                    
                    
                    else {
                        
                        if (dCount != 0) {
                            salesPrice = data.getP() * 1.3 * q * (d * .01);
                            outfile << endl << q << " widgets sold at ";
                            outfile << data.getP() * 1.3 * (d * .01);
                            outfile << " each" << "    Sales: $";
                            outfile << salesPrice << endl;
                            dCount--;
                        }
                        
                        else {
                            data.setQ (data.getQ() - q);
                            double temp = data.getP();
                            if (data.getQ() == 0) {
                                data.pop();
                            }
                            salesPrice = temp * 1.3 * q;
                            outfile << q << " at " << temp * 1.3;
                            outfile << " each" << "    Sales: $";
                            outfile << salesPrice << endl;
                        }
                        
                        totalSales += salesPrice;
                        q = 0;
                        
                    }
                }
                
                outfile << "           Total Sales: $" << totalSales;
                outfile << endl << endl;
                
            }
            
        }
        
        infile >> orderType;
    }
    
    while (!data.isEmpty()) {
        outfile << "OVERSTOCK" <<endl;
        outfile << endl << data.getQ() << "left @ $";
        outfile << data.getP() << endl;
        data.getNext();
    }
    
    infile.close();
    outfile.close();
    return 0;
}
