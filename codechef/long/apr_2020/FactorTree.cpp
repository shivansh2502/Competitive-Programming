#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;



ll mo = 1000000007;




class graph{


    unordered_map<ll, list<ll>> adjL;

public:


    void add(ll u, ll v, bool bidir=true){


        adjL[u].push_back(v);


        if(bidir){
            adjL[v].push_back(u);
        }


    }



    bool dfsHelper(ll sr, ll des, map<ll, bool> &visited1, vector<ll> &vec){


        visited1[sr]=true;

        if(sr== des) return true;


        for(auto i : adjL[sr]){

            if(!visited1[i]){

                bool flag=dfsHelper(i, des, visited1, vec);

                if(flag){

                    vec.push_back(i);
                    return true;

                }

            }

        }
        return false;
    }

    vector<ll> dfs(ll sr, ll des){


        map<ll, bool> visited1;


        vector<ll> vec;

        vec.push_back(sr);

        if(sr==des){

            return vec;

        }
        else bool f=dfsHelper(sr, des, visited1, vec);
        return vec;
    }

};
 
 

const ll MA = 1000001; 

ll factor[MA] = { 0 }; 

void PrimeFactors(){ 
    factor[1] = 1; 
    for (ll i = 2; i < MA; i++) factor[i] = i; 
    for (ll i = 4; i < MA; i += 2) factor[i] = 2; 
    for (ll i = 3; i * i < MA; i++) { 
        if (factor[i] == i) { 
            for (ll j = i * i; j < MA; j += i) { 
                if (factor[j] == j) factor[j] = i; 
            } 
        } 
    }
} 
  
void Factors(ll n1, unordered_map<ll, ll>&unord){ 
    if (n1 == 1) return;
    
    ll dupli = factor[n1]; 

    ll co = 1; 

    unord[dupli]++;







    ll j = n1 / factor[n1]; 


    while (j != 1){ 


        if (factor[j] == dupli){
            co += 1; 
            unord[dupli]++;
        } 


        else { 
            dupli = factor[j]; 
           
            co = 1;
            unord[dupli]++;
        } 


        j = j / factor[j];


    } 

   
}



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    PrimeFactors();
    ll t;
    cin>>t;
    


    while(t--){



        ll n1;
        cin>>n1;

        graph g1;



        for(ll i=0; i<(n1-1);i++){


            ll x1, y1;
            cin>>x1>>y1;
            g1.add(x1, y1, true);


        }

        ll arr[n1];


        for(ll i=0; i<n1;i++){


            cin>>arr[i];


        }





        ll q1;
        cin>>q1;


        while(q1--){


            ll x2, y2;
            cin>>x2>>y2;


            vector<ll> v=g1.dfs(x2, y2);




            unordered_map<ll, ll> unord;
    
            for(auto i:v){
                Factors(arr[i-1],unord);
            }


            ll finalans=1;


            for(auto i:unord){

                finalans= (finalans%mo * (i.second+1)%mo)%mo;

            }
        
            cout<<finalans<<endl;
        }
    }
    
    return 0;
}


