#include<bits/stdc++.h>
using namespace std;

#define f(i,n)			for(int i=0;i<n;i++)
#define fs(i,s,n)		for(int i=s;i<n;i++)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e110
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)



 
void sm25official()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int powers[40];
int num=1;

bool func(int s, int e, int x, int y, int count, vector<char> &v){
    if(s==x && e==y) return true;

    if(x>=0 && y>=0) if(s>(10*x) || e>(10*y) || s<(10*x*-1) || e<(10*y*-1)) return false;

    if(x>=0 && y<0) if(s>(10*x) || e>(10*y*-1) || s<(10*x*-1) || e<(10*y)) return false;

    if(x<0 && y>=0) if(s>(10*x*-1) || e>(10*y) || s<(10*x) || e<(10*y*-1)) return false;

    if(x<0 && y<0) if(s>(10*x*-1) || e>(10*y*-1) || s<(10*x) || e<(10*y)) return false;

    if(x>0){
        bool ans1=func(s+powers[count], e, x, y, count+1, v);
        if(ans1==true){
            v.push_back('N');
            return true;
        }
    
        bool ans2=func(s-powers[count], e, x, y, count+1, v);
        if(ans2==true){
            v.push_back('S');
            return true;
        }
    }
    else{
        bool ans2=func(s-powers[count], e, x, y, count+1, v);
        if(ans2==true){
            v.push_back('S');
            return true;
        }
        
        bool ans1=func(s+powers[count], e, x, y, count+1, v);
        if(ans1==true){
            v.push_back('N');
            return true;
        }
    }
    if(y>0){
        bool ans10=func(s, e+powers[count], x, y, count+1, v);
        if(ans10==true){
            v.push_back('E');
            return true;
        }

        bool ans4=func(s, e-powers[count], x, y, count+1, v);
        if(ans4==true){
            v.push_back('W');
            return true;
        }
    }
    else{
        bool ans4=func(s, e-powers[count], x, y, count+1, v);
        if(ans4==true){
            v.push_back('W');
            return true;
        }

        bool ans10=func(s, e+powers[count], x, y, count+1, v);
        if(ans10==true){
            v.push_back('E');
            return true;
        }
    }
    return false;
}

int32_t main(){
    sm25official();
    int q=1;
    for(int i=0;i<40;i++){
        powers[i]=num;
        num*=2;
    }
    w(t){
        cout<<"Case #"<<q<<": "; 
        int x, y;
        cin>>x>>y;
        vector<char> v;
        
        
        bool ans= func(0, 0, y, x, 0, v);
        if(ans){
            for(int i=v.size()-1;i>=0;i--){
                cout<<v[i];
            }
            cout<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
        
        q++;
    }
    
    return 0;
}


