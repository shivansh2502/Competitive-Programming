#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    priority_queue<long long> Q;
    while(N--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            long long x,y;
            cin>>x>>y;
            long long dist=x*x+y*y;
            if(Q.size()<K)
                Q.push(dist);
            else if(Q.top()>dist)
            {
                Q.pop();
                Q.push(dist);
            }
        }
        else
            cout<<Q.top()<<endl;
    }
}