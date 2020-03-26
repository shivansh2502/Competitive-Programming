#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;

int main(){
    
    ll1 test, sub;

    cin>>test>>sub;

    while(test--){

        ll1 num;
        cin>>num;

        ll1 at[num];
        ll1 de[num];

        for(ll1 i=0;i<num;i++){
            cin>>at[i];
        }
        for(ll1 i=0;i<num;i++){
            cin>>de[i];
        }

        sort(de, de+num);
        sort(at, at+num);

        vector<ll1> vec;

        unordered_set<ll1> sett;

        ll1 i=0;

        ll1 j=0;


        sett.insert(at[0]);

        vec.push_back(at[0]);

        i++;

        while(i<num && j<num){

            if(de[j]>vec[i+j-1]){

                if(!sett.count(de[j])){

                    sett.insert(de[j]);

                }

                vec.push_back(de[j]);

                j++;

            }
            else{

                cout<<"NO"<<endl;

                break;

            }

            if(sett.count(at[i])){

                vec.push_back(at[i]);

                i++;
            }
            else{

                cout<<"NO"<<endl;

                break;

            }

        }

        if(i==num && j==num-1){

            if(de[j]>vec[i+j-1]){

                if(!sett.count(de[j])) sett.insert(de[j]);

                vec.push_back(de[j]);

                j++;

                cout<<"YES"<<endl;

            }
            else{

                cout<<"NO"<<endl;

            }

        }

    }
    
    return 0;
}
