#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


ll dpp0[100000];
ll dpp1[100000];
ll dppa[100000];
ll dppA[100000];

ll M = 998244353;

ll invers(ll a) {
    ll t1 = a, r1 = 1, k1 = M - 2;
    while (k1) {

        if (k1 & 1) r1 = (long long) r1 * t1 % M;

        t1 = (long long) t1 * t1 % M;

        k1 >>= 1;

    }

    return r1;
}


ll probs(ll x, ll y, char finans, ll * symbol1, string &str){

    if(x==y && str[x]=='#'){

        if(finans=='0'){
            dpp0[x]=((1%M)*(invers(4)%M))%M;
            return dpp0[x];
        }

        else if(finans=='a'){
            dppa[x]=((1%M)*(invers(4)%M))%M;
            return dppa[x];
        }

        else if(finans=='1'){
            dpp1[x]=((1%M)*(invers(4)%M))%M;
            return dpp1[x];
        }

        else if(finans=='A'){
            dppA[x]=((1%M)*(invers(4)%M))%M;
            return dppA[x];
        }

    }

    if(dpp1[x]!=0 && finans=='1') return dpp1[x]%M;
    if(dppa[x]!=0 && finans=='a') return dppa[x]%M;
    if(dpp0[x]!=0 && finans=='0') return dpp0[x]%M;
    if(dppA[x]!=0 && finans=='A') return dppA[x]%M;
    
    ll i=symbol1[x];

    if(str[i]=='^'){
        if(finans=='0'){
            ll e4= probs(i+1, y-1, 'a', symbol1, str);
            ll e5= probs(x+1, i-1, 'A', symbol1, str);
            ll e6= probs(i+1, y-1, 'A', symbol1, str);
            ll e7= probs(x+1, i-1, '1', symbol1, str);
            ll e8= probs(i+1, y-1, '1', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, '0', symbol1, str);
            ll e3= probs(x+1, i-1, 'a', symbol1, str);

            dpp0[x]=((e1*e2)%M+(e3*e4)%M+(e5*e6)%M+(e7*e8)%M)%M;
            return dpp0[x];
        }
        else if(finans=='1'){
            ll e4= probs(i+1, y-1, '0', symbol1, str);
            ll e5= probs(x+1, i-1, 'a', symbol1, str);
            ll e6= probs(i+1, y-1, 'A', symbol1, str);
            ll e7= probs(x+1, i-1, 'A', symbol1, str);
            ll e8= probs(i+1, y-1, 'a', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, '1', symbol1, str);
            ll e3= probs(x+1, i-1, '1', symbol1, str);

            dpp1[x]=((e1*e2)%M+(e3*e4)%M+(e5*e6)%M+(e7*e8)%M)%M;
            return dpp1[x];
        }
        else if(finans=='a'){
            ll e4= probs(i+1, y-1, '0', symbol1, str);
            ll e5= probs(x+1, i-1, '1', symbol1, str);
            ll e6= probs(i+1, y-1, 'A', symbol1, str);
            ll e7= probs(x+1, i-1, 'A', symbol1, str);
            ll e8= probs(i+1, y-1, '1', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, 'a', symbol1, str);
            ll e3= probs(x+1, i-1, 'a', symbol1, str);

            dppa[x]=((e1*e2)%M+(e3*e4)%M+(e5*e6)%M+(e7*e8)%M)%M;
            return dppa[x];
        }
        else if(finans=='A'){
            ll e4= probs(i+1, y-1, '0', symbol1, str);
            ll e5= probs(x+1, i-1, '1', symbol1, str);
            ll e6= probs(i+1, y-1, 'a', symbol1, str);
            ll e7= probs(x+1, i-1, 'a', symbol1, str);
            ll e8= probs(i+1, y-1, '1', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, 'A', symbol1, str);
            ll e3= probs(x+1, i-1, 'A', symbol1, str);

            dppA[x]=((e1*e2)%M+(e3*e4)%M+(e5*e6)%M+(e7*e8)%M)%M;
            return dppA[x];
        }
    }

    else if(str[i]=='&'){
        
        if(finans=='0'){
            ll e5= probs(x+1, i-1, 'a', symbol1, str);
            ll e6= probs(i+1, y-1, 'a', symbol1, str);
            ll e7= probs(x+1, i-1, 'A', symbol1, str);
            ll e8= probs(i+1, y-1, 'A', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, '0', symbol1, str);
            ll e3= probs(x+1, i-1, '1', symbol1, str);
            ll e4= probs(i+1, y-1, '1', symbol1, str); 

            dpp0[x]=((e1*e2)%M+(e1*e4)%M+(e1*e6)%M+(e1*e8)%M+(e3*e2)%M+(e5*e2)%M+(e7*e2)%M+(e5*e8)%M+(e6*e7)%M)%M;
            return dpp0[x];
        }
        else if(finans=='1'){

            ll e2= probs(i+1, y-1, '1', symbol1, str);
            ll e1= probs(x+1, i-1, '1', symbol1, str);
            
            dpp1[x]=(e1*e2)%M;
            return dpp1[x];
        }
        else if(finans=='a'){

            ll e3= probs(x+1, i-1, 'a', symbol1, str);
            ll e4= probs(i+1, y-1, '1', symbol1, str);
            ll e1= probs(x+1, i-1, '1', symbol1, str);
            ll e2= probs(i+1, y-1, 'a', symbol1, str);
            
            dppa[x]=((e1*e2)%M+(e3*e4)%M+(e3*e2)%M)%M;
            return dppa[x];
        }
        else if(finans=='A'){
            ll e3= probs(x+1, i-1, 'A', symbol1, str);
            ll e4= probs(i+1, y-1, '1', symbol1, str);
            ll e1= probs(x+1, i-1, '1', symbol1, str);
            ll e2= probs(i+1, y-1, 'A', symbol1, str);
            
            dppA[x]=((e1*e2)%M+(e3*e4)%M+(e3*e2)%M)%M;
            return  dppA[x];
        }
    }
    else if(str[i]=='|'){
        if(finans=='0'){
            ll e2= probs(i+1, y-1, '0', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);

            dpp0[x]=(e1*e2)%M;
            return  dpp0[x];
        }
        else if(finans=='1'){
            ll e5= probs(x+1, i-1, 'a', symbol1, str);
            ll e6= probs(i+1, y-1, 'a', symbol1, str);
            ll e7= probs(x+1, i-1, 'A', symbol1, str);
            ll e8= probs(i+1, y-1, 'A', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, '0', symbol1, str);
            ll e3= probs(x+1, i-1, '1', symbol1, str);
            ll e4= probs(i+1, y-1, '1', symbol1, str);
           
            dpp1[x]=((e3*e2)%M+(e3*e4)%M+(e3*e6)%M+(e3*e8)%M+(e1*e4)%M+(e5*e4)%M+(e7*e4)%M+(e5*e8)%M+(e7*e6)%M)%M;
            return dpp1[x];
        }
        else if(finans=='a'){
            ll e3= probs(x+1, i-1, 'a', symbol1, str);
            ll e4= probs(i+1, y-1, '0', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, 'a', symbol1, str);

            dppa[x]=((e1*e2)%M+(e3*e4)%M+(e3*e2)%M)%M;
            return dppa[x];
        }
        else if(finans=='A'){
            ll e3= probs(x+1, i-1, 'A', symbol1, str);
            ll e4= probs(i+1, y-1, '0', symbol1, str);
            ll e1= probs(x+1, i-1, '0', symbol1, str);
            ll e2= probs(i+1, y-1, 'A', symbol1, str);

            dppA[x]=((e1*e2)%M+(e3*e4)%M+(e3*e2)%M)%M;
            return dppA[x];   
        }
    
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    
    while(t--){

        memset(dppa, 0, sizeof(dppa));
        memset(dppA, 0, sizeof(dppA));
        memset(dpp0, 0, sizeof(dpp0));
        memset(dpp1, 0, sizeof(dpp1));

        string s1;
        cin>>s1;

        stack<ll>stac;
        ll symbol1[s1.length()]={0};

        for(ll itt=0; itt<s1.length(); itt++){

            if(s1[itt]=='(') stac.push(itt);

            if(s1[itt]=='&' || s1[itt]=='|' || s1[itt]=='^'){
                ll t1=stac.top();
                stac.pop();
                symbol1[t1]=itt;
            }

        }

        ll finalans0= probs(0, s1.length()-1, '0', symbol1, s1);
        ll finalans1= probs(0, s1.length()-1, '1', symbol1, s1);
        ll finalansa= probs(0, s1.length()-1, 'a', symbol1, s1);
        ll finalansA= probs(0, s1.length()-1, 'A', symbol1, s1);
        
        cout<<finalans0<<" "<<finalans1<<" "<<finalansa<<" "<<finalansA<<"\n";
        
    }

    return 0;
}

