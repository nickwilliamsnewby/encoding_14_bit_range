#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <bitset> // memcpy
using namespace std;

//reads input ints from test_en.txt and writes encoded strings 
//to test_encoded.txt

string encode(short int shmumber){
    if (shmumber < -8192 or shmumber > 8191){
        return "number out of range for this encoder";
    } else {
        shmumber = shmumber + 8192;
    }
    short int num = shmumber << 1;
    for (int ix = 16; ix > 8; ix--){
        int x = (num >> ix) & 1U;
        shmumber ^= (-x ^ shmumber) & (1UL << ix);
    }
    shmumber &= ~(1UL << 7);
    bitset<16> n(shmumber);
    cout << "after: " << n << endl;
    stringstream hxstring;
    hxstring <<  hex << n.to_ulong();
    cout << hxstring.str() <<endl;
    return hxstring.str();
}


int main(){
    short int temp14;
    ifstream tests;
    tests.open("test_en.txt");
    ofstream myfile;
    myfile.open ("test_encoded.txt");
    while(tests >> temp14){
        //cout << temp14 << endl;
        myfile << encode(temp14) <<"\n";
    }
    myfile.close();
    tests.close();
    
    return 0;
}