#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long ll;


int main(){

    ll test;
    cin>>test;
    
    while(test--)
    {
        ll next;
        cin>>next;

        ll l[100006]={0};
        ll u[100006]={0};

        ll final_ans=INT_MAX;

        set<ll> sett;

        for(ll it=0;it<next;it++)
        {
            cin>>l[it]>>u[it];
            sett.insert(u[it]);
        }

        sort(l , l+next);
        sort(u , u+next);

        unordered_map<ll,ll> map;


        ll it = 1, jt = 0; 


        ll numbers=1;

        
        map[l[0]]=1;

        while(it<next && jt<next)
        {
            if(l[it]<= u[jt])
            {
                numbers++;
                map[l[it]]= numbers;
                it++;

            }
            else
            {
                map[u[jt]]=numbers;
                numbers--;
                jt++;
            }
        }

        while(it<next){
            numbers++;
            map[l[it]]= numbers;
            it++;
        }
        
        while(jt<next){
            map[u[jt]]=numbers;
            numbers--;
            jt++;
        }

        for(auto i: map){
            cout<<i.first<<" "<<i.second<<endl;
        }
        

        for(auto it:sett)
        {
            if(it>=l[next-1])
            {
                break;   
            }
            if(it!=u[next-1])
            {
                final_ans=min(final_ans, map[it]-1); 
            }
        }


        if(final_ans==INT_MAX)
        {
            cout<<-1<<endl;
        }

        else
        {
            cout<<final_ans<<endl;
        }
       
    }

    return 0;
}