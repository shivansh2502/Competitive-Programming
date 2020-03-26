#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;

int main(){

    ll1 test;
    cin>>test;

    while(test--){

        ll1 num, mum, key, que;
         
        cin>>num>>mum>>key>>que;

        ll1 lef[que], rig[que];
         
        for(ll1 i=0;i<que;i++){

            cin>>lef[i]>>rig[i];

        }

        ll1 ans1[que];

        int maxh=-2;

        for(ll1 i=0;i<que;i++){

            ll1 hu=-2;

            queue<ll1> queu;

            queu.push(mum/2);

            while( (hu==-2 || hu==-1) && key--){

                ll1 yt=queu.front();

                cout<<1<<" "<<lef[i]<<" "<<rig[i]<<" "<<yt<<endl;
                
                queu.pop();

                queu.push(yt- yt/2);

                queu.push(yt+ yt/2);
        

                cin>>hu;

                if(hu>maxh){
                    maxh=hu;
                }
            }

            if(hu==-1 || hu==-2){
                ans1[i]= maxh;
            }

            else{
                ans1[i]=hu;
            }

        }

        cout<<2<<" ";

        for(ll1 i=0;i<que;i++){

            cout<<ans1[i]<<" ";

        }

        cout<<endl;


        ll1 finalv;

        cin>>finalv;

        if(finalv==-1){

            exit(0);

        }

    }
    return 0;

}
