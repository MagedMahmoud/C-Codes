//Maged Mahmoud
//Professor Ziegler
//Homework Program # 1


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main () {
    char mine [5];
    cout << "enter a letter ";
    for (int i = 0; i < 6; i ++)
    cin >> mine;
    
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << mine;
        myfile.close();
    }
    {
        string line;
        ifstream myfile ("example.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                for (int i = 0; i < 6; i ++)
                cout << line[i] << "\n";
            }
            myfile.close();
        }
        
        else cout << "Unable to open file"; 
        
        return 0;
    }
}
    
    
