#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll1 test;
    cin>>test;

    while(test--){
        ll1 number,pract;
        
        cin>>number>>pract;

        ll1 array[number];

        for(ll1 i=0;i<number;i++){
            cin>>array[i];
        }

        vector<ll1> vec;

        bool flag1=false;

        if(pract%array[0] ==0){

            vec.push_back(0);

            for(ll1 ittr=1 ; ittr<number ; ittr++){

                if(pract%array[ittr]!=0 || array[ittr]%array[ittr-1]!=0){

                    flag1=true;

                    if(array[ittr]%array[ittr-1]!=0) {

                        vec.push_back(1);

                        vec[ittr-1]= ((pract-array[ittr])/array[ittr-1]) + 1;

                    }
                    else{

                        vec.push_back(pract/array[ittr] + 1);

                    }

                    break;

                }
                else{

                    vec.push_back(0);

                }
            }
        }
        else{

            vec.push_back((pract/array[0]) + 1);
            flag1=true;

        }

        if(flag1==false) cout<<"NO"<<endl;

        else{

            cout<<"YES ";

            for(ll1 ittr=0;ittr<number;ittr++){

                if(ittr<vec.size()) cout<<vec[ittr]<<" ";

                else cout<<"0"<<" ";

            }

            cout<<endl;

        }
    }
    return 0;
}
