//Maged Mahmoud
//Professor Ziegler
//Homework Program #2


// A program to calculate the value of y

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    
    double x,y;
    
    
    
    ofstream outfile("c:\\mypgms.txt");
    
    outfile<< "Table of function values " <<endl <<endl;
    outfile<< "VALUE OF X  VALUE OF Y    STATUS"<< endl;
    for (x = -3; x <=4; x = x + .05)
        
    {
        y = ((9*x)*(9*x)*(9*x)-(27*x)*(27*x)-(4*x)+(12))/(sqrt((3*x)*(3*x)+(1)))+ abs(5-(x)*(x)*(x)*(x));
        outfile<< "X = "<< x << "          Y = "<< y;        if (y>0)
           outfile<< "    Y is Positive"<< endl;
        if (y < 0)
            outfile<< "    Y is Negative"<< endl;
        if (y=0)
            outfile << "   Y equals 0"<<endl;
       
    }
    outfile<< endl<< " The table is finished"<< endl;
    
    
    outfile.close();
    
    return 0;
}