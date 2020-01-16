#include<iostream>
#include "hashtable.h"
using namespace std;

int main(){

    Hashtable<int> h(7);
    h.insert("mango", 100);

    // h.print();
    h["mango"]=120;
    h.print();
    cout<<h["mango"]<<endl;
    // h.erase("Apple");
    // h.print();
    return 0;
}