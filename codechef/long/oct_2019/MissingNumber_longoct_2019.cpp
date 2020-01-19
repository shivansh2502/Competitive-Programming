#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll converter(char a){
    if(a>=65 && a<=90){
        return a-65+10;
    }
    return a-48;
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll b[n]={0};
        vector<string> v;
        for(ll i=0;i<n;i++){
            cin>>b[i];
            string s;
            cin>>s;
            v.push_back(s);
        }
        unordered_map<ll,ll> hash;
        for(ll i=0;i<n;i++){
            if(b[i]!=-1){
                ll dec=0;
                bool flag=true;
                for(unsigned ll j=0;j<v[i].length();j++){
                    if(converter(v[i][j])>=b[i] || pow(b[i],v[i].length()-1-j)>1000000000001){
                        flag=false;
                        break;
                    }
                    else{
                        dec+= converter(v[i][j]) * pow(b[i],v[i].length()-1-j);
                    }
                }
                if(flag==true){
                    auto it=hash.find(dec);
                    if(it!=hash.end()){
                        it->second++;
                    }
                    else{
                        hash.insert(make_pair(dec,1));
                    }
                }  
            }
            else{
                for(ll k=2;k<=36;k++){
                    ll dec=0;
                    bool flag=true;
                    for(unsigned ll j=0;j<v[i].length();j++){
                        if(converter(v[i][j])>=k || pow(b[i],v[i].length()-1-j)>1000000000001){
                            flag=false;
                            break;
                        }
                        else{
                            dec+=converter(v[i][j]) * pow(k,v[i].length()-1-j);
                        }
                    }
                    if(flag==true){
                       auto it=hash.find(dec);
                        if(it!=hash.end()){
                            it->second++;
                        }
                        else{
                            hash.insert(make_pair(dec,1));
                        }
                    }     
                }
            }
        }
        ll min=1000000000001;
        for(auto i:hash){
            if(i.second==n && i.first<min){
                min=i.first;
            }
        }
        if(min==1000000000001){
            cout<<-1<<endl;
        }
        else{
            cout<<min<<endl;
        }
    }
    return 0;
}