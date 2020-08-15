#include<bits/stdc++.h>
using namespace std;


class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty()) return -1;
   else return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty()) return -1;
   int k=s.top();
   s.pop();
   if(k>=minEle){
       return k;
   }
   else{
       int x= minEle;
       minEle= 2*minEle - k;
       return x;
   }

}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.size()==0){
       s.push(x);
       minEle=x;
   }
   else{
       if(x>=minEle){
           s.push(x);
       }
       else{
           s.push(2*x - minEle);
           minEle= x;
       }
   }
   
}

int main(){

    return 0;
}