#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[4][4];
        memset(a, 0, sizeof(a));
        for(ll i=0;i<n;i++){
            char c;
            int x;
            cin>>c>>x;
            if(c=='A'){
                int s=0;
                if(x==12) a[0][0]++;
                else if( x== 3) a[0][1]++;
                else if(x==6) a[0][2]++;
                else if(x==9) a[0][3]++;
            }
            else if(c=='B'){
                if(x==12) a[1][0]++;
                else if( x== 3) a[1][1]++;
                else if(x==6) a[1][2]++;
                else if(x==9) a[1][3]++;
            }
            else if(c=='C'){
                if(x==12) a[2][0]++;
                else if( x== 3) a[2][1]++;
                else if(x==6) a[2][2]++;
                else if(x==9) a[2][3]++;
            }
            else if(c=='D'){
                if(x==12) a[3][0]++;
                else if( x== 3) a[3][1]++;
                else if(x==6) a[3][2]++;
                else if(x==9) a[3][3]++;
            }
        }
        // for(int i=0;i<4;i++){
        //     for(int j=0;j<4;j++){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int maxprofit=0;
        set<int> time;
        set<int> movie;
        for(int i=0;i<4;i++){
            int currentProfit=0;
            for(int j=0;j<4;j++){
                time.clear();
                movie.clear();
                if(a[i][j]!=0) currentProfit+=a[i][j]*100;
                else currentProfit-=100;
                time.insert(i);
                movie.insert(j);
                for(int k=0;k<4;i++){
                    for(int l=0;l<4;l++){
                        if(time.find(k)!= time.end() || movie.find(l)!= movie.end()){
                            continue;
                        }
                        else{
                            if(a[k][l]!=0) currentProfit+=a[k][l]*75;
                            else currentProfit-=100;
                            time.insert(k);
                            movie.insert(l);
                        }  
                        for(int m=0;m<4;m++){
                            for(int n=0;n<4;n++){
                                if(time.find(m)!= time.end() || movie.find(n)!= movie.end()){
                                    continue;
                                }
                                else{
                                    if(a[m][n]!=0) currentProfit+=a[m][n]*50;
                                    else currentProfit-=100;
                                    time.insert(m);
                                    movie.insert(n);
                                }  
                                for(int o=0;o<4;o++){
                                    for(int p=0;p<4;p++){
                                        if(time.find(o)!= time.end() || movie.find(p)!= movie.end()){
                                            continue;
                                        }
                                        else{
                                            if(a[o][p]!=0) currentProfit+=a[o][p]*25;
                                            else currentProfit-=100;
                                            time.insert(o);
                                            movie.insert(p);
                                            maxprofit= max(currentProfit, maxprofit);
                                        }  
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxprofit<<endl;
    }
    
    return 0;
}
