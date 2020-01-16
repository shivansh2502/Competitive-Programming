#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll test;
    cin>>test;

    while(test--)
    {

        ll  num;
        cin>>num;

        if(num==1)
        {

            cout<<"Hooray"<<"\n";
            cout<<1<<"\n";
            continue;

        }

        if(num%2!=0)
        {

            cout<<"Boo"<<"\n";

        }

        else 
        {

            cout<<"Hooray"<<"\n";
            
            ll count=2;
            ll a[num][num];
            memset(a,-1, sizeof(a));
            a[0][0]=1; a[1][1]=1; a[0][1]=2; a[1][0]=3;

            while(count < num)
            {
                
                for(ll it=0;it<count;it++)
                {

                    for(ll jt=0;jt<count;jt++)
                    {

                        a[count+it][count+jt]=a[it][jt];

                        if(it < jt)
                        {
                            a[it+count][jt]=a[it][jt]+(2*count)+1;
                            a[it][jt+count]=a[it][jt]+(2*count);   
                        }

                        else
                        {
                            a[it+count][jt]=a[it][jt]+(2*count);
                            a[it][jt+count]=a[it][jt]+(2*count)-1;
                        }
                    }
                }
                count*=2;
            }


            for(ll  it=0;it<num;it++){

                for(ll  jt=0;jt<num;jt++){

                    cout<<a[it][jt]<<" ";
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}