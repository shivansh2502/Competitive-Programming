#include<bits/stdc++.h>
using namespace std;
#define ll long long

double distance(ll a1,ll b1, ll a2, ll b2){
   return sqrt(pow((a2-a1),2) + pow((b2-b1),2));
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        ll c[m],d[m];
        for(ll i=0;i<m;i++){
            cin>>c[i]>>d[i];
        }
        ll e[k],f[k];
        for(ll i=0;i<k;i++){
            cin>>e[i]>>f[i];
        }
    
        double distae[n]={0};
        for(ll i=0;i<n;i++){
            double dist=DBL_MAX;
            for(ll j=0;j<k;j++){
                if(distance(a[i],b[i],e[j],f[j]) < dist){
                    dist=distance(a[i],b[i],e[j],f[j]);
                }
            }
            distae[i]=dist;
        }
        
        double distce[m]={0};
        for(ll i=0;i<m;i++){
            double dist=DBL_MAX;
            for(ll j=0;j<k;j++){
                if(distance(c[i],d[i],e[j],f[j]) < dist){
                    dist=distance(c[i],d[i],e[j],f[j]);
                }
            }
            distce[i]=dist;
        }

        double finaldista[n]={0};
        for(ll i=0;i<n;i++){
            double dist=DBL_MAX;
            for(ll j=0;j<m;j++){
                if(distance(a[i],b[i],c[j],d[j])+distce[j] < dist){
                    dist=distance(a[i],b[i],c[j],d[j])+distce[j];
                }
            }
            finaldista[i]=dist;
        }

        double finaldistc[m]={0};
        for(ll i=0;i<m;i++){
            double dist=DBL_MAX;
            for(ll j=0;j<n;j++){
                if(distance(c[i],d[i],a[j],b[j])+distae[j] < dist){
                    dist=distance(c[i],d[i],a[j],b[j])+distae[j];
                }
            }
            finaldistc[i]=dist;
        }

        double dis=DBL_MAX;
        for(ll i=0;i<n;i++){
            if(distance(x,y,a[i],b[i])+finaldista[i]<dis){
                dis=distance(x,y,a[i],b[i])+finaldista[i];
            }
        }
        for(ll i=0;i<m;i++){
            if(distance(x,y,c[i],d[i])+finaldistc[i]<dis){
                dis=distance(x,y,c[i],d[i])+finaldistc[i];
            }
        }
        cout<<setprecision(10)<<fixed<<dis<<endl;
    }
    return 0;
}