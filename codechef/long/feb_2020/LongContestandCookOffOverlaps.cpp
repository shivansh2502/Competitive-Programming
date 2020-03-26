#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;

ll1 gWDay(ll1 y, ll1 m, ll1 d){
	int r = d                                                      
		+ ((153 * (m + 12 * ((14 - m) / 12) - 3) + 2) / 5) 
		+ (365 * (y + 4800 - ((14 - m) / 12)))
		+ ((y + 4800 - ((14 - m) / 12)) / 4)
		- ((y + 4800 - ((14 - m) / 12)) / 100)
		+ ((y + 4800 - ((14 - m) / 12)) / 400)
		- 32045;

	return (r+1)%7 ;
}  

bool isleap(ll1 y){  

    if (y % 400 == 0)  
        return true;  
  
    if (y % 100 == 0)  
        return false;  
   
    if (y % 4 == 0)  
        return true;


    return false;

}  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll1 test;

    cin>>test;

    unordered_map<ll1, ll1> um;

    ll1 count=0;

    for(ll1 ittr=1;ittr<=400;ittr++){

        ll1 xt=gWDay(ittr, 2, 1);
        
        if(xt==6){

            count++;

            um[ittr]=count;

            if(isleap(ittr)){

                ittr+=4;

            }
            else if(isleap(ittr+5)){

                ittr+=5;

            }
        }
        else if(xt==0  &&  !isleap(ittr)){

            count++;

            um[ittr]=count;

            ittr+=4;

        }
    }
    while(test--){

        ll1 month1, year1, month2, year2;

        cin>>month1>>year1>>month2>>year2;

        ll1 count12=0;
        
        if(month2<2){

            year2--;

        }
        
        if(month1>2){

            year1++;

        }
        
        ll1 ittr=year1;

        while(ittr<=year2){

            if((year2-ittr)>400){

                if((ittr+1)%400==0){

                    int xtest= (year2-ittr)/400;

                    count12+= (101*xtest);

                    ittr+= xtest*400;

                }
            }

            if(um.count(ittr%400)){

                count12++;

            }
            ittr++;
        }

        cout<<count12<<endl;


    }
    
    return 0;
}
