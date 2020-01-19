#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    int x;
    int y;
    int id;
    Car(int id, int x, int y){
        this->id=id;
        this->x=x;
        this->y=y;
    }

    int dist(){
        return x*x+y*y;
    }

    void print(){
        cout<<"ID "<<id<<" : ";
        cout<<x<<" "<<y<<endl;
    }
};

class CarCompare{
public:
    bool operator()(Car a, Car b){
        return a.dist() > b.dist();
    }
};

int main(){
    priority_queue <Car, vector<Car>, CarCompare> pq;

    int x[]={2, 5, 16, 8, 3, 6};
    int y[]={0, 17, 8, 12, 11, 4};

    for(int i=0;i<6;i++){
        Car c(i,x[i],y[i]);
        pq.push(c);
    }

    while(!pq.empty()){
        Car p=pq.top();
        p.print();
        pq.pop();
    }

    return 0;
}