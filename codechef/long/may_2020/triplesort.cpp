#include<iostream>
#include<vector>
#include<unordered_set>
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
#define mod             1000000007
#define MOD             998244353;
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define PI              3.1415926535897932384626

 
 
void shivansh2502(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


class tri{
    public:
        int i1, i2, i3;
        tri(int v1, int v2, int v3){
            i1=v1;
            i2=v2;
            i3=v3;
        }
};

int32_t main(){
    shivansh2502();
    int t;
    cin>>t;
    vector<int>p;
    p.reserve(200005);

    unordered_set<int> se;
    se.max_load_factor(0.25);
    se.reserve(200005);

    vector<tri> v;
    v.reserve(200005);
    while(t--){
        int n, k;
        cin>>n>>k;
        p.clear();
        ++n;
        
        se.clear();
        

        for(int i=1;i<n;i++){
            cin>>p[i]; 
            if(p[i]!=i){
                se.insert(i);
            }
        }
        
        bool flag=false;
        v.clear();
        int siz=0;

        fs(i, 1, n){
            if(p[i]!=i){
                int index1= p[i];
                int val= p[p[i]];
                if(val!=i){
                    p[p[i]]=p[i];
                    se.erase(p[i]);

                    p[i]= p[val];
                    if(p[i]==i) se.erase(i);

                    p[val]=val;
                    se.erase(val);

                    tri trip(val, i, index1);
                    v[siz++]=(trip);
                    if(p[i]!=i) i--;
                }
            }
            
        }
       
        for(int i=1;i<n;i++){
            // cout<<i<<endl;
            if(p[i]!=i){
                int index1= p[i];
                int val= p[p[i]];
                p[p[i]]=p[i];
                se.erase(p[i]);
                // s[index1]=0;
                if(val==i){
                    int index=-1;
                    for(auto& j:se){
                        if(j!=i && j!=index1 && p[j]!=j){
                            index=j;
                            break;
                        }
                    }
                    if(index==-1){
                        flag=true;
                        break;
                    }

                    p[i]=p[index];
                    if(p[i]==i) se.erase(i);
                    p[index]=val;
                    if(p[index]==index) se.erase(index);
                
                    tri trip(index, i, index1);
                    v[siz++]=(trip);
                    // fs(j, i+1, n){
                    //     if(p[j]!=j){
                    //         int index1= p[j];
                    //         int val= p[p[j]];
                    //         if(val!=j){
                    //             p[p[j]]=p[j];
                    //             se.erase(p[j]);

                    //             p[j]= p[val];
                    //             if(p[j]==j) se.erase(j);

                    //             p[val]=val;
                    //             se.erase(val);

                    //             tri trip(val, j, index1);
                    //             v[siz++]=(trip);
                    //         }
                    //         if(p[j]==j) j--;
                    //     }
                        
                    // }
                }
                else{
                    p[i]= p[val];
                    if(p[i]==i) se.erase(i);
                    p[val]=val;
                    if(p[val]==val) se.erase(val);
                    
                    tri trip(val, i, index1);
                    v[siz++]=(trip);
                }
                if(p[i]!=i) i--;
            } 
            
        }

        
        if(!flag){
            cout<<siz<<"\n";
            for(int i=0;i<siz;i++){
                cout<<v[i].i1<<" "<<v[i].i2<<" "<<v[i].i3<<"\n";
            }
        }
        else{
            cout<<-1<<"\n";
        }

    }
    
    return 0;
}


