#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void shivansh2502()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}

int32_t main(){
    shivansh2502();

    int t, b;
    cin>>t>>b;
    while(t--){
        if(b==10){
            int a[b];
            int query=0;
            int number=1;
            int index=0;
            while(index<b && query<=150){
                cout<<number<<endl;
                int k; cin>>k;
                a[index]=k;
                index++;
                number++;
                query++;
            }

            f(i, b){
                cout<<a[i];
            }
            cout<<endl;
            char c;
            cin>>c;
            if(c=='N'){
                break;
            }
        }
    
        if(b==20){
            int oddarr[b];
            int query=0;
            int number=1;
            int index=0;
            // int a[10]={1,1,0,0,0,0,0,1,1,1};
            while(index<b && query<10){
                cout<<number<<endl;
                int k; cin>>k;
                oddarr[number-1]=k;
                // cout<<number-1<<"->"<<oddarr[number-1]<<endl;
                number+=2;
                query++;
                if(query==5) number++; 
            }
            int evenarr[b];
            query=0;
            number=2;
            index=1;
            // int arr[10]={1,0,0,1,1,0,0,0,0,1};
            while(index<=b && query<10){
                cout<<number<<endl;
                int k; cin>>k;
                evenarr[number-1]=k;
                // cout<<number-1<<"->"<<evenarr[number-1]<<endl;
                number+=2;
                query++;
                if(query==5) number--;
            }

            int originalarr[b]={0};
            // int ar[10]={1,0,1,1,1,1,0,0,0,0};
            query=0;
            number=1;
            index=0;

            while(index<b/2 && query<10){
                cout<<number<<endl;
                int k; cin>>k;
                originalarr[index]=k;
                index++;
                number++;
                query++;
            }

            if(originalarr[0]==oddarr[0] &&
                originalarr[2]==oddarr[2] &&
                originalarr[4]==oddarr[4] && 
                originalarr[6]==oddarr[6] &&
                originalarr[8]==oddarr[8] 
            ){
                originalarr[11]=oddarr[11];
                originalarr[13]=oddarr[13];
                originalarr[15]=oddarr[15];
                originalarr[17]=oddarr[17]; 
                originalarr[19]=oddarr[19];
            }
            else if(
                originalarr[0]==oddarr[19] &&
                originalarr[2]==oddarr[17] &&
                originalarr[4]==oddarr[15] && 
                originalarr[6]==oddarr[13] &&
                originalarr[8]==oddarr[11] 
            ){
                originalarr[11]=oddarr[8];
                originalarr[13]=oddarr[6];
                originalarr[15]=oddarr[4];
                originalarr[17]=oddarr[2]; 
                originalarr[19]=oddarr[0];
            }
            else if(
                originalarr[0]!=oddarr[0] &&
                originalarr[2]!=oddarr[2] &&
                originalarr[4]!=oddarr[4] && 
                originalarr[6]!=oddarr[6] &&
                originalarr[8]!=oddarr[8] 
            ){
                originalarr[11]=oddarr[11]^1;
                originalarr[13]=oddarr[13]^1;
                originalarr[15]=oddarr[15]^1;
                originalarr[17]=oddarr[17]^1; 
                originalarr[19]=oddarr[19]^1;
            }
            else if(
                originalarr[0]!=oddarr[19] &&
                originalarr[2]!=oddarr[17] &&
                originalarr[4]!=oddarr[15] && 
                originalarr[6]!=oddarr[13] &&
                originalarr[8]!=oddarr[11] 
            ){
                originalarr[11]=oddarr[8]^1;
                originalarr[13]=oddarr[6]^1;
                originalarr[15]=oddarr[4]^1;
                originalarr[17]=oddarr[2]^1; 
                originalarr[19]=oddarr[0]^1;
            }



            if(originalarr[1]==evenarr[1] &&
                originalarr[3]==evenarr[3] &&
                originalarr[5]==evenarr[5] && 
                originalarr[7]==evenarr[7] &&
                originalarr[9]==evenarr[9] 
            ){
                originalarr[10]=evenarr[10];
                originalarr[12]=evenarr[12];
                originalarr[14]=evenarr[14];
                originalarr[16]=evenarr[16]; 
                originalarr[18]=evenarr[18];
            }
            else if(
                originalarr[1]==evenarr[18] &&
                originalarr[3]==evenarr[16] &&
                originalarr[5]==evenarr[14] && 
                originalarr[7]==evenarr[12] &&
                originalarr[9]==evenarr[10] 
            ){
                originalarr[10]=evenarr[9];
                originalarr[12]=evenarr[7];
                originalarr[14]=evenarr[5];
                originalarr[16]=evenarr[3]; 
                originalarr[18]=evenarr[1];
            }
            else if(
                originalarr[1]!=evenarr[1] &&
                originalarr[3]!=evenarr[3] &&
                originalarr[5]!=evenarr[5] && 
                originalarr[7]!=evenarr[7] &&
                originalarr[9]!=evenarr[9] 
            ){
                originalarr[10]=evenarr[10]^1;
                originalarr[12]^=evenarr[12]^1;
                originalarr[14]^=evenarr[14]^1;
                originalarr[16]^=evenarr[16]^1; 
                originalarr[18]^=evenarr[18]^1;
            }
            else if(
                originalarr[1]!=evenarr[18] &&
                originalarr[3]!=evenarr[16] &&
                originalarr[5]!=evenarr[14] && 
                originalarr[7]!=evenarr[12] &&
                originalarr[9]!=evenarr[10] 
            ){
                originalarr[10]=evenarr[9]^1;
                originalarr[12]=evenarr[7]^1;
                originalarr[14]=evenarr[5]^1;
                originalarr[16]=evenarr[3]^1; 
                originalarr[18]=evenarr[1]^1;
            }

            f(i, b){
                cout<<originalarr[i];
            }
            cout<<endl;
            char c;
            cin>>c;
            if(c=='N'){
                break;
            }
        }
    }

    
    return 0;
}


